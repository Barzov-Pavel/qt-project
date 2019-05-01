#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>

namespace Ui {
class FirstWindow;
}

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = 0);
    ~FirstWindow();


private slots:
    void on_action_4_triggered();

    void on_mdiArea_subWindowActivated(QMdiSubWindow *arg1);

 //   void on_action_1_triggered();

    void on_TableX_triggered();

    void on_actionQuery1_triggered();

    void on_actionQyery2_triggered();

    void on_actionQuery2_triggered();

private:
    Ui::FirstWindow *ui;
};

#endif // FIRSTWINDOW_H
