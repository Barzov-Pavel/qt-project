#include "firstwindow.h"
#include "dialogsettings.h"
#include <QApplication>
#include <QTextCodec>
#include <QSqlDatabase>
#include "skeys.h"
#include <QSettings>
#include <QMessageBox>
#include <QSqlError>
#include <QTranslator>  // для русификации кнопок
#include <QLibraryInfo>

bool tryConnect()
{
    QSettings settings;
    QSqlDatabase db = QSqlDatabase::addDatabase(settings.value(SKEY_DRIVER).toString());
    db.setHostName(settings.value(SKEY_HOST).toString());
    db.setDatabaseName(settings.value(SKEY_DBNAME).toString());
    db.setUserName(settings.value(SKEY_USERNAME).toString());
    db.setPassword(settings.value(SKEY_PASSWD).toString());
    if (!db.open()) {
        QMessageBox::warning(0, "Подключение к БД ", db.lastError().text());
        return false;
    }
    return true;
}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setApplicationName("dreamteam");
    a.setOrganizationName("VSU");
    a.setOrganizationDomain("vsu.by");
    QTranslator qtTranslator;  // для русификации кнопок
    qtTranslator.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath)); // для русификации кнопок
    a.installTranslator(&qtTranslator); // для русификации кнопок

    while (!tryConnect()) {
        DialogSettings dialog;
        if (dialog.exec() == QDialog::Rejected)
            return 0;
    }

    FirstWindow w;
    w.show();

    return a.exec();
}
