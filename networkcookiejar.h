#ifndef NETWORKCOOKIEJAR_H
#define NETWORKCOOKIEJAR_H

#include <QObject>
#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QList>

class NetworkCookieJar : public QNetworkCookieJar
{
    Q_OBJECT
public:
    NetworkCookieJar(QObject *parent = nullptr);

    QList<QNetworkCookie> getCookies();
    void setCookies(const QList<QNetworkCookie>& cookieList);
};

#endif // NETWORKCOOKIEJAR_H
