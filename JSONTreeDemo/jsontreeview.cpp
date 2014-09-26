#include "jsontreeview.h"

#include <QFile>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>
#include <QDragMoveEvent>

JsonTreeView::JsonTreeView(QWidget *parent) :
    QTreeWidget(parent)
{

    setHeaderLabels(QStringList() << "Name" << "Description" );
    setAlternatingRowColors(true);
    setDragDropMode(QAbstractItemView::DragDrop);
}

bool JsonTreeView::loadJSON(const QString &filePath)
{
    QFile loadFile(filePath);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("load error ");
        return false;
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);
    QJsonObject jsobj = loadDoc.object();
    readJSON(jsobj);
    return true;
}

void JsonTreeView::readJSON(const QJsonObject &json)
{
    for (const QString& key : json.keys()) {
        JsInfo jsInfo(key);
        QJsonValue jv = json.value(key);
        QJsonArray jas = jv.toArray();
        if (jas.count() > 0)
            for (const QJsonValue& v : jas) {
                jsInfo.addChild(v.toObject());
            }
        m_jsInfos.append(jsInfo);
    }

    loadItems();
}

void JsonTreeView::loadItems()
{
    for (const JsInfo& js : m_jsInfos) {
        qDebug() << js.name();
        QTreeWidgetItem* parent = new QTreeWidgetItem(this, QStringList() << js.name() << js.desc() << js.fileName());
        addChildItem(parent, js);
        addTopLevelItem(parent);
    }
}

void JsonTreeView::addChildItem(QTreeWidgetItem *parent, const JsInfo &json)
{
    if (json.childs().count() == 0)
        return;
    for (const JsInfo& js : json.childs()) {
        qDebug() << js.name() << js.desc() << js.fileName();
        QTreeWidgetItem* child = new QTreeWidgetItem(parent, QStringList() << js.name() << js.desc() << js.fileName());
        child->setData(0, Qt::UserRole, 0);
        parent->addChild(child);
        addChildItem(child, js);
    }
}


void JsonTreeView::dragMoveEvent(QDragMoveEvent* event)
{
    qDebug() << this->frameGeometry() << "  " << event->pos();
    if (this->frameGeometry().contains(event->pos())) {
        event->ignore();
    } else {
        event->acceptProposedAction();
    }
}


void JsonTreeView::dragEnterEvent(QDragEnterEvent* e)
{
    qDebug() << "enter ";
    QTreeWidget::dragEnterEvent(e);
}
