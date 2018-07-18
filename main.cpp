#include <QCoreApplication>
#include "cnetsearch.h"
#include <QRegExp>
#include <QTimer>
#include <QDir>
#include <picdownloader.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path = QDir::currentPath();
         QCoreApplication::addLibraryPath(path+QString("/plugins"));
//    PicDownloader *pa = new PicDownloader();
//    pa->downloadURL(QString("http://image.xcar.com.cn/attachments/a/day_180327/2018032717_0eb4cdb7ddf849849d41fJMZp8da3ENQ.jpg"),"123");
     CNetSearch *ns = new CNetSearch();
    ns->requestCookie();
    ns->request();
    return a.exec();
}
