#ifndef CODECLOCKWINDOW_H
#define CODECLOCKWINDOW_H

#include <QMainWindow>

namespace Ui {
class CodeClockWindow;
}

class CodeClockWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit CodeClockWindow(QWidget *parent = 0);

    ~CodeClockWindow();

private:

    Ui::CodeClockWindow *ui;
};

#endif // CODECLOCKWINDOW_H
