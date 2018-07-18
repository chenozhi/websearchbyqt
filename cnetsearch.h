#ifndef CNETSEARCH_H
#define CNETSEARCH_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QByteArray>
#include <QDebug>
#include <networkcookiejar.h>
#include "cparseresult.h"
#include <QThread>
#include <QTimer>

#define MAIN_REQUEST_URL  "http://www.xcar.com.cn/bbs/forumdisplay.php?fid=46"
#define HOSTNAME          "http://www.xcar.com.cn"

class CNetSearch : public QObject
{
    Q_OBJECT
public:
    explicit CNetSearch(QObject *parent = nullptr);

    Q_INVOKABLE requestCookie();
    Q_INVOKABLE request();
signals:
    void startParsing(QByteArray);
    void stopParsing();
    void startRequest();
public slots:
    Q_INVOKABLE void replyFromRemote(QNetworkReply *reply);
private:
    QNetworkAccessManager *m_NetAccManager;
    QNetworkAccessManager *m_reqManager;
    NetworkCookieJar *m_cookies;
    CParseResult *m_parseResult;
    QThread *m_thread;
    int m_page;
    QTimer *timer;
};

#endif // CNETSEARCH_H
