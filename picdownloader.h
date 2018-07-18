#ifndef PICDOWNLOADER_H
#define PICDOWNLOADER_H

#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QUrl>

class PicDownloader : public QObject {
    Q_OBJECT
public:
    explicit PicDownloader(QObject *parent = 0) : QObject(parent) {m_isReady = true;}
    virtual ~PicDownloader() {}
    void downloadFileFromURL(const QString &url, const QString &filePath);
    bool downloadURL(const QString &url, const QString &fileName);
private slots:
    void onDownloadFileComplete(QNetworkReply *reply);
private:
    QFile *m_file;
    bool m_isReady;
};

QNetworkReply::NetworkError downloadURL(const QString &url, const QString &fileName);
#endif // PICDOWNLOADER_H
