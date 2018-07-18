#ifndef CPARSERESULT_H
#define CPARSERESULT_H

#include <QObject>

#include <QMap>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QHash>
#include <QPair>

class CParseResult : public QObject
{
    Q_OBJECT
public:
    explicit CParseResult(QObject *parent = nullptr);
    QMap<QString,int>& getPostInfomation();
signals:
    void parseFinished();
public slots:
    void doParseWork(QByteArray ba);
    void doGetReuslt();
private:
    QMap<QString,int> m_InfoMap;
    QHash<QString,QPair<int,int>> m_countHash;
    QSqlQuery sql_query;
};

#endif // CPARSERESULT_H
