#include "querywindow.h"
#include "ui_querywindow.h"
#include <QDebug>
#include <QSqlError>

QueryWindow::QueryWindow(QString title, QSqlQuery query, QStringList headers, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QueryWindow)
{
    ui->setupUi(this);
    setWindowTitle(title);
    ui->tableView->setModel(&model);
    model.setQuery(query);
    qDebug() << model.lastError();
    int section = 0;
    foreach (QString hTitle, headers) {
        model.setHeaderData(section, Qt::Horizontal,hTitle);
        ++section;
    }
}

QueryWindow::~QueryWindow()
{
    delete ui;
}
