#include <QDebug>
#include "controller.h"
#include "../model/model.h"
#include "../view/diagrams/abstractview.h"

Controller::Controller(QSharedPointer<AbstractModel> _model, QSharedPointer<AbstractView> _view, QObject* _parent)
    : mModel(_model),
      mView(_view)
{
    setParent(_parent);
    connectSignalsAndSlots();
    //mView->show();
}

void Controller::connectSignalsAndSlots()
{
    qDebug() << Q_FUNC_INFO;
    connect(mModel.data(), SIGNAL(dataChanged(QQueue<QSharedPointer<AbstractTrackableProcess> >)), mView.data(), SLOT(setData(QQueue<QSharedPointer<AbstractTrackableProcess> >)));
}
