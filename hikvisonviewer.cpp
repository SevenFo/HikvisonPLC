#include "hikvisonviewer.h"
#include <QtWidgets/QWidget>
#include <QtQuickWidgets/QQuickWidget>

HikvisonViewer::HikvisonViewer(QQuickItem *parent)
{
    hik = new HikvisonHandler(parent); // init hikvison
    qDebug()<<"inited hikvision!";
    void (HikvisonViewer::*updateImage2)(QImage image) = &HikvisonViewer::updateImage;
    connect(hik,&HikvisonHandler::hasNewPic,this,updateImage2);



}
HikvisonViewer::~HikvisonViewer()
{

}

void HikvisonViewer::loginAndSetup()
{
    qDebug()<<"setting up hivison";
    hik->SetupCamera();
}

void HikvisonViewer::startDecode()
{
    hik->SetupRealPlay();

}

void HikvisonViewer::setHost(QString &d)
{
    hik->host = d;
    this->hik->port = d;
    qDebug()<<"set host:"<<d;
}

void HikvisonViewer::setPort(QString &d)
{
    hik->port = d;
    qDebug()<<"set port:"<<d;

}
void HikvisonViewer::setUserid(QString &d)
{
    hik->userid = d;
    qDebug()<<"set userid:"<<d;

}
void HikvisonViewer::setPassword(QString &d)
{
    hik->password = d;
    qDebug()<<"set password:"<<d;

}
QString HikvisonViewer::getHost() const
{
    return hik->host;
}
QString HikvisonViewer::getPort() const
{
    return hik->port;
}
QString HikvisonViewer::getUserid() const
{
    return hik->userid;
}
QString HikvisonViewer::getPassword() const
{
    return hik->password;
}
