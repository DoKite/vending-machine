#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
        setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}


void Widget::on_rstButton_clicked()
{
    int obaekWon = 0, baekWon = 0, osipWon = 0, sipWon = 0;

    obaekWon = money / 500, money = money % 500;
    baekWon = money / 100, money = money % 100;
    osipWon = money / 50, money = money % 50;
    sipWon = money / 10, money = money % 10;


    QMessageBox::information(0, "Reset", QString("500won : %1 \n100won : %2 \n50won : %3 \n10won : %4 \n").arg(obaekWon). arg(baekWon). arg(osipWon). arg(sipWon));
}

