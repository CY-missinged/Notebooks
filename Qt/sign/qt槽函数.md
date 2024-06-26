# 槽函数四种写法

## 一、Qt4写法

`connect(ui->pushButton, SIGNAL(clicked), this, SLOT(myFun()));`

写错名称不会报错，但是信号发出后无反应（对应槽函数不执行）。

一个实例，点击按钮会弹窗。

```C++
#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(btnSlot()));
}

Widget::~Widget() { delete ui; }

void Widget::btnSlot() { QMessageBox::information(this, "tile", "clicked"); }

```

## 二、Qt5写法

`connect(ui->btnOpen, &QPushButton::clicked, this, &Widget::open);`

信号（clicked）名字，槽函数名称（open）写错，编译会报错。

```C++
#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(btnSlot()));
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::btnSlot);
}

Widget::~Widget() { delete ui; }

void Widget::btnSlot() { QMessageBox::information(this, "tile", "clicked"); }

```

## 三、lambda表达式写法

`connect(ui->btnOpen, &QPushButton::clicked,[=](){`

`//具体代码`

`});`

slot代码较少时使用

```C++
#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(btnSlot()));
    //connect(ui->pushButton, &QPushButton::clicked, this, &Widget::btnSlot);
    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        // 具体代码
        QMessageBox::information(this, "tile", "clicked");
    });
}

Widget::~Widget() { delete ui; }

void Widget::btnSlot() {}
    //QMessageBox::information(this, "tile", "clicked");

```

## 四、牵线方法（不常用）

1.点击编辑信号/槽（F4）（图1），进入编辑模式（图2）。

- 1

![这是一张示例图片](qt槽函数.assets/image-20240413222326036.png)

- 2

![这是一张示例图片](qt槽函数.assets/image-20240413214308930.png)

2.点击按钮拖动，会出现图3所示界面，再Widget选框中加入槽或信号。

- 3

![这是一张示例图片](qt槽函数.assets/image-2024-04-13-214216.png)

3.选定pushButton的一个信号与之联系（图4），结果如图5。

- 4

![这是一张示例图片](qt槽函数.assets/image-2024-04-13-214641.png)

5

![这是一张示例图片](qt槽函数.assets/image-2024-04-13-214706.png)

```C++
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

void Widget::myslot1() { QMessageBox::information(this, "tile", "clicked"); }
```

## 五、on_name_clicked形式（建议使用）

可以自己定义，也可以软件生成。

1.右键点击控件，点击转到槽（图6）。

- 6

![这是一张示例图片](qt槽函数.assets/image-2024-04-13-215323.png)

2.选择对应的信号（图7），会自动生成槽函数。

- 7

![这是一张示例图片](qt槽函数.assets/image-2024-04-13-215421.png)

```C++
void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this, "tile", "on_pushButton_clicked");
}

```
