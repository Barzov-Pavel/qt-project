#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QDialog>

namespace Ui {
class DialogSettings;
}

class DialogSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSettings(QWidget *parent = 0);
    ~DialogSettings();

public slots:
    void slot1();
    void loadSettings();

private slots:
    void on_ComboBox_currentIndexChanged(int index);

private:
    Ui::DialogSettings *ui;
    void setOkEnabled();
};

#endif // DIALOGSETTINGS_H
