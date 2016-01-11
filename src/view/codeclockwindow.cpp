#include "codeclockwindow.h"
#include "ui_codeclockwindow.h"
#include "diagrams/abstractview.h"

CodeClockWindow::CodeClockWindow(QSharedPointer<AbstractView> _view, QWidget* _parent) :
    QMainWindow(_parent),
    ui(new Ui::CodeClockWindow),
    mView(_view)
{
    ui->setupUi(this);
    mView->setParent(ui->wgtDiagramm);
}

CodeClockWindow::~CodeClockWindow()
{
    delete ui;
}
