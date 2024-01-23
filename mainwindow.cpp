#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canDraw = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if (canDraw)
    {
        paintImage("", ui->imageSpace->pos().x(), ui->imageSpace->pos().y());
    }
}

void MainWindow::paintImage(QString fileName, int x, int y)
{
    QPainter painter;
    QImage saveImage(200, 200, QImage::Format_RGB16);

    if (!fileName.isEmpty())
    {
        painter.begin(&saveImage);
    }
    else
    {
        painter.begin(this);
    }
    if (!pix->isNull())
    {
        painter.setClipRect(x, y, 200, 200);
        painter.fillRect(QRect(x, y, 200, 200), Qt::SolidPattern);
        painter.drawPixmap(x - drawPos.x(), y - drawPos.y(), drawSize.width(), drawSize.height(), *pix);
    }

    painter.end();
    if (fileName != "")
    {
        saveImage.save(fileName);
        QMessageBox::information(this, "Сохранение", "Изображение сохранено");
    }
}

void MainWindow::on_browseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть изображение"), QDir::currentPath(), tr("Изображения (*.jpg *.jpeg)"));
    if (!fileName.isEmpty())
    {
        QPixmap *newPix = new QPixmap(fileName);

        if (!newPix->isNull())
        {
            if (newPix->width() < 200 || newPix->height() < 200)
            {
                QMessageBox::warning(this, tr("Ошибка размера"), tr("Разрешение выбранного изображения мало. Выберите другое."));
                return;
            }

            pix = newPix;
            imageSize = pix->size();
            drawSize = pix->size();

            canDraw = true;
        }
        else
        {
            canDraw = false;

            QMessageBox::warning(this, tr("Ошибка изображения"), tr("Неизвестная ошибка файла. Попробуйте снова"));
        }
    }

}


void MainWindow::on_saveButton_clicked()
{

}

