#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_3,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_4,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_5,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_6,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_7,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_8,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_9,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_10,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_11,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_12,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_13,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_14,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_15,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_16,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_17,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_18,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_19,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_20,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_21,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_22,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_23,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_24,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_25,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_26,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_27,  &QPushButton::clicked, this, &MainWindow::handlePageChange);
    connect(ui->pushButton_28,  &QPushButton::clicked, this, &MainWindow::handlePageChange);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handlePageChange()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString name = button->objectName();

    int currentIndex = ui->stackedWidget->currentIndex();


    //returning to previous page
    if (name == "pushButton_6"|| name == "pushButton_19" || name == "pushButton_21" ||name == "pushButton_28") {
        ui->stackedWidget->setCurrentIndex(previousPageIndex);
        return;
    }
    previousPageIndex = currentIndex;

    //Cat profile
    if (name == "pushButton") {
        ui->stackedWidget->setCurrentIndex(5);
    //Search Page
    } else if (name == "pushButton_2"|| name == "pushButton_8" || name == "pushButton_15" ||name == "pushButton_22"|| name == "pushButton_24" ) {
        ui->stackedWidget->setCurrentIndex(3);
    //HomePage
    } else if (name == "pushButton_7"|| name == "pushButton_14"|| name == "pushButton_23") {
        ui->stackedWidget->setCurrentIndex(0);
    }
    //Camera Page
    else if (name == "pushButton_3"|| name == "pushButton_9"|| name == "pushButton_16" || name == "pushButton_25") {
        ui->stackedWidget->setCurrentIndex(6);
    }//Story Page
    else if (name == "pushButton_4"|| name == "pushButton_10"|| name == "pushButton_17" || name == "pushButton_26") {
        ui->stackedWidget->setCurrentIndex(4);
    }
    //User Profile
    else if (name == "pushButton_5"|| name == "pushButton_11"|| name == "pushButton_18" || name == "pushButton_22"|| name == "pushButton_27") {
        ui->stackedWidget->setCurrentIndex(2);
    }
    //LikesPage
    else if (name == "pushButton_12 "||name == "pushButton_13"||name == "pushButton_20") {
        ui->stackedWidget->setCurrentIndex(1);
    }

}

