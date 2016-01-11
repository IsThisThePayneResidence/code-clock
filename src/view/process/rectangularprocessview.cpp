#include <QPainter>
#include <QDebug>
#include "rectangularprocessview.h"
#include "../../model/abstracttrackableprocess.h"

RectangularProcessView::RectangularProcessView(QSharedPointer<AbstractTrackableProcess> _process, QWidget* _parent)
    : mProcess(_process)
{
    setParent(_parent);
}

void RectangularProcessView::paintEvent(QPaintEvent* _event)
{
    //qDebug() << Q_FUNC_INFO;
    QScopedPointer<QPainter> painter(new QPainter(this));
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::black);
    //painter->drawRect(QRect(0, 0, mProcess->duration() * 0.0005f, ((QWidget*)parent())->height()));
    painter->fillRect(QRect(0, 0, mProcess->duration() * 0.0005f, ((QWidget*)parent())->height()), mProcess->color());
    this->setMaximumWidth(mProcess->duration() * 0.0005f);

    AbstractProcessView::paintEvent(_event);
}

QSharedPointer<AbstractTrackableProcess> RectangularProcessView::process() const
{
    return mProcess;
}

void RectangularProcessView::setProcess(QSharedPointer<AbstractTrackableProcess> _process)
{
    qDebug() << Q_FUNC_INFO;
    mProcess = _process;
    emit processChanged(mProcess);
}

QSharedPointer<AbstractProcessView> RectangularProcessView::clone(QSharedPointer<AbstractTrackableProcess> _process, QWidget *_parent)
{
    return QSharedPointer<AbstractProcessView>(new RectangularProcessView(_process, _parent));
}
