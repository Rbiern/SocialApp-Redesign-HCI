#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <queue>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scrollTimer(new QTimer(this))
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    setWindowTitle("Social Media");

    originalImage.append(QPixmap(":/images/images/StoryPage.png"));
    scrollImages.append(QPixmap(":/images/images/right1.png"));
    scrollImages.append(QPixmap(":/images/images/right2.png"));
    scrollImages.append(QPixmap(":/images/images/right3.png"));

    scrollImages2.append(QPixmap(":/images/images/left1.png"));
    scrollImages2.append(QPixmap(":/images/images/left2.png"));
    scrollImages2.append(QPixmap(":/images/images/left3.png"));

    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();

    connect(scrollTimer, &QTimer::timeout, this, &MainWindow::onImageScroll);

    connect(ui->pushButton_155, &QPushButton::pressed, this, &MainWindow::onButtonPressed);
    connect(ui->pushButton_155, &QPushButton::released, this, &MainWindow::onButtonReleased);
    connect(ui->pushButton_156, &QPushButton::pressed, this, &MainWindow::onButtonPressed);
    connect(ui->pushButton_156, &QPushButton::released, this, &MainWindow::onButtonReleased);



    QStringList excludedNames = {
        "pushButton_32", "pushButton_33", "pushButton_34", "pushButton_35",
        "pushButton_55", "pushButton_56", "pushButton_57", "pushButton_58", "pushButton_59",
        "pushButton_60", "pushButton_61", "pushButton_62", "pushButton_63", "pushButton_64",
        "pushButton_65", "pushButton_66"
    };

    for (QPushButton* button : buttons) {
        QString name = button->objectName();
        if (!excludedNames.contains(name)) {
            button->setStyleSheet("QPushButton { background-color: rgba(255, 255, 255, 0); color: white; border: none; border-radius: 10px; }");
        }
         connect(button, &QPushButton::clicked, this, &MainWindow::handlePageChange);
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onButtonPressed()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (senderButton == ui->pushButton_155) {
        scrollDirection = 1;
    } else if (senderButton == ui->pushButton_156) {
        scrollDirection = 2;
    }

    scrollTimer->start(300);
}

void MainWindow::onButtonReleased()
{
    scrollTimer->stop();
    scrollIndex = 0;
    ui->label_5->setPixmap(originalImage[0]);

}

void MainWindow::onImageScroll()
{
    switch (scrollDirection) {
    case 1:
        scrollIndex = (scrollIndex + 1) % scrollImages.size();
        ui->label_5->setPixmap(scrollImages[scrollIndex]);
        break;
    case 2:
        scrollIndex = (scrollIndex + 1) % scrollImages2.size();
        ui->label_5->setPixmap(scrollImages2[scrollIndex]);
        break;
    default:
        break;
    }
}

void MainWindow::handlePageChange()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString name = button->objectName();

    int currentIndex = ui->stackedWidget->currentIndex();



    //returning to previous page
    if (name == "pushButton_78" || name == "pushButton_77" || name == "pushButton_74" || name == "pushButton_6"|| name == "pushButton_19" || name == "pushButton_21" || name == "pushButton_22"
        ||name == "pushButton_38") {
        ui->stackedWidget->setCurrentIndex(previousPageIndex.front());
        previousPageIndex.pop_front();
        return;
    }

    if (previousPageIndex.empty() || previousPageIndex.front() != currentIndex) {
        previousPageIndex.push_front(currentIndex);
    }

    //Cat profile
    if (name == "pushButton" || name == "pushButton_93" || name == "pushButton_100") {
        ui->stackedWidget->setCurrentWidget(ui->page_6);
    //Search Page
    } else if (name == "pushButton_8" ||name == "pushButton_22"|| name == "pushButton_24" ) {
        ui->stackedWidget->setCurrentWidget(ui->page_5);
    //HomePage
    } else if (name == "pushButton_7"|| name == "pushButton_14"|| name == "pushButton_23"||name == "pushButton_28"|| name == "pushButton_36" || name == "pushButton_39" || name == "pushButton_40"
               || name == "pushButton_41" || name == "pushButton_42" || name == "pushButton_43" || name == "pushButton_81" || name == "pushButton_88" || name == "pushButton_95"
                || name == "pushButton_102" || name == "pushButton_117" || name == "pushButton_125"|| name == "pushButton_126" || name == "pushButton_129"
               || name == "pushButton_132"||name == "pushButton_160" ||name == "pushButton_206" ||name == "pushButton_211" ) {
        ui->stackedWidget->setCurrentWidget(ui->page);
    }
    //Camera Page
    else if (name == "pushButton_3"|| name == "pushButton_9"|| name == "pushButton_16" || name == "pushButton_25" || name == "pushButton_83" || name == "pushButton_90"
             || name == "pushButton_97"|| name == "pushButton_104"|| name == "pushButton_114" || name == "pushButton_118" || name == "pushButton_124"
             || name == "pushButton_136" || name == "pushButton_138" || name == "pushButton_141" || name == "pushButton_135" || name == "pushButton_147"
             || name == "pushButton_148" || name == "pushButton_149" || name == "pushButton_151" || name == "pushButton_152" || name == "pushButton_153" || name == "pushButton_154"
             ||name == "pushButton_209" ||name == "pushButton_133") {
        ui->stackedWidget->setCurrentWidget(ui->page_7);
    }//Story Page
    else if (name == "pushButton_4"|| name == "pushButton_10"|| name == "pushButton_17" || name == "pushButton_26" || name == "pushButton_84" || name == "pushButton_91"
             || name == "pushButton_98" || name == "pushButton_105") {
        ui->stackedWidget->setCurrentWidget(ui->page_5);
    }
    //User Profile
    else if (name == "pushButton_5"|| name == "pushButton_11"|| name == "pushButton_18" || name == "pushButton_22"|| name == "pushButton_27" || name == "pushButton_85"
             || name == "pushButton_92" || name == "pushButton_99" || name == "pushButton_106" || name == "pushButton_79" || name == "pushButton_86") {
        ui->stackedWidget->setCurrentWidget(ui->page_3);
    }
    //LikesPage
    else if (name == "pushButton_12 "||name == "pushButton_13"||name == "pushButton_20") {
        ui->stackedWidget->setCurrentWidget(ui->page_2);
    }
    //Pressing Message from homepage
    else if (name == "pushButton_37" ||name == "pushButton_67" ||name == "pushButton_161" ||name == "pushButton_163" ||name == "pushButton_181") {
        ui->stackedWidget->setCurrentWidget(ui->page_8);
    }
    //Pressing Sort
    else if (name == "pushButton_29" ||name == "pushButton_53" ||name == "pushButton_157") {
        ui->stackedWidget->setCurrentWidget(ui->page_9);
    }
    //Pressing Edit
    else if (name == "pushButton_30"||name == "pushButton_158") {
        ui->stackedWidget->setCurrentWidget(ui->page_13);
    }
    //Pressing Unread
    else if (name == "pushButton_31" ||name == "pushButton_46" ||name == "pushButton_49" ||name == "pushButton_52" ||name == "pushButton_54" ||name == "pushButton_70"
             ||name == "pushButton_159" ||name == "pushButton_166" ||name == "pushButton_180") {
        ui->stackedWidget->setCurrentWidget(ui->page_14);
    }
    //Pressing Alphabet
    else if (name == "pushButton_32" ||name == "pushButton_55" ||name == "pushButton_59" ||name == "pushButton_63" ||name == "pushButton_182" ||name == "pushButton_183"
             ||name == "pushButton_193" ||name == "pushButton_199" ||name == "pushButton_221") {
        ui->stackedWidget->setCurrentWidget(ui->page_10);
    }
    //Pressing Recent
    else if (name == "pushButton_33" ||name == "pushButton_56" ||name == "pushButton_60" ||name == "pushButton_64" ||name == "pushButton_179" ||name == "pushButton_222") {
        ui->stackedWidget->setCurrentWidget(ui->page_11);
    }
    //Pressing Favourites
    else if (name == "pushButton_34" ||name == "pushButton_57" ||name == "pushButton_61" ||name == "pushButton_65" ||name == "pushButton_165" ||name == "pushButton_197"
             ||name == "pushButton_223") {
        ui->stackedWidget->setCurrentWidget(ui->page_12);
    }
    //Alphabetic Edit
    else if (name == "pushButton_45" ||name == "pushButton_68") {
        ui->stackedWidget->setCurrentWidget(ui->page_16);
    }
    //Alphabetic Sort
    else if (name == "pushButton_44" ||name == "pushButton_69" ||name == "pushButton_171" ||name == "pushButton_171") {
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
    else if (name == "pushButton_2" || name == "pushButton_15" || name == "pushButton_82" || name == "pushButton_89" || name == "pushButton_96" || name == "pushButton_103"){
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

    //Ruffle's Following page
    }else if (name == "pushButton_80" || name == "pushButton_108" ||  name == "pushButton_112"){
        ui->stackedWidget->setCurrentWidget(ui->page_25);
    }
    //Ruffle's Follower page
    else if (name == "pushButton_87" || name == "pushButton_107"|| name == "pushButton_111"){
        ui->stackedWidget->setCurrentWidget(ui->page_24);
    }
    //Sabansoke's Following page
    else if (name == "pushButton_110" || name == "pushButton_94"){
        ui->stackedWidget->setCurrentWidget(ui->page_27);
    }
    //Sabansoke's Follower page
    else if (name == "pushButton_10" || name == "pushButton_109"|| name == "pushButton_101"){
        ui->stackedWidget->setCurrentWidget(ui->page_26);
    }
    //Pop effects
    else if (name == "pushButton_113" || name == "pushButton_122"){
        ui->stackedWidget->setCurrentWidget(ui->page_28);
    }
    //Photo effects
    else if (name == "pushButton_116" || name == "pushButton_119"){
        ui->stackedWidget->setCurrentWidget(ui->page_30);
    }
    //Art Deco effects
    else if (name == "pushButton_123" ){
        ui->stackedWidget->setCurrentWidget(ui->page_29);
    }
    //Art Deco filter page
    else if (name == "pushButton_120" || name == "pushButton_130"|| name == "pushButton_137"|| name == "pushButton_139"||
             name == "pushButton_142" || name == "pushButton_143" || name == "pushButton_144" || name == "pushButton_145"
             ||name == "pushButton_210" ||name == "pushButton_205" ||name == "pushButton_213" ||name == "pushButton_214" ||name == "pushButton_140"){
        ui->stackedWidget->setCurrentWidget(ui->page_31);
    }
    //Basic User library
    else if (name == "pushButton_115" || name == "pushButton_121" || name == "pushButton_146" || name == "pushButton_150"){
        ui->stackedWidget->setCurrentWidget(ui->page_33);
    }
    //Art deco background user library
    else if (name == "pushButton_128" || name == "pushButton_131" || name == "pushButton_204" || name == "pushButton_212"){
        ui->stackedWidget->setCurrentWidget(ui->page_34);
    }
    //Art deco background filter choose
    else if (name == "pushButton_127" ||name == "pushButton_202"){
        ui->stackedWidget->setCurrentWidget(ui->page_32);
    }
    //Dialog
    else if (name == "pushButton_164" ||name == "pushButton_167" ||name == "pushButton_168" ||name == "pushButton_169" ||name == "pushButton_170"
             ||name == "pushButton_171" ||name == "pushButton_172" ||name == "pushButton_173" ||name == "pushButton_174" ||name == "pushButton_175"
             ||name == "pushButton_176" ||name == "pushButton_177" ||name == "pushButton_178" ||name == "pushButton_198" ||name == "pushButton_201"
             ||name == "pushButton_215" ||name == "pushButton_216" ||name == "pushButton_217" ||name == "pushButton_218" ||name == "pushButton_219"
             ||name == "pushButton_220" ||name == "pushButton_224"  ||name == "pushButton_225" ){
        ui->stackedWidget->setCurrentWidget(ui->page_36);
    }
    //Dialog keyboard
    else if (name == "pushButton_162"||name == "pushButton_196"){
        ui->stackedWidget->setCurrentWidget(ui->page_37);
    }
    //No result
    else if (name == "pushButton_184" ||name == "pushButton_185" ||name == "pushButton_186" ||name == "pushButton_187" ||name == "pushButton_188"
             ||name == "pushButton_189" ||name == "pushButton_190" ||name == "pushButton_191" ||name == "pushButton_192"){
        ui->stackedWidget->setCurrentWidget(ui->page_35);
    }
    else if (name == "pushButton_194"){
        ui->stackedWidget->setCurrentWidget(ui->page_39);
    }
    else if (name == "pushButton_195" ||name == "pushButton_200"){
        ui->stackedWidget->setCurrentWidget(ui->page_38);
    }
    else if (name == "pushButton_203"){
        ui->stackedWidget->setCurrentWidget(ui->page_41);
    }
    else if (name == "pushButton_208"  ||name == "pushButton_207"){
        ui->stackedWidget->setCurrentWidget(ui->page_40);
    }


}


