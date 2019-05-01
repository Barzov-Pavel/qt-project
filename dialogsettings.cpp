#include "dialogsettings.h"
#include "ui_dialogsettings.h"
#include <QSettings>
#include <QDialogButtonBox>
#include <QPushButton>
#include "skeys.h"
#include <QSqlDatabase>

DialogSettings::DialogSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSettings)
{
    ui->setupUi(this);

    ui->ComboBox->addItems(QSqlDatabase::drivers());
    on_ComboBox_currentIndexChanged(ui->ComboBox->currentIndex());
    loadSettings();
    setOkEnabled();
}

DialogSettings::~DialogSettings()
{
    delete ui;
}


void DialogSettings::slot1()
{
    QSettings settings;
    settings.setValue(SKEY_HOST, ui->LineEdit->text());
    settings.setValue(SKEY_DRIVER,ui->ComboBox->itemText(ui->ComboBox->currentIndex()));
    settings.setValue(SKEY_DBNAME, ui->LineEdit_2->text());
    settings.setValue(SKEY_USERNAME, ui->LineEdit_3->text());
    settings.setValue(SKEY_PASSWD, ui->LineEdit_4->text());

}

void DialogSettings::loadSettings()
{
    QSettings settings;
    QString driverName = settings.value(SKEY_DRIVER).toString();
    int idx = ui->ComboBox->findText(driverName);
    ui->ComboBox->setCurrentIndex(idx);
    ui->LineEdit->setText(settings.value(SKEY_HOST).toString());
    ui->LineEdit_2->setText(settings.value(SKEY_DBNAME).toString());
    ui->LineEdit_3->setText(settings.value(SKEY_USERNAME).toString());
    ui->LineEdit_4->setText(settings.value(SKEY_PASSWD).toString());
}

void DialogSettings::setOkEnabled()
{
    if (ui->ComboBox->currentIndex()!=-1) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    } else {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

void DialogSettings::on_ComboBox_currentIndexChanged(int index)
{
    setOkEnabled();
}
