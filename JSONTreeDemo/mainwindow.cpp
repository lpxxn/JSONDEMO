#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jsontreeview.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    JsonTreeView* tv = new JsonTreeView(this);
    tv->loadJSON(QStringLiteral(":/JSON/jsJSON"));
    ui->centralWidget->layout()->addWidget(tv);
}

MainWindow::~MainWindow()
{
    delete ui;
}

