#ifndef LINEARVIEW_H
#define LINEARVIEW_H

#include <QWidget>
#include <QQueue>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSharedPointer>
#include "abstractview.h"
#include "../process/rectangularprocessview.h"

class LinearView : public AbstractView
{
    Q_OBJECT
public:

    explicit LinearView(QQueue<QSharedPointer<AbstractTrackableProcess>> _data,
                        QSharedPointer<AbstractProcessView> _dataView,
                        QWidget* _parent = nullptr);

    explicit LinearView(QWidget* _parent = nullptr);

    virtual QQueue<QSharedPointer<AbstractTrackableProcess> > data() const Q_DECL_OVERRIDE;

    virtual QSharedPointer<AbstractProcessView> dataView() const Q_DECL_OVERRIDE;

signals:

    void dataChanged(QQueue<QSharedPointer<AbstractTrackableProcess>>);

    void dataViewChanged(QSharedPointer<AbstractProcessView>);

public slots:

    virtual void setData(const QQueue<QSharedPointer<AbstractTrackableProcess>>& _data) Q_DECL_OVERRIDE;

    virtual void setDataView(QSharedPointer<AbstractProcessView> _dataView) Q_DECL_OVERRIDE;

protected:

    void applyDataView();

private:

    QQueue<QSharedPointer<AbstractTrackableProcess>> mData;

    QSharedPointer<AbstractProcessView> mDataView;

    QSharedPointer<QVBoxLayout> mLayout;

    QSharedPointer<QHBoxLayout> mProcessBar;

    QSharedPointer<QHBoxLayout> mDocumentBar;

    QQueue<QSharedPointer<AbstractProcessView>> mDataViews;

};

#endif // LINEARVIEW_H
