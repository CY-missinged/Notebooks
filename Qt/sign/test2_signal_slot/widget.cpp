#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(btnSlot()));
    //connect(ui->pushButton, &QPushButton::clicked, this, &Widget::btnSlot);
    // connect(ui->pushButton, &QPushButton::clicked, [=]() {
    //     // 具体代码
    //     QMessageBox::information(this, "tile", "clicked");
    // });

}

Widget::~Widget() { delete ui; }

void Widget::btnSlot() {}
// QMessageBox::information(this, "tile", "clicked");

//void Widget::myslot1() { QMessageBox::information(this, "tile", "clicked"); }

void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this, "tile", "on_pushButton_clicked");
}

