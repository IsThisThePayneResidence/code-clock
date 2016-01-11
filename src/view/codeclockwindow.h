#ifndef CODECLOCKWINDOW_H
#define CODECLOCKWINDOW_H

#include <QMainWindow>

namespace Ui {
class CodeClockWindow;
}

class AbstractView;

class CodeClockWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit CodeClockWindow(QSharedPointer<AbstractView> _view, QWidget* _parent = nullptr);

    ~CodeClockWindow();

private:

    Ui::CodeClockWindow *ui;

    QSharedPointer<AbstractView> mView;
};

#endif // CODECLOCKWINDOW_H
