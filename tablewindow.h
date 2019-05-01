#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QMap>

namespace Ui {
class TableWindow;
}

class TableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableWindow(QString tableName, QStringList headerTitles, QMap<int, QSqlRelation> relations, QWidget *parent = 0);
    ~TableWindow();

private slots:
    void on_actionAddRow_triggered();

    void on_actionRemoveRow_triggered();

private:
    Ui::TableWindow *ui;
    QSqlRelationalTableModel model;
};

#endif // TABLEWINDOW_H
