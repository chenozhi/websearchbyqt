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
       database.setDatabaseName("mydatabase1.db");
       database.setUserName("mojito");
       database.setPassword("J0a1m8");
       bool ok = database.open();
       qDebug() << ok;


     QSqlQuery  query(database);
     sql_query = query;
    QString create_sql = "create table userinfo (username varchar(40), total int,click int,reply int)";
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
    QDateTime maxTime;

    QString insert_sql = "insert into userinfo values (?, ? ,? ,?)";




    QString update_sql = "update userinfo set total = :total,click = :click,reply = :reply where username = :username";

    QRegExp rx("(\\d+)");
    while(!stream.atEnd()) {
        QString line = stream.readLine();
        if(line.contains("uid=")){
            userName = line.split("</a>")[0].split(">")[1];
            //没有加入过的username才第一次插入，否则就修改value值.
            QString dateLine = stream.readLine();
            QString datetime = dateLine.split("</span>")[0].split(">")[1];//<span class="tdate">2018-07-09</span>
            time = QDateTime::fromString(datetime, "yyyy-MM-dd");//读取的主题时间
            maxTime = QDateTime::fromString("2018-07-15", "yyyy-MM-dd");//边界时间
            if( QDateTime::fromString("2018-07-09","yyyy-MM-dd") <= time && time <= maxTime ){
                if(userName == "成都白手帕" || userName == "健康小宝" || userName == "爱卡福利专员") continue;
                stream.readLine();
                QString tcount = stream.readLine();

                 QStringList list;
                 int pos = 0;

                 while ((pos = rx.indexIn(tcount, pos)) != -1) {
                     list << rx.cap(1);
                      pos += rx.matchedLength();
                 }
                QString replyNum = list[0];
                QString clickNum = list[1];




                if(m_InfoMap[userName] == 0){
                    QPair<int,int> pair(clickNum.toInt(),replyNum.toInt());
                    m_countHash.insert(userName,pair);
                    m_InfoMap.insert(userName,1);

                    sql_query.prepare(insert_sql);
                    sql_query.addBindValue(userName);
                    sql_query.addBindValue(1);
                    sql_query.addBindValue(clickNum);
                    sql_query.addBindValue(replyNum);
                    if(!sql_query.exec())
                    {
                        qDebug() << sql_query.lastError();
                    }
                    else
                    {
                        qDebug() << "inserted OK!";
                    }
                }
                else{
                    QPair<int,int> pair(m_countHash[userName].first + clickNum.toInt(),m_countHash[userName].second + replyNum.toInt());
                    m_countHash[userName] = pair;
                    m_InfoMap[userName] = m_InfoMap.value(userName) + 1;
                    if(userName == "object") qDebug() << "###查看当前： " <<m_countHash[userName].first + " -- " + clickNum.toInt();
                    sql_query.prepare(update_sql);
                    sql_query.bindValue(":total", m_InfoMap[userName]);
                    sql_query.bindValue(":username", userName);
                    sql_query.bindValue(":click", (m_countHash[userName].first) + clickNum.toInt());
                    sql_query.bindValue(":reply", m_countHash[userName].second + replyNum.toInt());
                    if(!sql_query.exec())
                    {
                        qDebug() << sql_query.lastError();
                    }
                    else
                    {
                        qDebug() << "updated OK!";
                    }
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
