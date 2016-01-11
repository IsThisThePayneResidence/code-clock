#include "codeclockwindow.h"
#include "ui_codeclockwindow.h"

CodeClockWindow::CodeClockWindow(QWidget* _parent) :
    QMainWindow(_parent),
    ui(new Ui::CodeClockWindow)
{
    ui->setupUi(this);
}

CodeClockWindow::~CodeClockWindow()
{
    delete ui;
}
