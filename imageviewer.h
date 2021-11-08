#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QQuickPaintedItem>
#include <QObject>
#include <QQuickItem>
#include <hikvisonhandler.h>
#include <hikvisonhandlercstyelfuncs.h>
#include <QImage>

class IMageViewer : public QQuickPaintedItem
{
    Q_OBJECT
public:
    IMageViewer(QQuickItem *parent = 0);
    ~IMageViewer();

protected:
    void paint(QPainter *painter);
    QImage image;
public slots:
    void updateImage();
    void updateImage(QImage i);
private:

};

#endif // IMAGEVIEWER_H
