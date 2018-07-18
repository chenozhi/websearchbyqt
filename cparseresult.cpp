#include "cparseresult.h"
#include <QThread>
#include <QDebug>
#include <QTextStream>
#include <QTextCodec>
#include <QRegExp>
#include <QFile>
#include <QDatetime>


CParseResult::CParseResult(QObject *parent) : QObject(parent)
{
    m_InfoMap.clear();
    m_countHash.clear();


    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setHostName("acidalia");
    database.setDatabaseName("xcarinfo.db");
    database.setUserName("mojito");
    database.setPassword("J0a1m8");
    bool ok = database.open();
    qDebug() << ok;


    QSqlQuery  query(database);
    sql_query = query;
    QString create_sql = "create table userinfo (username varchar(40), title varchar(80),time varchar(20))";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }


}

void CParseResult::doGetReuslt()
{
    qDebug()<<"###现在的用户列表: "<<m_InfoMap ;
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

    QRegExp rx("(\\d+)");
    while(!stream.atEnd()) {
        QString line = stream.readLine();
        if(line.contains("titlink")){
            QString title = line.split("</a>")[0].split(">")[1];

            while(!stream.atEnd()) {
                QString dateline = stream.readLine();
                if(dateline.contains("uid=")) {
                    userName = dateline.split("</a>")[0].split(">")[1];
                    dateline = stream.readLine();
                    datetime = dateline.split("</span>")[0].split(">")[1];//<span class="tdate">2018-07-09</span>
                    time = QDateTime::fromString(datetime, "yyyy-MM-dd");//读取的主题时间

                    if( QDateTime::fromString("2018-06-16","yyyy-MM-dd") <= time && time <= maxTime ){
                        sql_query.prepare(insert_sql);
                        sql_query.addBindValue(userName);
                        sql_query.addBindValue(title);
                        sql_query.addBindValue(time.toString());
                        if(!sql_query.exec())
                        {
                            qDebug() << sql_query.lastError();
                        }
                        else
                        {
                            //qDebug() << "inserted OK!";
                        }
                    }

                    break;
                }
            }


        }
    }
    emit parseFinished();
}

QMap<QString,int> & CParseResult::getPostInfomation()
{
    return m_InfoMap;
}
