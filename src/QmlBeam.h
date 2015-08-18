#ifndef QMLBEAM_H_
#define QMLBEAM_H_

#include <bb/cascades/Application>
#include <QObject>
#include <QUrl>

namespace bb
{
    namespace cascades
    {
        class AbstractPane;
    }
}
/**
 * QmlBeam Description
 *
 * A utility object that can be used to run the application using
 * the DevelopmentSupport signals to update the QML part of your app
 * on the fly. Every time you save a QML file, the file is uploaded
 * to the device and the application scene is reloaded.
 */
class QmlBeam: public QObject
{
    Q_OBJECT

public:
    QmlBeam(QObject *parent = 0);

private slots:

     // The reloadQML() function is where the QML gets
     // reloaded in the application.

    void reloadQML(QUrl mainFile);

     // The cleanup() function is where the saved
     // application context is cleaned up.

    void cleanup();

private:
    // Root pane of the application scene
    bb::cascades::AbstractPane* mRoot;
};

#endif /* QMLBEAM_H_ */
