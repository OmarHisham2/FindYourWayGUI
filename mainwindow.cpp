#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include "globals.h"
#include <iostream>
#include <vector>
#include "Graph.h"
#include <queue>
#include <list>


// construct graph




int money = 999;
int weight1,weight2,weight3,weight4,weight5,weight6;









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

    bool valid = false;
    while(!valid)
    {
    vector<Edge> edges;
    edges.push_back({ 0, 1, 5 });
    edges.push_back({ 0, 2, 7});
    edges.push_back({ 0, 3, 2});
    edges.push_back({ 1, 3, -2});
    edges.push_back({ 2, 3, -1});
    edges.push_back({ 3, 4, 3});
    edges.push_back({ 3, 5, 8});
    edges.push_back({ 4, 5, 1});
    edges.push_back({ 5, 4, -1});


    // construct graph
    Graph graphEasy(edges, 6);
    graphEasy.generateRandomWeights();

     weight1 =graphEasy.adjList[0].front().second;
     weight2 =graphEasy.adjList[1].front().second;
     weight3 =graphEasy.adjList[2].front().second;
     weight4 =graphEasy.adjList[3].front().second;
     weight5 =graphEasy.adjList[4].front().second;
     weight6 =graphEasy.adjList[5].front().second;

    money = graphEasy.BellmanFordSP(0, graphEasy.nodes_count() - 1);

    if ( money <= 0 )
    {
        valid = false;
    }
    else
        valid = true;

    }

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
    ui->money_label->setText(QString("Money : ").append(QString::number(money)));
    ui->button_1->setText(QString(" ").append(QString::number(weight1)));
    ui->button_2->setText(QString(" ").append(QString::number(weight2)));
    ui->button_3->setText(QString(" ").append(QString::number(weight3)));
    ui->button_4->setText(QString(" ").append(QString::number(weight4)));
    ui->button_5->setText(QString(" ").append(QString::number(weight5)));
    ui->button_6->setText(QString(" ").append(QString::number(weight6)));

}


void MainWindow::on_startgame_button_pressed()
{
    ui->button_1->setEnabled(true);
    ui->button_2->setEnabled(true);
    ui->button_3->setEnabled(true);
    ui->startgame_button->setEnabled(false);
 QPixmap greenvertical("D:/DS Project Stuff/Images/vwgreen.png");
 QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");
 QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
    ui->line10->setPixmap(greenleft);
    ui->line11->setPixmap(greenvertical);
    ui->line12->setPixmap(greenright);
    levelButtons->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    levelButtons->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/startgame.mp3"));
    levelButtons->play();
}

void MainWindow::on_button_1_pressed()
{
    ui->button_1->setEnabled(false);
    ui->button_3->setEnabled(false);
    ui->button_2->setEnabled(false);
    ui->button_4->setEnabled(true);
    if (weight1 >= 0)
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
        else
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));
    buttonsfx->play();
    money += weight1;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)));
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
     QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
    ui->line10->setPixmap(normalleft);
    ui->line11->setPixmap(normalvertical);
    ui->line12->setPixmap(normalright);
    ui->line1->setPixmap(greenright);
    plus6=true;


}


void MainWindow::on_button_2_pressed()
{
    ui->button_1->setEnabled(false);
    ui->button_3->setEnabled(false);
    ui->button_2->setEnabled(false);
    ui->button_4->setEnabled(true);
    if (weight2 >= 0)
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
        else
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->play();
    money += weight2;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenvertical("D:/DS Project Stuff/Images/vwgreen.png");
    ui->line10->setPixmap(normalleft);
    ui->line11->setPixmap(normalvertical);
    ui->line12->setPixmap(normalright);
    ui->line2->setPixmap(greenvertical);
    minus5=true;
}


void MainWindow::on_button_3_pressed()
{
    if (weight3 >= 0)
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
        else
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
    ui->button_1->setEnabled(false);
    ui->button_3->setEnabled(false);
    ui->button_2->setEnabled(false);
    ui->button_4->setEnabled(true);
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->play();
    money += weight3;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");
    ui->line10->setPixmap(normalleft);
    ui->line11->setPixmap(normalvertical);
    ui->line12->setPixmap(normalright);
    ui->line3->setPixmap(greenleft);
     plus10=true;
}


void MainWindow::on_button_4_pressed()
{
    if (weight4 >= 0)
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
        else
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
    ui->button_4->setEnabled(false);
    ui->button_5->setEnabled(true);
    ui->button_6->setEnabled(true);
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->play();
    money += weight4;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");
    QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
    if(plus6){ui->line1->setPixmap(normalright);}
    else if(minus5){ui->line2->setPixmap(normalvertical);}
    else if(plus10){ui->line3->setPixmap(normalleft);}
    ui->line4->setPixmap(greenleft);
    ui->line5->setPixmap(greenright);
}


void MainWindow::on_button_5_pressed()
{    ui->finishButton->setEnabled(true);

     if (weight5 >= 0)
     {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
         else
     {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
     buttonsfx->setAudioOutput(leveloutput);
     leveloutput->setVolume(0.8);

     buttonsfx->play();
      money += weight5;
      ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
       QPixmap greenarrowright("D:/DS Project Stuff/Images/vw3arrowgreen.png");
        QPixmap normalarrowleft("D:/DS Project Stuff/Images/vw3arrowleft.png");
         QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
          QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
           QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
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
             ui->button_6->setEnabled(true);
              ui->button_5->setEnabled(false);
}


void MainWindow::on_button_6_pressed()
{
    ui->finishButton->setEnabled(true);
    if (weight1 >= 0)
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
        else
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
         buttonsfx->setAudioOutput(leveloutput);
         leveloutput->setVolume(0.8);
         buttonsfx->play();
         money += weight6;
         ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
         QPixmap greenarrowleft("D:/DS Project Stuff/Images/vw3arrowleftgreen.png");
          QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");
          QPixmap normalarrowright("D:/DS Project Stuff/Images/vw3arrow.png");
          QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
          QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
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
         ui->button_6->setEnabled(false);
         ui->button_5->setEnabled(true);
}



void MainWindow::setStars()
{
    if(money >= 70)
    {
        QPixmap greenstar("D:/DS Project Stuff/Images/stargreen.png");
        ui->star1->setPixmap(greenstar);
        ui->star2->setPixmap(greenstar);
        ui->star3->setPixmap(greenstar);
    }
    else if ((money < 70) && (money > 40))
    {
        QPixmap greenstar("D:/DS Project Stuff/Images/stargreen.png");
        ui->star1->setPixmap(greenstar);
        ui->star2->setPixmap(greenstar);
    }
    else if ( money < 40 && money >= 0)
    {
        QPixmap greenstar("D:/DS Project Stuff/Images/stargreen.png");
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
    ui->button_6->setEnabled(false);
    ui->button_5->setEnabled(false);

    QPixmap normalarrowright("D:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalarrowleft("D:/DS Project Stuff/Images/vw3arrowleft.png");
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
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

