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

    explicit CodeClockWindow(QWidget* _parent = nullptr);

    ~CodeClockWindow();

private:

    Ui::CodeClockWindow *ui;
};

#endif // CODECLOCKWINDOW_H
