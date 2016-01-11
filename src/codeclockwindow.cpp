#include "codeclockwindow.h"
#include "ui_codeclockwindow.h"

CodeClockWindow::CodeClockWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CodeClockWindow)
{
    ui->setupUi(this);
}

CodeClockWindow::~CodeClockWindow()
{
    delete ui;
}
