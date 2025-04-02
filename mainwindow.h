#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <deque>  // Required for dqueue
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    std::deque<int> previousPageIndex;
    Ui::MainWindow *ui;
    QTimer *scrollTimer;
    QVector<QPixmap> scrollImages , scrollImages2;
    QVector<QPixmap> originalImage;
    int scrollIndex = 0;
    int scrollDirection =0;
private slots:
    void handlePageChange();
    void onImageScroll();
    void onButtonPressed();
    void onButtonReleased();
};


#endif // MAINWINDOW_H
