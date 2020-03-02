#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../moudle/Button/lightbutton/lightbutton.h"
#include "../moudle/Button/navbutton/navbutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QList<NavButton *> btns1;

public Q_SLOTS:
    void changed(int index);
    void navButtonClick();

private:
    QPixmap getPixmap(const QColor &color, const QChar &str, quint32 size = 12,
                      quint32 pixWidth = 15, quint32 pixHeight = 15,
                      int flags = Qt::AlignCenter);

private:
    QFont iconFont;             //图形字体

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
