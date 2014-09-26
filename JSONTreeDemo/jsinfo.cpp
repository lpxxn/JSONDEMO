#include "jsinfo.h"
#include <QJsonObject>
#include <QDebug>

JsInfo::JsInfo()
{

}

JsInfo::JsInfo(const QString &name) :
    m_name(name)
{

}

QString JsInfo::name() const
{
    return m_name;
}

void JsInfo::setName(const QString &name)
{
    m_name = name;
}
QString JsInfo::desc() const
{
    return m_desc;
}

void JsInfo::setDesc(const QString &desc)
{
    m_desc = desc;
}
QString JsInfo::fileName() const
{
    return m_fileName;
}

void JsInfo::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

QVector<JsInfo> JsInfo::childs() const
{
    return m_childs;
}

void JsInfo::readJSON(const QJsonObject &json)
{
    m_name = json["name"].toString();
    m_desc = json["description"].toString();
    m_fileName = json["fileName"].toString();
}

void JsInfo::addChild(const QJsonObject &json)
{
    JsInfo child;
    child.readJSON(json);
    m_childs.append(child);
}




