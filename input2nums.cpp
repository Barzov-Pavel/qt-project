#include "input2nums.h"
#include "ui_input2nums.h"

Input2Nums::Input2Nums(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Input2Nums)
{
    ui->setupUi(this);
}

Input2Nums::~Input2Nums()
{
    delete ui;
}

int Input2Nums::getNum1()
{
    return ui->num1SpinBox->value();
}




