#include "cnetsearch.h"
#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QList>
#include <QEventLoop>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QTimer>

CNetSearch::CNetSearch(QObject *parent) : QObject(parent) , m_page(1)
{
    m_NetAccManager = new QNetworkAccessManager(this);
    m_reqManager = new QNetworkAccessManager(this);
    m_parseResult = new CParseResult();
    m_cookies = new NetworkCookieJar();
    m_thread = new QThread();

    m_parseResult->moveToThread(m_thread);

    connect(m_reqManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFromRemote(QNetworkReply*)));
    connect(this,SIGNAL(startParsing(QByteArray)),m_parseResult,SLOT(doParseWork(QByteArray)));
    connect(this,SIGNAL(stopParsing()),m_parseResult,SLOT(doGetReuslt()));
    connect(m_parseResult,SIGNAL(parseFinished()),this,SLOT(request()));
}

void CNetSearch::replyFromRemote(QNetworkReply *reply)
{
    QByteArray ba = reply->readAll();

    //告诉Qt这个内容以什么形式编码的
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QString response = codec->toUnicode(ba.data());
    QString filename = "response.txt";
//    if(m_page == 1) filename = "rep1.txt";
//    else if(m_page == 2) filename = "rep2.txt";
//    else if(m_page == 3) filename = "rep3.txt";
//    else filename = "response.txt";
//    QFile resultFile(filename);
//    if(resultFile.open(QIODevice::ReadWrite)){
//        QTextStream stream(&resultFile);
//        stream.setCodec(codec);
//        stream<<response;
//        //qDebug()<<"###输出: " <<codec->toUnicode(ba.data());
//        resultFile.close();
//    }
//    QTextStream txtStream(&ba,QIODevice::ReadWrite);
//    txtStream.setCodec(codec);
    if(!m_thread->isRunning())
        m_thread->start();

    if(m_page > 100){
       emit stopParsing();
   //     timer->stop();
       return;
    }

    emit startParsing(ba);
    m_page += 1;


}

CNetSearch::requestCookie()
{
    QEventLoop loop;
    QNetworkRequest request;
    m_NetAccManager->setCookieJar(m_cookies);
    request.setUrl(QUrl(MAIN_REQUEST_URL));
    QNetworkReply *reply = m_NetAccManager->get(request);
    connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QList<QNetworkCookie> cookies = m_cookies->getCookies();
    //qDebug()<<"###当前的返回: " << cookies;

//     timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(request()));
//    timer->start(6000);


    //"http://www.xcar.com.cn/bbs/forumdisplay.php?fid=46&page=2"
}

CNetSearch::request()
{
    QVariant var;
    if(m_page == 2) requestCookie();
    var.setValue(m_cookies->getCookies());
    QNetworkRequest request;
    request.setHeader(QNetworkRequest::CookieHeader,var);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"text/html");

    if(m_page == 1){
        request.setUrl(QUrl(MAIN_REQUEST_URL));
    }else{
        request.setUrl(QUrl(MAIN_REQUEST_URL + QString("&page=") + QString::number(m_page,10)));
    }

    m_reqManager->get(request);

}
