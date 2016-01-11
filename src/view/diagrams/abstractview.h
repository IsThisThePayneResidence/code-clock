#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QObject>
#include <QWidget>

class AbstractTrackableProcess;
class AbstractProcessView;

class AbstractView : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QQueue<QSharedPointer<AbstractTrackableProcess>> data READ data WRITE setData NOTIFY dataChanged)
    Q_PROPERTY(QSharedPointer<AbstractProcessView> dataView READ dataView WRITE setDataView NOTIFY dataViewChanged)
public:

    virtual QQueue<QSharedPointer<AbstractTrackableProcess>> data() const = 0;

    virtual QSharedPointer<AbstractProcessView> dataView() const = 0;

signals:

    void dataChanged(const QQueue<QSharedPointer<AbstractTrackableProcess>>&);

    void dataViewChanged(QSharedPointer<AbstractProcessView>);

public slots:

    virtual void setData(const QQueue<QSharedPointer<AbstractTrackableProcess>>& _data) = 0;

    virtual void setDataView(QSharedPointer<AbstractProcessView> _dataView) = 0;

protected:

    //virtual void paintEvent(QPaintEvent* _event) = 0;

private:

};

#endif // ABSTRACTVIEW_H
