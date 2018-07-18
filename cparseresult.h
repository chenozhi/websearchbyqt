#ifndef CPARSERESULT_H
#define CPARSERESULT_H

#include <QObject>

#include <QMap>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QHash>
#include <QPair>
#include <picdownloader.h>


class CParseResult : public QObject
{
    Q_OBJECT
public:
    explicit CParseResult(QObject *parent = nullptr);
    QMap<QString,int>& getPostInfomation();
signals:
    void parseFinished();
    void parseThreadFinished();
    void enterIntoThread(QString);
public slots:
    void doParseWork(QByteArray ba);
    void doThreadParse(QByteArray ba);
    void doGetReuslt();
private:
    QMap<QString,int> m_InfoMap;
    QHash<QString,QPair<int,int>> m_countHash;
    QSqlQuery sql_query;
    QString m_title;
    PicDownloader *m_pd;
};

#endif // CPARSERESULT_H
