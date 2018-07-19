#include "cparseresult.h"
#include <QThread>
#include <QDebug>
#include <QTextStream>
#include <QTextCodec>
#include <QRegExp>
#include <QFile>
#include <QDatetime>
#include <QEventLoop>
#include <QNetworkRequest>
#include <QDir>
#include <D:\Qt\Qt5.9.3\5.9.3\mingw53_32\include\QtGui\qimage.h>
#include <QBuffer>
#include <QQuickView>
#include <QQmlContext>


#define HOSTNAME          "http://www.xcar.com.cn"

CParseResult::CParseResult(QObject *parent) : QObject(parent)
{
    m_InfoMap.clear();
    m_countHash.clear();
    //m_NetSearch = new CNetSearch();
    m_pd = new PicDownloader();
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setHostName("acidalia");
    database.setDatabaseName("xcarinfo.db");
    database.setUserName("mojito");
    database.setPassword("J0a1m8");
    bool ok = database.open();
    qDebug() << ok;


    //    QSqlQuery  query(database);
    //    sql_query = query;
    //    QString create_sql = "create table userinfo (username varchar(40), title varchar(80),time varchar(20))";
    //    sql_query.prepare(create_sql);
    //    if(!sql_query.exec())
    //    {
    //        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    //    }
    //    else
    //    {
    //        qDebug() << "Table created!";
    //    }

    //qmlRegisterType<ColorMaker>("ch.qt.ParseResult", 1, 0, "ParseResult");
      QQuickView *view = new QQuickView;

      view->rootContext()->setContextProperty("myParseResult", this);
      view->setSource(QUrl("main.qml"));
      view->setTitle(QStringLiteral("XCAR"));
      view->show();
}

void CParseResult::doGetReuslt()
{
    qDebug()<<"###现在的用户列表: "<<m_InfoMap ;
    emit parseDone("123");
}
void CParseResult::doParseWork(QByteArray ba)
{
    // qDebug()<<"###local thread id = "<<QThread::currentThreadId();
    QStringList sl;

    //告诉Qt这个内容以什么形式编码的
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QTextStream stream(&ba,QIODevice::ReadWrite);
    stream.setCodec(codec);
    QString userName;
    QDateTime time;
    QDateTime maxTime  = QDateTime::fromString("2018-07-16", "yyyy-MM-dd");//边界时间;
    QString datetime;
    QString insert_sql = "insert into userinfo values (?, ?,?)";




    QString update_sql = "update userinfo set total = :total,click = :click,reply = :reply where username = :username";
    qDebug()<<"###ddddd";
    while(!stream.atEnd()) {
        QString line = stream.readLine();
        if(line.contains("titlink")){
            m_title = line.split("</a>")[0].split(">")[1];
            QString threadUrl = HOSTNAME +  line.split("href=\"")[1].split("\"")[0];
            qDebug()<<"###帖子的连接:" <<threadUrl;
            //threadUrl = "http://www.xcar.com.cn/bbs/viewthread.php?tid=33796702";
            //   m_NetSearch->requestThread(threadUrl);
            emit enterIntoThread(threadUrl);
            QEventLoop loop;
            connect(this,SIGNAL(parseThreadFinished()),&loop,SLOT(quit()));
            loop.exec();

        }
    }
    emit parsePageFinished();
}

void CParseResult::doThreadParse(QByteArray ba)
{
    QStringList sl;

    //告诉Qt这个内容以什么形式编码的
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QTextStream stream(&ba,QIODevice::ReadWrite);
    stream.setCodec(codec);
    QRegExp rx("http://image.*jpg");
    rx.setMinimal(true);//最小模式，也就是贪婪模式,尽可能多的匹配这种格式
    //利用m_title来建立文件夹，每一次进入一个帖子，都会在上次的解析中获取一个title，在这个函数里面用是能够保证是当前帖子的title

    QString fullPath = "F:/xcar/"+m_title;
    QDir dir(fullPath);
    if(!dir.exists())
    {
        dir.mkdir(fullPath);
    }

    while(!stream.atEnd()) {
        QString line = stream.readLine();
        if(line.contains("http://image.xcar.com.cn")){
            QStringList list;
            int pos = 0;

            while ((pos = rx.indexIn(line, pos)) != -1) {
                list << rx.cap();
                pos += rx.matchedLength();
            }
            for(int i = 0; i<list.length();i++){
                qDebug()<<"###图片开始了: ";
                m_pd->downloadURL(list[i],fullPath + "/" + "picture" + QString::number(i)+ ".jpg" );
            }
        }
    }
    emit parseThreadFinished();
}
QMap<QString,int> & CParseResult::getPostInfomation()
{
    return m_InfoMap;
}
