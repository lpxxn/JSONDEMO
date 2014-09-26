#ifndef JSINFO_H
#define JSINFO_H

#include <QObject>
#include <QString>
#include <QVector>

class JsInfo
{
public:
    JsInfo();
    JsInfo(const QString& name);

    QString name() const;
    void setName(const QString &name);

    QString desc() const;
    void setDesc(const QString &desc);

    QString fileName() const;
    void setFileName(const QString &fileName);

    QVector<JsInfo> childs() const;

    void readJSON(const QJsonObject &json);

    void addChild(const QJsonObject &json);

private:
    QString m_name;
    QString m_desc;
    QString m_fileName;
    QVector<JsInfo> m_childs;

};

#endif // JSINFO_H
