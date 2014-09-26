#ifndef JSONTREEVIEW_H
#define JSONTREEVIEW_H

#include <QTreeWidget>
#include <QJsonArray>
#include <QJsonDocument>

#include "jsinfo.h"

class JsonTreeView : public QTreeWidget
{
    Q_OBJECT
public:
    explicit JsonTreeView(QWidget *parent = 0);
    bool loadJSON(const QString& filePath);
    void readJSON(const QJsonObject &json);

protected:
    void dragMoveEvent(QDragMoveEvent *event);

private:
    void addChildItem(QTreeWidgetItem* parent, const JsInfo& json);
    void loadItems();

signals:

public slots:

private:
    QVector<JsInfo> m_jsInfos;


    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *);
};

#endif // JSONTREEVIEW_H
