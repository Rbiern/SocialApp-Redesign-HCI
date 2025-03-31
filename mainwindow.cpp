#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <queue>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();

    QStringList excludedNames = {
        "pushButton_32", "pushButton_33", "pushButton_34", "pushButton_35",
        "pushButton_55", "pushButton_56", "pushButton_57", "pushButton_58", "pushButton_59",
        "pushButton_60", "pushButton_61", "pushButton_62", "pushButton_63", "pushButton_64",
        "pushButton_65", "pushButton_66"
    };

    for (QPushButton* button : buttons) {
        QString name = button->objectName();
        if (!excludedNames.contains(name)) {
            button->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 50); color: white; border: none; border-radius: 10px; }");
        }
         connect(button, &QPushButton::clicked, this, &MainWindow::handlePageChange);
    }



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
    if (name == "pushButton_78" || name == "pushButton_77" || name == "pushButton_74" || name == "pushButton_6"|| name == "pushButton_19" || name == "pushButton_21" || name == "pushButton_22"||name == "pushButton_28"||name == "pushButton_38") {
        ui->stackedWidget->setCurrentIndex(previousPageIndex.front());
        previousPageIndex.pop_front();
        return;
    }

    if (previousPageIndex.empty() || previousPageIndex.front() != currentIndex) {
        previousPageIndex.push_front(currentIndex);
    }

    //Cat profile
    if (name == "pushButton") {
        ui->stackedWidget->setCurrentWidget(ui->page_6);
    //Search Page
    } else if (name == "pushButton_8" || name == "pushButton_15" ||name == "pushButton_22"|| name == "pushButton_24" ) {
        ui->stackedWidget->setCurrentWidget(ui->page_5);
    //HomePage
    } else if (name == "pushButton_7"|| name == "pushButton_14"|| name == "pushButton_23"|| name == "pushButton_36" || name == "pushButton_39" || name == "pushButton_40"
               || name == "pushButton_41" || name == "pushButton_42" || name == "pushButton_43") {
        ui->stackedWidget->setCurrentWidget(ui->page);
    }
    //Camera Page
    else if (name == "pushButton_3"|| name == "pushButton_9"|| name == "pushButton_16" || name == "pushButton_25") {
        ui->stackedWidget->setCurrentWidget(ui->page_7);
    }//Story Page
    else if (name == "pushButton_4"|| name == "pushButton_10"|| name == "pushButton_17" || name == "pushButton_26") {
        ui->stackedWidget->setCurrentWidget(ui->page_5);
    }
    //User Profile
    else if (name == "pushButton_5"|| name == "pushButton_11"|| name == "pushButton_18" || name == "pushButton_22"|| name == "pushButton_27") {
        ui->stackedWidget->setCurrentWidget(ui->page_3);
    }
    //LikesPage
    else if (name == "pushButton_12 "||name == "pushButton_13"||name == "pushButton_20") {
        ui->stackedWidget->setCurrentWidget(ui->page_2);
    }
    //Pressing Message
    else if (name == "pushButton_37" ||name == "pushButton_67") {
        ui->stackedWidget->setCurrentWidget(ui->page_8);
    }
    //Pressing Sort
    else if (name == "pushButton_29" ||name == "pushButton_53") {
        ui->stackedWidget->setCurrentWidget(ui->page_9);
    }
    //Pressing Edit
    else if (name == "pushButton_30") {
        ui->stackedWidget->setCurrentWidget(ui->page_13);
    }
    //Pressing Unread
    else if (name == "pushButton_31" ||name == "pushButton_46" ||name == "pushButton_49" ||name == "pushButton_52" ||name == "pushButton_54" ||name == "pushButton_70") {
        ui->stackedWidget->setCurrentWidget(ui->page_14);
    }
    //Pressing Alphabet
    else if (name == "pushButton_32" ||name == "pushButton_55" ||name == "pushButton_59" ||name == "pushButton_63" ) {
        ui->stackedWidget->setCurrentWidget(ui->page_10);
    }
    //Pressing Recent
    else if (name == "pushButton_33" ||name == "pushButton_56" ||name == "pushButton_60" ||name == "pushButton_64") {
        ui->stackedWidget->setCurrentWidget(ui->page_11);
    }
    //Pressing Favourites
    else if (name == "pushButton_34" ||name == "pushButton_57" ||name == "pushButton_61" ||name == "pushButton_65") {
        ui->stackedWidget->setCurrentWidget(ui->page_12);
    }
    //Alphabetic Edit
    else if (name == "pushButton_45" ||name == "pushButton_68") {
        ui->stackedWidget->setCurrentWidget(ui->page_16);
    }
    //Alphabetic Sort
    else if (name == "pushButton_44" ||name == "pushButton_69") {
        ui->stackedWidget->setCurrentWidget(ui->page_15);
    }
    //Recent Edit
    else if (name == "pushButton_48") {
        ui->stackedWidget->setCurrentWidget(ui->page_18);
    }
    //Recent Sort
    else if (name == "pushButton_47"||name == "pushButton_71") {
        ui->stackedWidget->setCurrentWidget(ui->page_17);
    }
    //Favorite Edit
    else if (name == "pushButton_51") {
        ui->stackedWidget->setCurrentWidget(ui->page_20);
    }
    //Favorite Sort
    else if (name == "pushButton_50" ||name == "pushButton_72") {
        ui->stackedWidget->setCurrentWidget(ui->page_19);

    }
    //Search
    else if (name == "pushButton_2"){
        ui->stackedWidget->setCurrentWidget(ui->page_4);
    }
    //Search
    else if (name == "pushButton_73"){
        ui->stackedWidget->setCurrentWidget(ui->page_21);
    }
    else if (name == "pushButton_75" || name == "pushButton_78"){
        ui->stackedWidget->setCurrentWidget(ui->page_22);
    }
    else if (name == "pushButton_76"){
        ui->stackedWidget->setCurrentWidget(ui->page_23);
    }
}

