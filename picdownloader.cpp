#include "picdownloader.h"
#include <QDebug>
#include <QEventLoop>

void PicDownloader::downloadFileFromURL(const QString &url, const QString &filePath)
{
    if (!m_isReady)
        return;
    m_isReady = false;
    const QString fileName = filePath + url.right(url.size() - url.lastIndexOf("/"));
    qDebug() << fileName;
    m_file = new QFile();
    m_file->setFileName(fileName);
    m_file->open(QIODevice::WriteOnly);
    if (!m_file->isOpen()) {
        m_isReady = true;
        return;
    }


    QNetworkAccessManager *manager = new QNetworkAccessManager;
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onDownloadFileComplete(QNetworkReply *)));
    manager->get(request);
}


void PicDownloader::onDownloadFileComplete(QNetworkReply *reply)
{
    if (!m_file->isWritable()) {
        m_isReady = true;
        return;
    }

    m_file->write(reply->readAll());
    m_file->close();
    m_isReady = true;
}

bool PicDownloader::downloadURL(const QString &url, const QString &fileName)
{
    QNetworkAccessManager manager;
    QNetworkRequest request;

    request.setUrl(url);
    QNetworkReply *reply = manager.get(request);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if (reply->error() != QNetworkReply::NoError)
    {
        return false;
    }

    QFile f(fileName);

    if(!f.open(QIODevice::WriteOnly))
        return false;
    QByteArray ba = reply->readAll();

    f.write(ba);
    f.close();

    //    QFile resultFile(filename);
    //    if(resultFile.open(QIODevice::ReadWrite)){
    //        QTextStream stream(&resultFile);
    //        stream.setCodec(codec);
    //        stream<<response;
    //        //qDebug()<<"###输出: " <<codec->toUnicode(ba.data());
    //        resultFile.close();
    //    }

    delete reply;
    return true;
 }
