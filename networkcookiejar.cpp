#include "networkcookiejar.h"

NetworkCookieJar::NetworkCookieJar(QObject *parent)
{

}

void NetworkCookieJar::setCookies(const QList<QNetworkCookie> &cookieList)
{
    if(this == NULL) {
        return;
    }
    //基类protected函数
    setAllCookies(cookieList);
}

QList<QNetworkCookie> NetworkCookieJar::getCookies()
{
    return allCookies();
}
