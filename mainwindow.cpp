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


QString make_number_main(int x){
    return QString::number(-x);
}


// construct graph




int money = 999;
int E_weight0_1,E_weight0_2,E_weight0_3,E_weight1_3,E_weight2_3,E_weight3_4,E_weight3_5,E_weight4_5,E_weight5_4;
int t4_1,t4_2,t4_3;


bool easy=0,med=0,seed=0,hard=0;
long int easy_seed;


extern long int med_seed;
bool ebut4;
extern long int insane_seed;

int is4 = 3;

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

    //addiding code for retry logic
        hard = 0;
        easy = true;
        med = 0;
        //end of retry


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
//    if ( money <= 0 )
//    {
//        valid = true;
//    }
//    else{
//        valid = true; //changed here

//    }

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

   //weight4=t4_2;
   // ui->button_4->setText(QString(" ").append(QString::number(weight4)));
}


void MainWindow::on_button_3_pressed()
{
    is4 = 3;
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
    money -= E_weight1_3;
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
    if(is4 == 3)
    {
        money -= E_weight3_4;
    }else if(is4 == 5)
    {
        money -= E_weight5_4;
    }
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );
    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap greenarrowright("D:/DS Project Stuff/Images/vw3arrowgreen.png");
    QPixmap normalarrowleft("D:/DS Project Stuff/Images/vw3arrowleft.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");

    ui->line1->setPixmap(normalright);
    ui->line3->setPixmap(normalleft);
    ui->line11->setPixmap(normalvertical);
    ui->line7->setPixmap(greenarrowright);
    ui->line8->setPixmap(greenright);
    ui->line4->setPixmap(normalleft);
    ui->line5->setPixmap(normalright);
    ui->line9->setPixmap(normalleft);
    ui->line6->setPixmap(normalarrowleft);
}


void MainWindow::on_button_5_pressed()
{
    is4 = 5;
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
         money -= E_weight4_5;
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
          ui->line6->setPixmap(normalarrowleft);
          ui->line9->setPixmap(normalleft);



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
    if(money >= 10)
    {
        QPixmap greenstar("D:/DS Project Stuff/Images/stargreen.png");
        ui->star1->setPixmap(greenstar);
        ui->star2->setPixmap(greenstar);
        ui->star3->setPixmap(greenstar);
    }
    else if ((money > 0) && (money < 10))
    {
        QPixmap greenstar("D:/DS Project Stuff/Images/stargreen.png");
        ui->star1->setPixmap(greenstar);
        ui->star2->setPixmap(greenstar);
    }
    else if (money >= 0)
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

    if(easy && !med && !hard){
        ui->stackedWidget->setCurrentIndex(2);

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
        graphEasy.generateRandomWeights(easy_seed);
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

        ui->finishButton->setEnabled(false);
        ui->money_label->setText(QString("Money : ").append(QString::number(money)));

    }else if (med && !hard && !easy){
        ui->stackedWidget->setCurrentIndex(4);
        vector<Edge> edges_med = { {0,1},{0,2},{1,4},{1,5},{2,1},{2,3},{2,4},{3,6},{3,8},
             {4,7},{4,8},{5,3},{5,7},{6,9},{7,8},{7,11},{8,9},{9,5},
             {9,10},{10,12},{11,10},{11,13},{12,13}
         };
        Graph med_graph(edges_med,14);

        //med graph ********************************************************
        ui->M_finishButton->setEnabled(0);
        long int num = med_graph.generateRandomWeights(med_seed);
        ui->M_seed_label->setText(make_number_main(-num));
        med_graph.printGraph();
        money = med_graph.BellmanFordSP(0,13);
        ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
        ui->M_weight0_1->setText(make_number_main(med_graph.get_weight(0,1)));
        ui->M_weight0_2->setText(make_number_main(med_graph.get_weight(0,2)));
        ui->M_weight1_4->setText(make_number_main(med_graph.get_weight(1,4)));
        ui->M_weight1_5->setText(make_number_main(med_graph.get_weight(1,5)));
        ui->M_weight2_1->setText(make_number_main(med_graph.get_weight(2,1)));
        ui->M_weight2_3->setText(make_number_main(med_graph.get_weight(2,3)));
        ui->M_weight2_4->setText(make_number_main(med_graph.get_weight(2,4)));
        ui->M_weight3_6->setText(make_number_main(med_graph.get_weight(3,6)));
        ui->M_weight3_8->setText(make_number_main(med_graph.get_weight(3,8)));
        ui->M_weight4_7->setText(make_number_main(med_graph.get_weight(4,7)));
        ui->M_weight4_8->setText(make_number_main(med_graph.get_weight(4,8)));
        ui->M_weight5_3->setText(make_number_main(med_graph.get_weight(5,3)));
        ui->M_weight5_7->setText(make_number_main(med_graph.get_weight(5,7)));
        ui->M_weight6_9->setText(make_number_main(med_graph.get_weight(6,9)));
        ui->M_weight7_8->setText(make_number_main(med_graph.get_weight(7,8)));
        ui->M_weight7_11->setText(make_number_main(med_graph.get_weight(7,11)));
        ui->M_weight8_9->setText(make_number_main(med_graph.get_weight(8,9)));
        ui->M_weight9_5->setText(make_number_main(med_graph.get_weight(9,5)));
        ui->M_weight9_10->setText(make_number_main(med_graph.get_weight(9,10)));
        ui->M_weight10_12->setText(make_number_main(med_graph.get_weight(10,12)));
        ui->M_weight11_10->setText(make_number_main(med_graph.get_weight(11,10)));
        ui->M_weight11_13->setText(make_number_main(med_graph.get_weight(11,13)));
        ui->M_weight12_13->setText(make_number_main(med_graph.get_weight(12,13)));


    }else if (seed){

    }else if(hard && !med && !easy)
    {
        vector<Edge> Insane_edges = { {0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{4,6},{3,7},{7,2},
             {7,6},{7,8},{8,1},{0,13},{13,14},{13,12},{12,11},{11,10},{9,10},
             {8,9},{14,15},{15,21},{21,10},{20,10},{21,20},{16,20},{10,16},
             {16,9},{7,16},{6,17},{16,17},{17,18},{17,19},{19,22},{18,19},{10,15}
         };
        Graph Insane_graph(Insane_edges, 23);
        ui->I_finishButton->setEnabled(0);
        ui->stackedWidget->setCurrentIndex(5);
        cout<<"\n insane seed from main window = "<<insane_seed;
        Insane_graph.generateRandomWeights(insane_seed);
        Insane_graph.printGraph();
        money = Insane_graph.BellmanFordSP(0,22);
        cout<<"\nmoney= "<<money;
        ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));


        ui->I_weight0_1->setText(make_number_main(Insane_graph.get_weight(0,1)));
        ui->I_weight1_2->setText(make_number_main(Insane_graph.get_weight(1,2)));
        ui->I_weight2_3->setText(make_number_main(Insane_graph.get_weight(2,3)));
        ui->I_weight3_4->setText(make_number_main(Insane_graph.get_weight(3,4)));
        ui->I_weight4_5->setText(make_number_main(Insane_graph.get_weight(4,5)));
        ui->I_weight5_6->setText(make_number_main(Insane_graph.get_weight(5,6)));
        ui->I_weight4_6->setText(make_number_main(Insane_graph.get_weight(4,6)));
        ui->I_weight3_7->setText(make_number_main(Insane_graph.get_weight(3,7)));
        ui->I_weight7_2->setText(make_number_main(Insane_graph.get_weight(7,2)));
        ui->I_weight7_6->setText(make_number_main(Insane_graph.get_weight(7,6)));
        ui->I_weight7_8->setText(make_number_main(Insane_graph.get_weight(7,8)));
        ui->I_weight8_1->setText(make_number_main(Insane_graph.get_weight(8,1)));
        ui->I_weight0_13->setText(make_number_main(Insane_graph.get_weight(0,13)));
        ui->I_weight13_14->setText(make_number_main(Insane_graph.get_weight(13,14)));
        ui->I_weight13_12->setText(make_number_main(Insane_graph.get_weight(13,12)));
        ui->I_weight12_11->setText(make_number_main(Insane_graph.get_weight(12,11)));
        ui->I_weight11_10->setText(make_number_main(Insane_graph.get_weight(11,10)));
        ui->I_weight9_10->setText(make_number_main(Insane_graph.get_weight(9,10)));
        ui->I_weight8_9->setText(make_number_main(Insane_graph.get_weight(8,9)));
        ui->I_weight14_15->setText(make_number_main(Insane_graph.get_weight(14,15)));
        ui->I_weight15_21->setText(make_number_main(Insane_graph.get_weight(15,21)));
        ui->I_weight21_10->setText(make_number_main(Insane_graph.get_weight(21,10)));
        ui->I_weight20_10->setText(make_number_main(Insane_graph.get_weight(20,10)));
        ui->I_weight21_20->setText(make_number_main(Insane_graph.get_weight(21,20)));
        ui->I_weight16_20->setText(make_number_main(Insane_graph.get_weight(16,20)));
        ui->I_weight10_16->setText(make_number_main(Insane_graph.get_weight(10,16)));
        ui->I_weight16_9->setText(make_number_main(Insane_graph.get_weight(16,9)));
        ui->I_weight7_16->setText(make_number_main(Insane_graph.get_weight(7,16)));
        ui->I_weight6_17->setText(make_number_main(Insane_graph.get_weight(6,17)));
        ui->I_weight16_17->setText(make_number_main(Insane_graph.get_weight(16,17)));
        ui->I_weight17_18->setText(make_number_main(Insane_graph.get_weight(17,18)));
        ui->I_weight17_19->setText(make_number_main(Insane_graph.get_weight(17,19)));
        ui->I_weight19_22->setText(make_number_main(Insane_graph.get_weight(19,22)));
        ui->I_weight18_19->setText(make_number_main(Insane_graph.get_weight(18,19)));
        ui->I_weight10_15->setText(make_number_main(Insane_graph.get_weight(10,15)));

        ui->I_weight0_1->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight1_2->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight2_3->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight3_4->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight4_5->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight5_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight4_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight3_7->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight8_1->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight0_13->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight13_14->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight13_12->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight12_11->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight11_10->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight9_10->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight8_9->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight14_15->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight15_21->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight21_10->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight20_10->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight21_20->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_20->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight10_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_9->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight6_17->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_17->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight17_18->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight17_19->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight19_22->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight18_19->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight10_15->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_startgame_button->setEnabled(true);
    }

    music->setAudioOutput(musicoutput);
    musicoutput->setVolume(0.8);
    music->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/Select.mp3"));
    music->play();
   // money=100; mnk llah ya omar
    ui->money_label->setText(QString("Money : ").append(QString::number(money)) );



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





void MainWindow::on_insane_button_pressed()
{

}


void MainWindow::on_I_startgame_button_2_pressed()
{

}


void MainWindow::on_nextLevel_button_pressed()
{
    if(easy && !hard && !med)
    {
        on_medium_button_pressed();
    }else if(med && !hard && !easy)
    {
        on_hard_button_pressed();
    }else if(hard && !easy && !med)
    {
        on_easy_button_pressed();
    }
}

