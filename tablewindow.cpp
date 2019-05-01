#include "tablewindow.h"
#include "ui_tablewindow.h"
#include <QModelIndex>
#include <QSqlRelation>
#include <algorithm>
#include <QDebug>
#include <QSqlError>

class HeaderTitleSetter {
    int idx;
    QSqlRelationalTableModel &model;
public:
    HeaderTitleSetter(QSqlRelationalTableModel &_model) : idx(0), model(_model) {}
    void operator() (QString name) {
        model.setHeaderData(idx++, Qt::Horizontal, name);
    }
};

TableWindow::TableWindow(QString tableName, QStringList headerTitles, QMap<int, QSqlRelation> relations, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);
    setWindowTitle(QString("Таблица %1").arg(tableName));
    model.setTable(tableName);
    std::for_each(headerTitles.begin(), headerTitles.end(), HeaderTitleSetter(model));
    for (QMap<int, QSqlRelation>::const_iterator r = relations.cbegin(); r != relations.cend(); ++r) {
        model.setRelation(r.key(), r.value());
    }
    model.select();
    ui->tableView->setModel(&model);
}

TableWindow::~TableWindow()
{
    delete ui;
}

void TableWindow::on_actionAddRow_triggered()
{
    model.insertRow(model.rowCount());
}

void TableWindow::on_actionRemoveRow_triggered()
{
    model.removeRow(ui->tableView->currentIndex().row());
}



