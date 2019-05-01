#ifndef QUERYWINDOW_H
#define QUERYWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class QueryWindow;
}

class QueryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QueryWindow(QString title, QSqlQuery query, QStringList headers, QWidget *parent = 0);
    ~QueryWindow();

private:
    Ui::QueryWindow *ui;
    QSqlQueryModel model;
};

#endif // QUERYWINDOW_H
