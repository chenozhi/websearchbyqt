#include <QCoreApplication>
#include "cnetsearch.h"
#include <QRegExp>
#include <QTimer>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path = QDir::currentPath();
         QCoreApplication::addLibraryPath(path+QString("/plugins"));

    CNetSearch *ns = new CNetSearch();
    ns->requestCookie();
    ns->request();
    return a.exec();
}
