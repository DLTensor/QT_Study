#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *ev);  // 键盘按下事件
    void timerEvent(QTimerEvent *ev);
    void closeEvent(QCloseEvent *ev);

    // bool event(QEvent *ev);
    bool eventFilter(QObject *obj, QEvent *ev);

private:
    Ui::MainWindow *ui;
    int timerID;
    int timerID_2;
};

#endif // MAINWINDOW_H
