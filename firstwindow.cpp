#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "tablewindow.h"
#include <QSettings>
#include <QMessageBox>
#include "dialogsettings.h"
#include <QMdiSubWindow>
#include <QSqlRelation>
#include "querywindow.h"
#include "input2nums.h"

FirstWindow::FirstWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}


void FirstWindow::on_action_4_triggered()
{
    DialogSettings dialog;
    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "Предупреждение", "Изменения настроек вступят в силу только после перезапуска программы");
    }
}




void FirstWindow::on_TableX_triggered()
{
    QStringList headerTitles;
    headerTitles.append("number");
    headerTitles.append("imformation");
    QMap<int, QSqlRelation> relations;
    relations.insert(2, QSqlRelation("Y", "id", "title"));
    TableWindow *window = new TableWindow("dict", headerTitles, relations, this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    QMdiSubWindow *sw = ui->mdiArea->addSubWindow(window);
    sw->setAttribute(Qt::WA_DeleteOnClose);
    sw->show();
}

void FirstWindow::on_mdiArea_subWindowActivated(QMdiSubWindow *arg1)
{

}

void FirstWindow::on_actionQuery1_triggered()
{
    QSqlQuery query;
        query.prepare("SELECT * FROM dict");
        query.exec();
        QStringList headers;
            headers.append("count");
            headers.append("information");
        QueryWindow *window = new QueryWindow("Query 1", query, headers);
        window->setAttribute(Qt::WA_DeleteOnClose);
        QMdiSubWindow *sw = ui->mdiArea->addSubWindow(window);
        sw->setAttribute(Qt::WA_DeleteOnClose);
        sw->show();
}

void FirstWindow::on_actionQyery2_triggered()
{
    QSqlQuery query;
        query.prepare("SELECT v FROM dict ORDER BY v");
        query.exec();
        QStringList headers;
            headers.append("information");
        QueryWindow *window = new QueryWindow("Query 1", query, headers);
        window->setAttribute(Qt::WA_DeleteOnClose);
        QMdiSubWindow *sw = ui->mdiArea->addSubWindow(window);
        sw->setAttribute(Qt::WA_DeleteOnClose);
        sw->show();
}

void FirstWindow::on_actionQuery2_triggered()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM dict WHERE k = :minarea");
    Input2Nums paramDialog;
    if (paramDialog.exec() != QDialog::Accepted)
        return;
    query.bindValue(":minarea", paramDialog.getNum1());
    query.exec();
    QStringList headers;
    headers.append("count");
    headers.append("information");
    QueryWindow *window = new QueryWindow("Query 1", query, headers);
    window->setAttribute(Qt::WA_DeleteOnClose);
    QMdiSubWindow *sw = ui->mdiArea->addSubWindow(window);
    sw->setAttribute(Qt::WA_DeleteOnClose);
    sw->show();
}
