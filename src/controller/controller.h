#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QSharedPointer>
#include "abstractcontroller.h"

class AbstractModel;
class AbstractView;

class Controller : public AbstractController
{
    Q_OBJECT
public:
    explicit Controller(QSharedPointer<AbstractModel> _model, QSharedPointer<AbstractView> _view, QObject* _parent = nullptr);

signals:

public slots:

    virtual void connectSignalsAndSlots() Q_DECL_OVERRIDE;

protected:

private:

    QSharedPointer<AbstractModel> mModel;

    QSharedPointer<AbstractView> mView;
};

#endif // CONTROLLER_H
