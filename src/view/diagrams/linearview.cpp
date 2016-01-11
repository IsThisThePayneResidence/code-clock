#include <QQueue>
#include <QSharedPointer>
#include <QDebug>
#include "linearview.h"
#include "../../model/abstracttrackableprocess.h"

LinearView::LinearView(QQueue<QSharedPointer<AbstractTrackableProcess> > _data, QSharedPointer<AbstractProcessView> _dataView, QWidget* _parent)
    : mData(_data),
      mDataView(_dataView),
      mLayout(new QVBoxLayout(this)),
      mProcessBar(new QHBoxLayout()),
      mDocumentBar(new QHBoxLayout())
{
    setParent(_parent);
    mProcessBar->setSpacing(0);
    applyDataView();
    mLayout->addLayout(mProcessBar.data());
    mLayout->addLayout(mDocumentBar.data());
    setLayout(mLayout.data());
}

LinearView::LinearView(QWidget* _parent)
    : mData(QQueue<QSharedPointer<AbstractTrackableProcess>>()),
      mDataView(QSharedPointer<AbstractProcessView>(new RectangularProcessView(QSharedPointer<AbstractTrackableProcess>()))),
      mLayout(new QVBoxLayout(this)),
      mProcessBar(new QHBoxLayout()),
      mDocumentBar(new QHBoxLayout())
{
    setParent(_parent);
    mProcessBar->setSpacing(0);
    applyDataView();
    mLayout->addLayout(mProcessBar.data());
    mLayout->addLayout(mDocumentBar.data());
    setLayout(mLayout.data());
}

void LinearView::applyDataView()
{
    qDebug() << Q_FUNC_INFO;
    for(auto i = mDataViews.begin(); i != mDataViews.end(); ++i)
    {
        mProcessBar->removeWidget((*i).data());
    }
    mDataViews.clear();
    for(auto i = mData.cbegin(); i != mData.cend(); ++i)
        mDataViews.push_back(mDataView->clone((*i), this));
    for(auto i = mDataViews.begin(); i != mDataViews.end(); ++i)
    {
        mProcessBar->addWidget((*i).data());
    }
}

QQueue<QSharedPointer<AbstractTrackableProcess> > LinearView::data() const
{
    return mData;
}

QSharedPointer<AbstractProcessView> LinearView::dataView() const
{
    return mDataView;
}

void LinearView::setData(const QQueue<QSharedPointer<AbstractTrackableProcess>>& _data)
{
    mData = _data;
    applyDataView();
    emit dataChanged(mData);
}

void LinearView::setDataView(QSharedPointer<AbstractProcessView> _dataView)
{
    mDataView = _dataView;
    applyDataView();
    emit dataViewChanged(mDataView);
}
