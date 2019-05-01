#ifndef INPUT2NUMS_H
#define INPUT2NUMS_H

#include <QDialog>

namespace Ui {
class Input2Nums;
}

class Input2Nums : public QDialog
{
    Q_OBJECT

public:
    explicit Input2Nums(QWidget *parent = 0);
    ~Input2Nums();
    int getNum1();

private slots:
    void on_num1Label_linkActivated(const QString &link);

private:
    Ui::Input2Nums *ui;
};

#endif // INPUT2NUMS_H
