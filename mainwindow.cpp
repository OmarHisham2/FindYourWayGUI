#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include "globals.h"



int money = 100;

bool plus6=false;
bool minus5=false;
bool plus10=false;
bool minus20=false;
bool plus7=false;
bool rightgreen= false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * output = new QAudioOutput();
    music->setAudioOutput(output);
    output->setVolume(0.2);
    music->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/music/backgroundgame.mp3"));
    music->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menustart_button_pressed()
{
    music->setAudioOutput(musicoutput);
    musicoutput->setVolume(0.8);
    music->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/Select.mp3"));
    music->play();
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_easy_button_pressed()
{
    music->setAudioOutput(musicoutput);
    musicoutput->setVolume(0.8);
    music->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/Select.mp3"));
    music->play();
    ui->stackedWidget->setCurrentIndex(2);
    ui->finishButton->setEnabled(false);

}


void MainWindow::on_startgame_button_pressed()
{
    ui->plus_6->setEnabled(true);
    ui->minus_5->setEnabled(true);
    ui->plus_10->setEnabled(true);
    ui->startgame_button->setEnabled(false);
 QPixmap greenvertical("E:/DS Project Stuff/Images/vwgreen.png");
 QPixmap greenleft("E:/DS Project Stuff/Images/vw3leftgreen.png");
 QPixmap greenright("E:/DS Project Stuff/Images/vw3rightgreen.png");
    ui->line10->setPixmap(greenleft);
    ui->line11->setPixmap(greenvertical);
    ui->line12->setPixmap(greenright);
    levelButtons->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    levelButtons->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/startgame.mp3"));
    levelButtons->play();
}

void MainWindow::on_plus_6_pressed()
{
    ui->plus_6->setEnabled(false);
    ui->plus_10->setEnabled(false);
    ui->minus_5->setEnabled(false);
    ui->minus_9->setEnabled(true);
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));
    buttonsfx->play();
    money += 6;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)));
    QPixmap normalvertical("E:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("E:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("E:/DS Project Stuff/Images/vw3right.png");
     QPixmap greenright("E:/DS Project Stuff/Images/vw3rightgreen.png");
    ui->line10->setPixmap(normalleft);
    ui->line11->setPixmap(normalvertical);
    ui->line12->setPixmap(normalright);
    ui->line1->setPixmap(greenright);
    plus6=true;


}


void MainWindow::on_minus_5_pressed()
{
    ui->plus_6->setEnabled(false);
    ui->plus_10->setEnabled(false);
    ui->minus_5->setEnabled(false);
    ui->minus_9->setEnabled(true);
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));
    buttonsfx->play();
    money -= 5;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("E:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("E:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("E:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenvertical("E:/DS Project Stuff/Images/vwgreen.png");
    ui->line10->setPixmap(normalleft);
    ui->line11->setPixmap(normalvertical);
    ui->line12->setPixmap(normalright);
    ui->line2->setPixmap(greenvertical);
    minus5=true;
}


void MainWindow::on_plus_10_pressed()
{
    ui->plus_6->setEnabled(false);
    ui->plus_10->setEnabled(false);
    ui->minus_5->setEnabled(false);
    ui->minus_9->setEnabled(true);
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));
    buttonsfx->play();
    money += 10;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("E:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("E:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("E:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenleft("E:/DS Project Stuff/Images/vw3leftgreen.png");
    ui->line10->setPixmap(normalleft);
    ui->line11->setPixmap(normalvertical);
    ui->line12->setPixmap(normalright);
    ui->line3->setPixmap(greenleft);
     plus10=true;
}


void MainWindow::on_minus_9_pressed()
{
    ui->minus_9->setEnabled(false);
    ui->plus_7->setEnabled(true);
    ui->minus_20->setEnabled(true);
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));
    buttonsfx->play();
    money -= 9;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("E:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("E:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("E:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenleft("E:/DS Project Stuff/Images/vw3leftgreen.png");
    QPixmap greenright("E:/DS Project Stuff/Images/vw3rightgreen.png");
    if(plus6){ui->line1->setPixmap(normalright);}
    else if(minus5){ui->line2->setPixmap(normalvertical);}
    else if(plus10){ui->line3->setPixmap(normalleft);}
    ui->line4->setPixmap(greenleft);
    ui->line5->setPixmap(greenright);
}


void MainWindow::on_plus_7_pressed()
{    ui->finishButton->setEnabled(true);
     buttonsfx->setAudioOutput(leveloutput);
     leveloutput->setVolume(0.8);
     buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));
     buttonsfx->play();
      money += 7;
      ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
       QPixmap greenarrowright("E:/DS Project Stuff/Images/vw3arrowgreen.png");
        QPixmap normalarrowleft("E:/DS Project Stuff/Images/vw3arrowleft.png");
         QPixmap greenright("E:/DS Project Stuff/Images/vw3rightgreen.png");
          QPixmap normalleft("E:/DS Project Stuff/Images/vw3left.png");
           QPixmap normalright("E:/DS Project Stuff/Images/vw3right.png");
          ui->line4->setPixmap(normalleft);
          ui->line5->setPixmap(normalright);
        plus7=true;
           if(minus20)
           {
               ui->line6->setPixmap(normalarrowleft);
               ui->line9->setPixmap(normalleft);
           }
            ui->line7->setPixmap(greenarrowright);
            ui->line8->setPixmap(greenright);
             ui->minus_20->setEnabled(true);
              ui->plus_7->setEnabled(false);
}


void MainWindow::on_minus_20_pressed()
{
    ui->finishButton->setEnabled(true);
         buttonsfx->setAudioOutput(leveloutput);
         leveloutput->setVolume(0.8);
         buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));
         buttonsfx->play();
         money -= 20;
         ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
         QPixmap greenarrowleft("E:/DS Project Stuff/Images/vw3arrowleftgreen.png");
          QPixmap greenleft("E:/DS Project Stuff/Images/vw3leftgreen.png");
          QPixmap normalarrowright("E:/DS Project Stuff/Images/vw3arrow.png");
          QPixmap normalright("E:/DS Project Stuff/Images/vw3right.png");
          QPixmap normalleft("E:/DS Project Stuff/Images/vw3left.png");
          ui->line4->setPixmap(normalleft);
          ui->line5->setPixmap(normalright);
          if(plus7)
          {
              ui->line7->setPixmap(normalarrowright);
              ui->line8->setPixmap(normalright);
          }
         ui->line6->setPixmap(greenarrowleft);
         ui->line9->setPixmap(greenleft);
         minus20=true;
         ui->minus_20->setEnabled(false);
         ui->plus_7->setEnabled(true);
}



void MainWindow::setStars()
{
    if(money >= 70)
    {
        QPixmap greenstar("E:/DS Project Stuff/Images/stargreen.png");
        ui->star1->setPixmap(greenstar);
        ui->star2->setPixmap(greenstar);
        ui->star3->setPixmap(greenstar);
    }
    else if ((money < 70) && (money > 40))
    {
        QPixmap greenstar("E:/DS Project Stuff/Images/stargreen.png");
        ui->star1->setPixmap(greenstar);
        ui->star2->setPixmap(greenstar);
    }
    else if ( money < 40 && money >= 0)
    {
        QPixmap greenstar("E:/DS Project Stuff/Images/stargreen.png");
        ui->star1->setPixmap(greenstar);
    }
}

void MainWindow::on_finishButton_pressed()
{

    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/finish.mp3"));
    buttonsfx->play();
    setStars();
    ui->finishButton->setEnabled(false);
    ui->minus_20->setEnabled(false);
    ui->plus_7->setEnabled(false);

    QPixmap normalarrowright("E:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap normalright("E:/DS Project Stuff/Images/vw3right.png");
    QPixmap normalleft("E:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalarrowleft("E:/DS Project Stuff/Images/vw3arrowleft.png");
    QPixmap normalvertical("E:/DS Project Stuff/Images/vw.png");
    ui->line1->setPixmap(normalright);
    ui->line2->setPixmap(normalvertical);
    ui->line3->setPixmap(normalleft);
    ui->line6->setPixmap(normalarrowleft);
    ui->line7->setPixmap(normalarrowright);
    ui->line8->setPixmap(normalright);
    ui->line9->setPixmap(normalleft);
    ui->stackedWidget->setCurrentIndex(3);
    if(money < 0)
    {
        ui->stackedWidget->setCurrentIndex(3);
        ui->winner_label->setText("You Lose");
        ui->nextLevel_button->setEnabled(false);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
}


void MainWindow::on_retry_button_pressed()
{

    music->setAudioOutput(musicoutput);
    musicoutput->setVolume(0.8);
    music->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/Select.mp3"));
    music->play();
    money=100;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_return_button_pressed()
{
    music->setAudioOutput(musicoutput);
    musicoutput->setVolume(0.8);
    music->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/Select.mp3"));
    music->play();
    money=100;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_menuexit_button_pressed()
{
    this->close();
}

