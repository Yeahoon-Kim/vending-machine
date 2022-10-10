#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff) {
    this->money += diff;
    ui->lcdNumber->display(money);

    // Check money and enable/disable
    checkCoffee();
    checkTea();
    checkMilk();
}

void Widget::checkCoffee() {
    if(this->money >= 100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(false);
}

void Widget::checkTea() {
    if(this->money >= 150) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);
}

void Widget::checkMilk() {
    if(this->money >= 200) ui->pbMilk->setEnabled(true);
    else ui->pbMilk->setEnabled(false);
}

void Widget::on_pb500_clicked() {
    changeMoney(500);
}

void Widget::on_pb100_clicked() {
    changeMoney(100);
}

void Widget::on_pb50_clicked() {
    changeMoney(50);
}

void Widget::on_pb10_clicked() {
    changeMoney(10);
}

void Widget::on_pbCoffee_clicked() {
    changeMoney(-100);
}

void Widget::on_pbTea_clicked() {
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked() {
    changeMoney(-200);
}

void Widget::on_pbReset_clicked() {
    QMessageBox msg;

    int num500{0}, num100{0}, num50{0}, num10{0};
    QString leftCoin;

    leftCoin = "Left money: " + QString::number(this->money) + ",\n";

    while(this->money >= 500) num500++, this->money -= 500;
    while(this->money >= 100) num100++, this->money -= 100;
    while(this->money >= 50) num50++, this->money -= 50;
    while(this->money >= 10) num10++, this->money -= 10;

    leftCoin += "* 500: " + QString::number(num500) + ",\n" +
                "* 100: " + QString::number(num100) + ",\n" +
                "*  50: " + QString::number(num50) + ",\n" +
                "*  10: " + QString::number(num10);

    changeMoney(-this->money);

    msg.information(this, "Reset", leftCoin);


}

