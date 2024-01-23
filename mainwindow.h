#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);
    void paintImage(QString fileName, int x, int y);


private slots:
    void on_browseButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    bool canDraw;
    QPixmap *pix;
    QSize imageSize;
    QSize drawSize;
    QPoint drawPos;

};
#endif // MAINWINDOW_H
