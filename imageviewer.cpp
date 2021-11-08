#include "imageviewer.h"
#include <QImage>
#include <QPainter>

IMageViewer::IMageViewer(QQuickItem*parent):QQuickPaintedItem(parent)
{
    image = QImage();


}
IMageViewer::~IMageViewer()
{

}

void IMageViewer::paint(QPainter *painter)
{
    painter->drawImage(this->boundingRect(),image);
}
void IMageViewer::updateImage()
{
    IMageViewer::update();
}
void IMageViewer::updateImage(QImage i)
{
    image = i;
    qDebug()<<image.size().height();
    qDebug()<<image.size().width();
    qDebug()<<image.sizeInBytes();
    IMageViewer::update();

}
