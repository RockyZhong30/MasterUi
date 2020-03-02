#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFontDatabase>
#include <QButtonGroup>
#include <QLayout>
#include <QDebug>

#include "../common/commontoool.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int fontId = QFontDatabase::addApplicationFont(":/res/image/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont = QFont(fontName, 30);

    QPalette pe;
    pe.setColor(QPalette::WindowText,QColor(255, 182, 193));
    ui->label_icon->setPalette(pe);
    ui->label_icon->setFont(iconFont);
    ui->label_icon->setText(QChar(0xf1aa));

    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->pushButton, 0);
    group->addButton(ui->pushButton_1, 1);
    group->addButton(ui->pushButton_2, 2);
    group->addButton(ui->pushButton_3, 3);
    group->addButton(ui->pushButton_4, 4);
    group->addButton(ui->pushButton_5, 5);
    group->addButton(ui->pushButton_6, 6);
    group->addButton(ui->pushButton_7, 7);
    group->addButton(ui->pushButton_8, 8);
    group->addButton(ui->pushButton_9, 9);
    group->addButton(ui->pushButton_10, 10);
    group->addButton(ui->pushButton_11, 11);
    group->addButton(ui->pushButton_12, 12);
    group->addButton(ui->pushButton_13, 13);
    group->addButton(ui->pushButton_14, 14);
    group->addButton(ui->pushButton_15, 15);
    group->addButton(ui->pushButton_16, 16);
    group->addButton(ui->pushButton_17, 17);
    group->addButton(ui->pushButton_18, 18);
    group->addButton(ui->pushButton_19, 19);
    group->addButton(ui->pushButton_20, 20);
    group->addButton(ui->pushButton_21, 21);
    group->addButton(ui->pushButton_22, 22);
    group->addButton(ui->pushButton_23, 23);
    group->addButton(ui->pushButton_24, 24);
    group->addButton(ui->pushButton_25, 25);
    group->addButton(ui->pushButton_26, 26);
    group->addButton(ui->pushButton_27, 27);
    group->addButton(ui->pushButton_28, 28);
    group->addButton(ui->pushButton_29, 29);
    group->addButton(ui->pushButton_30, 30);
    group->addButton(ui->pushButton_31, 31);
    group->addButton(ui->pushButton_32, 32);
    group->addButton(ui->pushButton_33, 33);
    group->addButton(ui->pushButton_34, 34);
    group->addButton(ui->pushButton_35, 35);
    group->addButton(ui->pushButton_36, 36);
    group->addButton(ui->pushButton_37, 37);
    group->addButton(ui->pushButton_38, 38);
    group->addButton(ui->pushButton_39, 39);

    connect(group, SIGNAL(buttonClicked(int)), SLOT(changed(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPixmap MainWindow::getPixmap(const QColor &color, const QChar &str, quint32 size,
                              quint32 pixWidth, quint32 pixHeight, int flags)
{
    QPixmap pix(pixWidth, pixHeight);
    pix.fill(Qt::transparent);

    QPainter painter;
    painter.begin(&pix);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.setPen(color);

    iconFont.setPixelSize(size);
    painter.setFont(iconFont);
    painter.drawText(pix.rect(), flags, str);
    painter.end();

    return pix;
}

void MainWindow::changed(int index)
{
    QWidget *widget = new QWidget();
    widget->setLayout(new QVBoxLayout());
    widget->setFixedSize(222, 222);
    switch(index)
    {
    case 0:
        widget->layout()->addWidget(new LightButton(widget));
        break;
    case 1:
    {
        quint32 size = 15;
        quint32 pixWidth = 15;
        quint32 pixHeight = 15;

        //从图形字体获得图片,也可以从资源文件或者路径文件获取
        QChar icon = 0xf061;
        QPixmap iconNormal = getPixmap(QColor(100, 100, 100).name(), icon, size, pixWidth, pixHeight);
        QPixmap iconHover = getPixmap(QColor(255, 255, 255).name(), icon, size, pixWidth, pixHeight);
        QPixmap iconCheck = getPixmap(QColor(255, 255, 255).name(), icon, size, pixWidth, pixHeight);
        btns1.clear();
        btns1 << new NavButton() << new NavButton() << new NavButton() << new NavButton();
        for(int i = 0; i < btns1.count(); i++)
        {
            NavButton *btn = btns1.at(i);
            btn->setPaddingLeft(32);
            btn->setLineSpace(6);
            btn->setShowIcon(true);
            btn->setIconSpace(15);
            btn->setIconSize(QSize(10, 10));

            btn->setText(QString("navbutton_%1").arg(i));
            btn->setIconNormal(iconNormal);
            btn->setIconHover(iconHover);
            btn->setIconCheck(iconCheck);

            widget->layout()->addWidget(btn);
            connect(btn, SIGNAL(clicked(bool)), this, SLOT(navButtonClick()));
        }
    }
        break;

    default:
        break;
    }
    widget->show();
}

void MainWindow::navButtonClick()
{
    NavButton *b = (NavButton *)sender();
    qDebug() << "当前按下" << b->text();
    for (int i = 0; i < btns1.count(); i++)
    {
        NavButton *btn = btns1.at(i);
        btn->setChecked(b == btn);
    }
}
