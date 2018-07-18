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


class CNetSearch : public QObject
{
    Q_OBJECT
public:
    explicit CNetSearch(QObject *parent = nullptr);

    Q_INVOKABLE requestCookie();
signals:
    void startParsing(QByteArray);
    void startParsingThread(QByteArray);
    void stopParsing();
    void startRequest();
public slots:
    Q_INVOKABLE void replyFromRemote(QNetworkReply *reply);
    Q_INVOKABLE void replyFromThreadAsk(QNetworkReply *reply);
    Q_INVOKABLE void request();
    Q_INVOKABLE void requestThread(QString url);
private:
    QNetworkAccessManager *m_NetAccManager;
    QNetworkAccessManager *m_reqManager;
    QNetworkAccessManager *m_reqThreadMan;
    NetworkCookieJar *m_cookies;
    CParseResult *m_parseResult;
    QThread *m_thread;
    QThread *m_threadPic;
    int m_page;
    QTimer *timer;
};

#endif // CNETSEARCH_H
