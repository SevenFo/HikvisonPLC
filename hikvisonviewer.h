#ifndef HIKVISONVIEWER_H
#define HIKVISONVIEWER_H

#include <QObject>
#include <QQuickItem>
#include <imageviewer.h>
#include <hikvisonhandler.h>
#include <hikvisonhandlercstyelfuncs.h>

class HikvisonViewer : public IMageViewer
{
    Q_OBJECT

    Q_PROPERTY(QString host READ getHost WRITE setHost );
    Q_PROPERTY(QString port READ getPort WRITE setPort);
    Q_PROPERTY(QString userid READ getUserid WRITE setUserid );
    Q_PROPERTY(QString password READ getPassword WRITE setPassword);

public:
    HikvisonViewer(QQuickItem *parent = nullptr);
    virtual ~HikvisonViewer();

    Q_INVOKABLE void loginAndSetup();
    Q_INVOKABLE void startDecode();


    QString getHost() const;
    QString getPort() const;
    QString getUserid() const;
    QString getPassword() const;

    void setHost(QString &d);
    void setPort(QString &d);
    void setUserid(QString &d);
    void setPassword(QString &d);

signals:

private:
    HikvisonHandler *hik;


};

#endif // HIKVISONVIEWER_H
