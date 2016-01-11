#ifndef RECTANGULARPROCESSVIEW_H
#define RECTANGULARPROCESSVIEW_H

#include <QObject>
#include <QWidget>
#include "abstractprocessview.h"

class RectangularProcessView : public AbstractProcessView
{
    Q_OBJECT
public:

    RectangularProcessView(QSharedPointer<AbstractTrackableProcess> _process, QWidget* _parent = nullptr);

    virtual QSharedPointer<AbstractTrackableProcess> process() const Q_DECL_OVERRIDE;

protected:

    virtual void paintEvent(QPaintEvent* _event) Q_DECL_OVERRIDE;

public slots:

    virtual void setProcess(QSharedPointer<AbstractTrackableProcess> _process) Q_DECL_OVERRIDE;

    virtual QSharedPointer<AbstractProcessView> clone(QSharedPointer<AbstractTrackableProcess> _process, QWidget* _parent = nullptr) Q_DECL_OVERRIDE;

protected:

private:

    QSharedPointer<AbstractTrackableProcess> mProcess;
};

#endif // RECTANGULARPROCESSVIEW_H
