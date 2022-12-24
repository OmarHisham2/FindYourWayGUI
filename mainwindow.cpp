#pragma once
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
int E_weight0_1,E_weight0_2,E_weight0_3,E_weight1_3,E_weight2_3,E_weight3_4,E_weight3_5,E_weight4_5,E_weight5_4;
int t4_1,t4_2,t4_3;



bool ebut4;




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

// construct EASY graph END msh 3aref by3ml eh fa sebto

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * output = new QAudioOutput();
    music->setAudioOutput(output);
    output->setVolume(0.2);
    music->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/music/backgroundgame.mp3"));
    music->play();

// ---------------------------------------------






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


    bool valid = false;
    while(!valid)
    {
    vector<Edge> edges;
    edges.push_back({ 0, 1, });
    edges.push_back({ 0, 2, });
    edges.push_back({ 0, 3, });
    edges.push_back({ 1, 4, });
    edges.push_back({ 2, 4, });
    edges.push_back({ 3, 4, });
    edges.push_back({ 4, 5, });
    edges.push_back({ 4, 6, });
    edges.push_back({ 5, 6, });
    edges.push_back({ 6, 5, });



    Graph graphEasy(edges, 7);
    graphEasy.generateRandomWeights();
    auto j = graphEasy.adjList[0].begin();

    E_weight0_1= j->second;  j++;
    E_weight0_2= j->second;  j++;
    E_weight0_3= j->second;
    E_weight1_3 = (graphEasy.adjList[1].begin())->second;
    E_weight2_3 = (graphEasy.adjList[2].begin())->second;
    E_weight3_4 = (graphEasy.adjList[3].begin())->second;
    auto i = graphEasy.adjList[4].begin();
    E_weight4_5= i->second;  i++;
    E_weight5_4 = (graphEasy.adjList[5].begin())->second;
    money = graphEasy.BellmanFordSP(0, graphEasy.nodes_count() - 1);
    if ( money <= 0 )
    {
        valid = true;
    }
    else
        valid = true; //changed here

    }

    ui->label_1->setText(QString(" ").append(QString::number(-E_weight0_1)));
    ui->label_2->setText(QString(" ").append(QString::number(-E_weight0_3)));
    ui->label_3->setText(QString(" ").append(QString::number(-E_weight0_2)));
    ui->label_4->setText(QString(" ").append(QString::number(-E_weight1_3)));
    ui->label_5->setText(QString(" ").append(QString::number(-E_weight2_3)));
    ui->label_6->setText(QString(" ").append(QString::number(-E_weight3_4)));
    ui->label_7->setText(QString(" ").append(QString::number(-E_weight3_5)));
    ui->label_8->setText(QString(" ").append(QString::number(-E_weight5_4)));
    ui->label_9->setText(QString(" ").append(QString::number(-E_weight4_5)));





    music->setAudioOutput(musicoutput);
    musicoutput->setVolume(0.8);
    music->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/Select.mp3"));
    music->play();
    ui->stackedWidget->setCurrentIndex(2);
    ui->finishButton->setEnabled(false);
    ui->money_label->setText(QString("Money : ").append(QString::number(money)));

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
    ui->button_3->setEnabled(true);
    ui->button_2->setEnabled(false);
    if (E_weight0_1 >= 0)
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
        else
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));
    buttonsfx->play();
    money -= E_weight0_1;
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
   // weight4=t4_1;
    //ui->button_4->setText(QString(" ").append(QString::number(weight4)));

}


void MainWindow::on_button_2_pressed()
{
    ui->button_1->setEnabled(false);
    ui->button_3->setEnabled(true);
    ui->button_2->setEnabled(false);

    if (E_weight0_2 >= 0)
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
        else
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->play();
    money -= E_weight0_2;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");
    ui->line10->setPixmap(normalleft);
    ui->line11->setPixmap(normalvertical);
    ui->line12->setPixmap(normalright);
    ui->line3->setPixmap(greenleft);
    minus5=true;
   //weight4=t4_2;
   // ui->button_4->setText(QString(" ").append(QString::number(weight4)));
}


void MainWindow::on_button_3_pressed()
{
    if (E_weight0_3 >= 0)
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
        else
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
    ui->button_1->setEnabled(false);
    ui->button_3->setEnabled(false);
    ui->button_2->setEnabled(false);
    ui->button_4->setEnabled(true);
    ui->button_5->setEnabled(true);
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->play();
    money -= E_weight0_3;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
    QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");
    ui->line10->setPixmap(normalleft);
    ui->line11->setPixmap(normalvertical);
    ui->line12->setPixmap(normalright);
    ui->line3->setPixmap(normalleft);
    ui->line4->setPixmap(greenleft);
    ui->line5->setPixmap(greenright);
     plus10=true;
     //weight4=t4_3;
     //ui->button_4->setText(QString(" ").append(QString::number(weight4)));
}


void MainWindow::on_button_4_pressed()
{
    ebut4=1;
    if (E_weight3_4 >= 0)
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
        else
    {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
    ui->button_4->setEnabled(false);
    ui->button_5->setEnabled(true);
    ui->finishButton->setEnabled(true);
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->play();
    money -= E_weight3_4;
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap greenarrowright("D:/DS Project Stuff/Images/vw3arrowgreen.png");
    QPixmap normalarrowleft("D:/DS Project Stuff/Images/vw3arrowleft.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
    if(plus6){ui->line1->setPixmap(normalright);}
    else if(minus5){ui->line11->setPixmap(normalvertical);}
    else if(plus10){ui->line3->setPixmap(normalleft);}
    ui->line7->setPixmap(greenarrowright);
    ui->line8->setPixmap(greenright);
    ui->line4->setPixmap(normalleft);
    ui->line5->setPixmap(normalright);
    ui->line9->setPixmap(normalleft);
    ui->line6->setPixmap(normalarrowleft);
}


void MainWindow::on_button_5_pressed()
{

    ui->button_4->setEnabled(true);
    ui->finishButton->setEnabled(true);
     if (E_weight3_5 >= 0)
     {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/plus.mp3"));}
         else
     {buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/minus.mp3"));}
     buttonsfx->setAudioOutput(leveloutput);
     leveloutput->setVolume(0.8);

     buttonsfx->play();
     if(ebut4){
         money -= E_weight3_5;
     }else{
         money -= E_weight3_5;
     }
     ebut4=0;
      ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
       QPixmap greenarrowleft("D:/DS Project Stuff/Images/vw3arrowleftgreen.png");
        QPixmap normalarrowleft("D:/DS Project Stuff/Images/vw3arrowleft.png");
        QPixmap normalarrowright("D:/DS Project Stuff/Images/vw3arrow.png");
         QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");
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

             ui->finishButton->setEnabled(true);
              ui->button_5->setEnabled(false);
              ui->line4->setPixmap(normalleft);
              ui->line5->setPixmap(normalright);
              ui->line9->setPixmap(greenleft);
              ui->line6->setPixmap(greenarrowleft);
              ui->line8->setPixmap(normalright);
              ui->line7->setPixmap(normalarrowright);

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
  //  ui->button_6->setEnabled(false);
    ui->button_5->setEnabled(false);

    QPixmap normalarrowright("D:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalarrowleft("D:/DS Project Stuff/Images/vw3arrowleft.png");
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    ui->line1->setPixmap(normalright);
    ui->line11->setPixmap(normalvertical);
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
    //delete after test

//    ui->label_4->setText(QString(" ").append(QString::number(-weight1_4)));
//    ui->label_5->setText(QString(" ").append(QString::number(-E_weight0_2_4)));
//    ui->label_6->setText(QString(" ").append(QString::number(-E_weight0_3_4)));
//    ui->label_4->setText(QString(" ").append(QString::number(-weight6_5)));
//    ui->label_5->setText(QString(" ").append(QString::number(-weight5_6)));





//    music->setAudioOutput(musicoutput);
//    musicoutput->setVolume(0.8);
//    music->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/Select.mp3"));
//    music->play();
//    ui->stackedWidget->setCurrentIndex(2);
//    ui->finishButton->setEnabled(false);
//    ui->money_label->setText(QString("Money : ").append(QString::number(money)));
//    ui->button_1->setText(QString(" ").append(QString::number(-weight1)));
//    ui->button_2->setText(QString(" ").append(QString::number(-E_weight0_2)));
//    ui->button_3->setText(QString(" ").append(QString::number(-E_weight0_3)));

//    ui->button_5->setText(QString(" ").append(QString::number(-weight5)));
//    ui->button_6->setText(QString(" ").append(QString::number(-weight6)));













    // end of delete

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

//med graph *******************************************************




<<<<<<< Updated upstream
=======
void MainWindow::on_insane_button_pressed()
{

}


void MainWindow::on_I_startgame_button_2_pressed()
{

}


>>>>>>> Stashed changes
