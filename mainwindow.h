#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_startgame_button_pressed();

    void on_button_1_pressed();

    void on_button_2_pressed();

    void on_button_3_pressed();

    void on_button_4_pressed();

    void on_button_5_pressed();

    void on_menustart_button_pressed();

    void on_easy_button_pressed();

    void setStars();

    void on_finishButton_pressed();

    void on_retry_button_pressed();

    void on_return_button_pressed();

    void on_menuexit_button_pressed();

    void on_medium_button_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
