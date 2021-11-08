#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "hikvisonhandler.h"
#include <imageviewer.h>
#include <hikvisonviewer.h>
#include <QQuickWidget>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    qmlRegisterType<IMageViewer>("siky.ImageViewer",1,0,"ImageViewer");
    qmlRegisterType<HikvisonViewer>("siky.HikvisonViewer",1,0,"HikvisonViewer");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
