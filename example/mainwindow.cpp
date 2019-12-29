#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "multiplerowstabbar.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MultipleRowsTabBar *multiTab = new MultipleRowsTabBar(2, this);

    QWidget *comConfWidget = new QWidget;
    QWidget *ipConfWidget = new QWidget;
    QWidget *scalesConf = new QWidget;
    QWidget *camConf = new QWidget;
    QWidget *autoWidget = new QWidget;
    QWidget *digitConf = new QWidget;
    QWidget *rfidWidget = new QWidget;
    QWidget *qrWidget = new QWidget;

    multiTab->addTab(0, tr("COM"), comConfWidget);
    multiTab->addTab(0, tr("IP"), ipConfWidget);
    multiTab->addTab(0, tr("Scales"), scalesConf);
    multiTab->addTab(0, tr("Cams"), camConf);
    multiTab->addTab(1, tr("ICPCON"), autoWidget);
    multiTab->addTab(1, tr("Digit table"), digitConf);
    multiTab->addTab(1, tr("RFID"), rfidWidget);
//    multiTab->addTab(1, tr("QR"), qrWidget);

    multiTab->setCurrentTab(1, 1);

    QWidget *centralWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(multiTab);
    centralWidget->setLayout(layout);

    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

