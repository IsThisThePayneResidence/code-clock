#ifndef ABSTRACTPROCESSVIEW_H
#define ABSTRACTPROCESSVIEW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class AbstractTrackableProcess;

class AbstractProcessView : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QSharedPointer<AbstractTrackableProcess> process READ process WRITE setProcess NOTIFY processChanged)
public:

    virtual QSharedPointer<AbstractTrackableProcess> process() const = 0;

signals:

    void processChanged(QSharedPointer<AbstractTrackableProcess>);

public slots:

    virtual void setProcess(QSharedPointer<AbstractTrackableProcess> _process) = 0;

    virtual QSharedPointer<AbstractProcessView> clone(QSharedPointer<AbstractTrackableProcess> _process, QWidget* _parent = nullptr) = 0;

protected:

    virtual void paintEvent(QPaintEvent* _event) Q_DECL_OVERRIDE { QWidget::paintEvent(_event); }

private:

};

#endif // ABSTRACTPROCESSVIEW_H
