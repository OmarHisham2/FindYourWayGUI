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



    void on_M_startgame_button_pressed();

    void on_M_button_1_pressed();

    void on_M_button_4_pressed();

    void on_M_button_5_pressed();

    void on_M_button_2_pressed();

    void on_M_button_3_pressed();



    void on_M_button_6_pressed();

    void on_M_button_7_pressed();

    void on_M_button_8_pressed();

    void on_M_button_9_pressed();

    void on_M_button_10_pressed();

    void on_M_button_11_pressed();

    void on_M_button_12_pressed();

    void on_M_finishButton_pressed();

    void on_M_copy_seed_pressed();

    void on_M_seed_button_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
