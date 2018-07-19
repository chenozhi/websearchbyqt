#include "cnetsearch.h"
#include <QRegExp>
#include <QTimer>
#include <QDir>
#include <picdownloader.h>
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QString path = QDir::currentPath();
    QGuiApplication::addLibraryPath(path+QString("/plugins"));
    CNetSearch *ns = new CNetSearch();
    ns->requestCookie();
    ns->request();
    return a.exec();
}
