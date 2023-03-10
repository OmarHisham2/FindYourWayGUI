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
#include <QClipboard>
#include <QMessageBox>
#include <QInputDialog>

//bool is5_or_6 = false;
int is5_4_or7 = 5;
int is1_or7 = 1;
int is0_or8 = 0;
int is8_or16 = 8;
int is9_11_20_or21 = 9;
int is14_or10 = 14;
int is10_or7 = 10;
int is6_or16 = 6;
int is17_or_18 = 17;
int is21_or16 = 21;

extern bool med,easy,seed,hard;
long int insane_seed, number;
vector<Edge> Insane_edges = { {0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{4,6},{3,7},{7,2},
     {7,6},{7,8},{8,1},{0,13},{13,14},{13,12},{12,11},{11,10},{9,10},
     {8,9},{14,15},{15,21},{21,10},{20,10},{21,20},{16,20},{10,16},
     {16,9},{7,16},{6,17},{16,17},{17,18},{17,19},{19,22},{18,19},{10,15}
 };

Graph Insane_graph(Insane_edges, 23);

QString make_Inumber(int x){
    return QString::number(-x);
}


void MainWindow::on_hard_button_pressed()
{   //addiding code for retry logic
    hard = true;
    easy = 0;
    med = 0;
    seed=0;
    //end of retry
    ui->stackedWidget->setCurrentIndex(5);

    number = Insane_graph.generateRandomWeights();
    insane_seed = number;
    cout<<"\n insane seed from insane level = "<<insane_seed;
    Insane_graph.printGraph();
    money = Insane_graph.BellmanFordSP(0,22);
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));

    ui->I_weight0_1->setText(make_Inumber(Insane_graph.get_weight(0,1)));
    ui->I_weight1_2->setText(make_Inumber(Insane_graph.get_weight(1,2)));
    ui->I_weight2_3->setText(make_Inumber(Insane_graph.get_weight(2,3)));
    ui->I_weight3_4->setText(make_Inumber(Insane_graph.get_weight(3,4)));
    ui->I_weight4_5->setText(make_Inumber(Insane_graph.get_weight(4,5)));
    ui->I_weight5_6->setText(make_Inumber(Insane_graph.get_weight(5,6)));
    ui->I_weight4_6->setText(make_Inumber(Insane_graph.get_weight(4,6)));
    ui->I_weight3_7->setText(make_Inumber(Insane_graph.get_weight(3,7)));
    ui->I_weight7_2->setText(make_Inumber(Insane_graph.get_weight(7,2)));
    ui->I_weight7_6->setText(make_Inumber(Insane_graph.get_weight(7,6)));
    ui->I_weight7_8->setText(make_Inumber(Insane_graph.get_weight(7,8)));
    ui->I_weight8_1->setText(make_Inumber(Insane_graph.get_weight(8,1)));
    ui->I_weight0_13->setText(make_Inumber(Insane_graph.get_weight(0,13)));
    ui->I_weight13_14->setText(make_Inumber(Insane_graph.get_weight(13,14)));
    ui->I_weight13_12->setText(make_Inumber(Insane_graph.get_weight(13,12)));
    ui->I_weight12_11->setText(make_Inumber(Insane_graph.get_weight(12,11)));
    ui->I_weight11_10->setText(make_Inumber(Insane_graph.get_weight(11,10)));
    ui->I_weight9_10->setText(make_Inumber(Insane_graph.get_weight(9,10)));
    ui->I_weight8_9->setText(make_Inumber(Insane_graph.get_weight(8,9)));
    ui->I_weight14_15->setText(make_Inumber(Insane_graph.get_weight(14,15)));
    ui->I_weight15_21->setText(make_Inumber(Insane_graph.get_weight(15,21)));
    ui->I_weight21_10->setText(make_Inumber(Insane_graph.get_weight(21,10)));
    ui->I_weight20_10->setText(make_Inumber(Insane_graph.get_weight(20,10)));
    ui->I_weight21_20->setText(make_Inumber(Insane_graph.get_weight(21,20)));
    ui->I_weight16_20->setText(make_Inumber(Insane_graph.get_weight(16,20)));
    ui->I_weight10_16->setText(make_Inumber(Insane_graph.get_weight(10,16)));
    ui->I_weight16_9->setText(make_Inumber(Insane_graph.get_weight(16,9)));
    ui->I_weight7_16->setText(make_Inumber(Insane_graph.get_weight(7,16)));
    ui->I_weight6_17->setText(make_Inumber(Insane_graph.get_weight(6,17)));
    ui->I_weight16_17->setText(make_Inumber(Insane_graph.get_weight(16,17)));
    ui->I_weight17_18->setText(make_Inumber(Insane_graph.get_weight(17,18)));
    ui->I_weight17_19->setText(make_Inumber(Insane_graph.get_weight(17,19)));
    ui->I_weight19_22->setText(make_Inumber(Insane_graph.get_weight(19,22)));
    ui->I_weight18_19->setText(make_Inumber(Insane_graph.get_weight(18,19)));
    ui->I_weight10_15->setText(make_Inumber(Insane_graph.get_weight(10,15)));
    ui->I_finishButton->setEnabled(0);

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




void MainWindow::on_I_startgame_button_pressed()
{
    QPixmap normalverticalGreen("D:/DS Project Stuff/Images/vwgreen.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");



    levelButtons->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    levelButtons->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/startgame.mp3"));
    levelButtons->play();
    //update_Ifrom(0);
    ui->I_button_1->setEnabled(true);
    ui->I_button_13->setEnabled(true);
    ui->I_startgame_button->setEnabled(0);
    ui->I_line0_13->setPixmap(upleftGreen);
    ui->I_line0_1->setPixmap(normalverticalGreen);
    ui->I_weight0_1->setStyleSheet("QLabel {color : #00FF00} ");
    ui->I_weight0_13->setStyleSheet("QLabel {color : #00FF00} ");
    is0_or8 = 0;
}




void MainWindow::on_I_button_1_pressed()
{

    QPixmap normalrightGreen("D:/DS Project Stuff/Images/vw3arrowgreen.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap downVertical("D:/DS Project Stuff/Images/vwdown.png");

    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");

    is1_or7 = 1;
    ui->I_button_2->setEnabled(true);
    ui->I_button_1->setEnabled(false);
    ui->I_button_13->setEnabled(false);
    ui->I_button_9->setEnabled(false);
    ui->I_weight1_2->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_line1_2->setPixmap(normalrightGreen);
    ui->I_weight0_13->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_line0_13->setPixmap(upleft);
    if(is0_or8 == 0)
    {
        ui->I_line0_1->setPixmap(normalvertical);
        ui->I_weight0_1->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(0,1);
    }else if(is0_or8 == 8)
    {
        ui->I_line8_9->setPixmap(upleft);
        ui->I_weight8_9->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_line8_1->setPixmap(downVertical);
        ui->I_weight8_1->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(8,1);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}


void MainWindow::on_I_button_13_pressed()
{

    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");


    QPixmap uprightGreen("D:/DS Project Stuff/Images/vw3rightgreen.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");

    ui->I_button_12->setEnabled(true);
    ui->I_button_14->setEnabled(true);
    ui->I_button_13->setEnabled(false);
    ui->I_button_1->setEnabled(false);
    ui->I_line13_12->setPixmap(uprightGreen);
    ui->I_line13_14->setPixmap(upleftGreen);
    ui->I_weight13_12->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight13_14->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_line0_1->setPixmap(normalvertical);
    ui->I_line0_13->setPixmap(upleft);
    ui->I_weight0_1->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight0_13->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    ui->I_button_13->setEnabled(false);
    money-= Insane_graph.get_weight(0,13);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}


void MainWindow::on_I_button_2_pressed()
{

    QPixmap downVertical("D:/DS Project Stuff/Images/vwdown.png");

    QPixmap normalright("D:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");
    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");

    QPixmap uprightGreen("D:/DS Project Stuff/Images/vw3rightgreen.png");


    ui->I_button_3->setEnabled(true);
    ui->I_button_2->setEnabled(false);
    ui->I_line2_3->setPixmap(uprightGreen);
    ui->I_weight2_3->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_button_13->setEnabled(false);
    if(is1_or7 == 1)
    {
        ui->I_line1_2->setPixmap(normalright);
        ui->I_weight1_2->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(1,2);
    }else if(is1_or7 == 7)
    {
        ui->I_button_16->setEnabled(false);
        ui->I_button_8->setEnabled(false);
        ui->I_button_6->setEnabled(false);
        ui->I_line7_6->setPixmap(upright);
        ui->I_line7_8->setPixmap(bottomleft);
        ui->I_line7_16->setPixmap(upleft);
        ui->I_line7_2->setPixmap(downVertical);

        ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(7,2);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}



void MainWindow::on_I_button_3_pressed()
{

    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");

    QPixmap normalverticalGreen("D:/DS Project Stuff/Images/vwgreen.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");

    ui->I_button_4->setEnabled(true);
    ui->I_button_7->setEnabled(true);
    ui->I_button_3->setEnabled(false);
    ui->I_line3_4->setPixmap(normalverticalGreen);
    ui->I_line3_7->setPixmap(upleftGreen);
    ui->I_line2_3->setPixmap(upright);

    ui->I_weight3_4->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight3_7->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight2_3->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(2,3);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}


void MainWindow::on_I_button_4_pressed()
{

    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalrightGreen("D:/DS Project Stuff/Images/vw3arrowgreen.png");
    QPixmap uprightGreen("D:/DS Project Stuff/Images/vw3rightgreen.png");


    ui->I_button_5->setEnabled(true);
    ui->I_button_6->setEnabled(true);
    ui->I_button_3->setEnabled(false);
    ui->I_button_7->setEnabled(false);
    ui->I_line4_5->setPixmap(normalrightGreen);
    ui->I_line4_6->setPixmap(uprightGreen);
    ui->I_line3_7->setPixmap(upleft);
    ui->I_line3_4->setPixmap(normalvertical);

    ui->I_weight4_5->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight4_6->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight3_7->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight3_4->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    ui->I_button_4->setEnabled(false);
    money-= Insane_graph.get_weight(3,4);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is5_4_or7 = 4;
}



void MainWindow::on_I_button_5_pressed()
{

    QPixmap normalright("D:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");

    ui->I_button_6->setEnabled(true);
    ui->I_button_4->setEnabled(false);
    ui->I_button_5->setEnabled(false);
    ui->I_line5_6->setPixmap(upleftGreen);
    ui->I_line4_6->setPixmap(upright);
    ui->I_line4_5->setPixmap(normalright);

    ui->I_weight5_6->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight4_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight4_5->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(4,5);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    //is5_or_6 = true;
    is5_4_or7 = 5;
}


void MainWindow::on_I_button_6_pressed()
{

    QPixmap downVertical("D:/DS Project Stuff/Images/vwdown.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");
    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");

    ui->I_button_17->setEnabled(true);
    ui->I_button_6->setEnabled(false);
    ui->I_line6_17->setPixmap(upleftGreen);
    ui->I_weight6_17->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    if(is5_4_or7 == 5)
    {
        ui->I_line4_6->setPixmap(upright);
        ui->I_line4_5->setPixmap(normalright);
        ui->I_line5_6->setPixmap(upleft);

        ui->I_weight4_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight4_5->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight5_6->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(5,6);
    }else if(is5_4_or7 == 4)
    {
        ui->I_line4_5->setPixmap(normalright);
        ui->I_line4_6->setPixmap(upright);

        ui->I_button_5->setEnabled(false);
        ui->I_weight4_5->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight4_6->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(4,6);
    }else if(is5_4_or7 == 7)
    {
        ui->I_button_16->setEnabled(false);
        ui->I_button_8->setEnabled(false);
        ui->I_button_2->setEnabled(false);
        ui->I_line7_2->setPixmap(downVertical);
        ui->I_line7_8->setPixmap(bottomleft);
        ui->I_line7_16->setPixmap(upleft);
        ui->I_line7_6->setPixmap(upright);

        ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        ui->I_button_7->setEnabled(false);
        money-= Insane_graph.get_weight(7,6);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is6_or16 = 6;
}



void MainWindow::on_I_button_7_pressed()
{

    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap bottomleftGreen("D:/DS Project Stuff/Images/vw3bottomleftgreen.png");
    QPixmap uprightGreen("D:/DS Project Stuff/Images/vw3rightgreen.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");
    QPixmap downVerticalGreen("D:/DS Project Stuff/Images/vwdowngreen.png");

    ui->I_button_6->setEnabled(true);
    ui->I_button_2->setEnabled(true);
    ui->I_button_8->setEnabled(true);
    ui->I_button_16->setEnabled(true);
    ui->I_button_7->setEnabled(false);
    ui->I_button_4->setEnabled(false);
    ui->I_line7_2->setPixmap(downVerticalGreen);
    ui->I_line7_6->setPixmap(uprightGreen);
    ui->I_line7_8->setPixmap(bottomleftGreen);
    ui->I_line7_16->setPixmap(upleftGreen);
    ui->I_line3_4->setPixmap(normalvertical);
    ui->I_line3_7->setPixmap(upleft);

    ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight3_4->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight3_7->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(3,7);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is1_or7 = 7;
    is10_or7 = 7;
    is5_4_or7 = 7;
}


void MainWindow::on_I_button_8_pressed()
{

    QPixmap downVertical("D:/DS Project Stuff/Images/vwdown.png");
    QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");
    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");
    QPixmap downVerticalGreen("D:/DS Project Stuff/Images/vwdowngreen.png");

    ui->I_button_1->setEnabled(true);
    ui->I_button_9->setEnabled(true);
    ui->I_button_2->setEnabled(false);
    ui->I_button_6->setEnabled(false);
    ui->I_button_16->setEnabled(false);
    ui->I_button_8->setEnabled(false);
    ui->I_line8_1->setPixmap(downVerticalGreen);
    ui->I_line8_9->setPixmap(upleftGreen);
    ui->I_line7_2->setPixmap(downVertical);
    ui->I_line7_6->setPixmap(upright);
    ui->I_line7_16->setPixmap(upleft);
    ui->I_line7_8->setPixmap(bottomleft);

    ui->I_weight8_1->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight8_9->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(7,8);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is0_or8 = 8;
    is8_or16 = 8;
}


void MainWindow::on_I_button_9_pressed()
{
    QPixmap downVertical("D:/DS Project Stuff/Images/vwdown.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");

    ui->I_button_10->setEnabled(true);
    ui->I_button_17->setEnabled(false);
    ui->I_button_20->setEnabled(false);
    ui->I_button_16->setEnabled(false);
    ui->I_button_1->setEnabled(false);
    ui->I_button_9->setEnabled(false);
    ui->I_line9_10->setPixmap(upleftGreen);
    ui->I_weight9_10->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is8_or16 == 8)
    {
        ui->I_line8_1->setPixmap(downVertical);
        ui->I_line8_9->setPixmap(upleft);
        ui->I_weight8_1->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight8_9->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(8,9);

    }else if(is8_or16 == 16)
    {
        ui->I_line16_17->setPixmap(normalright);
        ui->I_line16_20->setPixmap(upleft);
        ui->I_line16_9->setPixmap(bottomleft);

        ui->I_weight16_17->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_20->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_9->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(16,9);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is9_11_20_or21 = 9;
}

void MainWindow::on_I_button_10_pressed()
{

    QPixmap downVertical("D:/DS Project Stuff/Images/vwdown.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap bottomright("D:/DS Project Stuff/Images/vw3bottomright.png");
    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalLeftGreen("D:/DS Project Stuff/Images/vw3arrowleftgreen.png");

    QPixmap uprightGreen("D:/DS Project Stuff/Images/vw3rightgreen.png");


    ui->I_button_16->setEnabled(true);
    ui->I_button_15->setEnabled(true);
    ui->I_button_10->setEnabled(false);
    ui->I_button_20->setEnabled(false);
    ui->I_line10_16->setPixmap(uprightGreen);
    ui->I_line10_15->setPixmap(normalLeftGreen);

    ui->I_weight10_16->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight10_15->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is9_11_20_or21 == 9)
    {
        ui->I_line9_10->setPixmap(upleft);

        ui->I_weight9_10->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(9,10);

    }else if(is9_11_20_or21 == 11)
    {
        ui->I_line11_10->setPixmap(upright);

        ui->I_weight11_10->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(11,10);
    }else if(is9_11_20_or21 == 20)
    {
        ui->I_line20_10->setPixmap(downVertical);

        ui->I_weight20_10->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(20,10);
    }else if(is9_11_20_or21 == 21)
    {
        ui->I_line21_20->setPixmap(normalright);
        ui->I_line21_10->setPixmap(bottomright);

        ui->I_weight21_20->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight21_10->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(21,10);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is14_or10 = 10;
    is10_or7 =10;
}

void MainWindow::on_I_button_12_pressed()
{
    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");

    ui->I_button_11->setEnabled(true);
    ui->I_button_14->setEnabled(false);
    ui->I_button_12->setEnabled(false);
    ui->I_line12_11->setPixmap(upleftGreen);
    ui->I_line13_14->setPixmap(upleft);
    ui->I_line13_12->setPixmap(upright);

    ui->I_weight12_11->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight13_14->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight13_12->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(13,12);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}

void MainWindow::on_I_button_11_pressed()
{
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap uprightGreen("D:/DS Project Stuff/Images/vw3rightgreen.png");


    ui->I_button_10->setEnabled(true);
    ui->I_button_11->setEnabled(false);
    ui->I_line11_10->setPixmap(uprightGreen);
    ui->I_line12_11->setPixmap(upleft);

    ui->I_weight11_10->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight12_11->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(12,11);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is9_11_20_or21 = 11;
}

void MainWindow::on_I_button_14_pressed()
{


    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");


    QPixmap normalverticalGreen("D:/DS Project Stuff/Images/vwgreen.png");


    ui->I_button_15->setEnabled(true);
    ui->I_button_12->setEnabled(false);
    ui->I_button_14->setEnabled(false);
    ui->I_line14_15->setPixmap(normalverticalGreen);
    ui->I_line13_12->setPixmap(upright);
    ui->I_line13_14->setPixmap(upleft);

    ui->I_weight14_15->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight13_12->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight13_14->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(13,14);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is14_or10 = 14;
}

void MainWindow::on_I_button_15_pressed()
{


    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalLeft("D:/DS Project Stuff/Images/vw3arrowleft.png");

    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");

    QPixmap uprightGreen("D:/DS Project Stuff/Images/vw3rightgreen.png");


    ui->I_button_21->setEnabled(true);
    ui->I_button_16->setEnabled(false);
    ui->I_button_15->setEnabled(false);
    ui->I_line15_21->setPixmap(uprightGreen);

    ui->I_weight15_21->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is14_or10 == 14)
    {
        ui->I_line13_12->setPixmap(upright);
        ui->I_line14_15->setPixmap(normalvertical);

        ui->I_weight13_12->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight14_15->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(14,15);

    }else if(is14_or10 == 10)
    {
        ui->I_line10_16->setPixmap(upright);
        ui->I_line10_15->setPixmap(normalLeft);

        ui->I_weight10_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight10_15->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(10,15);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}

void MainWindow::on_I_button_16_pressed()
{

    QPixmap downVertical("D:/DS Project Stuff/Images/vwdown.png");

    QPixmap normalLeft("D:/DS Project Stuff/Images/vw3arrowleft.png");
    QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");
    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");


    QPixmap normalrightGreen("D:/DS Project Stuff/Images/vw3arrowgreen.png");

    QPixmap bottomleftGreen("D:/DS Project Stuff/Images/vw3bottomleftgreen.png");
    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");

    ui->I_button_9->setEnabled(true);
    ui->I_button_20->setEnabled(true);
    ui->I_button_17->setEnabled(true);
    ui->I_button_15->setEnabled(false);
    ui->I_button_8->setEnabled(false);
    ui->I_button_2->setEnabled(false);
    ui->I_button_6->setEnabled(false);
    ui->I_button_16->setEnabled(false);
    ui->I_line16_17->setPixmap(normalrightGreen);
    ui->I_line16_20->setPixmap(upleftGreen);
    ui->I_line16_9->setPixmap(bottomleftGreen);

    ui->I_weight16_17->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight16_20->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight16_9->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");


    if(is10_or7 == 10)
    {
        ui->I_line10_15->setPixmap(normalLeft);
        ui->I_line10_16->setPixmap(upright);

        ui->I_weight10_15->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight10_16->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(10,16);

    }else if(is10_or7 == 7)
    {
        ui->I_line7_8->setPixmap(bottomleft);
        ui->I_line7_2->setPixmap(downVertical);
        ui->I_line7_6->setPixmap(upright);
        ui->I_line7_16->setPixmap(upleft);

        ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(7,16);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is8_or16 = 16;
    is6_or16 = 16;
    is21_or16 = 16;
}


void MainWindow::on_I_button_17_pressed()
{

    QPixmap normalright("D:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");


    QPixmap normalverticalGreen("D:/DS Project Stuff/Images/vwgreen.png");

    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");

    ui->I_button_18->setEnabled(true);
    ui->I_button_19->setEnabled(true);
    ui->I_button_9->setEnabled(false);
    ui->I_button_20->setEnabled(false);
    ui->I_button_17->setEnabled(false);
    ui->I_line17_18->setPixmap(normalverticalGreen);
    ui->I_line17_19->setPixmap(upleftGreen);

    ui->I_weight17_18->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight17_19->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is6_or16 == 6)
    {
        ui->I_line6_17->setPixmap(upleft);

        ui->I_weight6_17->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(6,17);

    }else if(is6_or16 == 16)
    {
        ui->I_line16_9->setPixmap(bottomleft);
        ui->I_line16_20->setPixmap(upleft);
        ui->I_line16_17->setPixmap(normalright);

        ui->I_weight16_9->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_20->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_17->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(16,17);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is17_or_18 = 17;
}


void MainWindow::on_I_button_18_pressed()
{


    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");

    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");

    QPixmap normalLeftGreen("D:/DS Project Stuff/Images/vw3arrowleftgreen.png");


    ui->I_button_19->setEnabled(true);
    ui->I_button_18->setEnabled(false);
    ui->I_line18_19->setPixmap(normalLeftGreen);
    ui->I_line17_19->setPixmap(upleft);
    ui->I_line17_18->setPixmap(normalvertical);

    ui->I_weight18_19->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight17_19->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight17_18->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(17,18);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is17_or_18 = 18;
}

void MainWindow::on_I_button_19_pressed()
{


    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
    QPixmap normalLeft("D:/DS Project Stuff/Images/vw3arrowleft.png");

    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");

    QPixmap upleftGreen("D:/DS Project Stuff/Images/vw3leftgreen.png");

    ui->I_finishButton->setEnabled(true);
    ui->I_button_19->setEnabled(false);
    ui->I_line19_22->setPixmap(upleftGreen);

    ui->I_weight19_22->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is17_or_18 == 17)
    {
        ui->I_line17_18->setPixmap(normalvertical);
        ui->I_line17_19->setPixmap(upleft);

        ui->I_button_18->setEnabled(false);
        ui->I_weight17_18->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight17_19->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(17,19);

    }else if(is17_or_18 == 18)
    {
        ui->I_line18_19->setPixmap(normalLeft);

        ui->I_weight18_19->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(18,19);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}

void MainWindow::on_I_button_20_pressed()
{


    QPixmap normalright("D:/DS Project Stuff/Images/vw3arrow.png");
    QPixmap bottomright("D:/DS Project Stuff/Images/vw3bottomright.png");
    QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");
    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap downVerticalGreen("D:/DS Project Stuff/Images/vwdowngreen.png");

    ui->I_button_10->setEnabled(true);
    ui->I_button_9->setEnabled(false);
    ui->I_button_17->setEnabled(false);
    ui->I_button_20->setEnabled(false);
    ui->I_line20_10->setPixmap(downVerticalGreen);

    ui->I_weight20_10->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is21_or16 == 21)
    {
        ui->I_line21_10->setPixmap(bottomright);
        ui->I_line21_20->setPixmap(normalright);

        ui->I_weight21_10->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight21_20->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(21,20);

    }else if(is21_or16 == 16)
    {
        ui->I_line16_17->setPixmap(normalright);
        ui->I_line16_9->setPixmap(bottomleft);
        ui->I_line16_20->setPixmap(upleft);

        ui->I_weight16_17->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_9->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_20->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(16,20);
    }
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is9_11_20_or21 = 20;
}

void MainWindow::on_I_button_21_pressed()
{

    QPixmap upright("D:/DS Project Stuff/Images/vw3right.png");


    QPixmap normalrightGreen("D:/DS Project Stuff/Images/vw3arrowgreen.png");
    QPixmap bottomrightGreen("D:/DS Project Stuff/Images/vw3bottomrightgreen.png");


    ui->I_button_10->setEnabled(true);
    ui->I_button_20->setEnabled(true);
    ui->I_button_21->setEnabled(false);
    ui->I_line21_20->setPixmap(normalrightGreen);
    ui->I_line21_10->setPixmap(bottomrightGreen);
    ui->I_line15_21->setPixmap(upright);

    ui->I_weight21_20->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight21_10->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight15_21->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(15,21);
    //cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is9_11_20_or21 = 21;
    is21_or16 = 21;
}

void MainWindow::on_I_finishButton_pressed()
{

    QPixmap upleft("D:/DS Project Stuff/Images/vw3left.png");
    ui->I_line19_22->setPixmap(upleft);

    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/finish.mp3"));
    buttonsfx->play();

    money-= Insane_graph.get_weight(19,22);

    if(money < 0)
    {
        ui->star1->setVisible(0);
        ui->star2->setVisible(0);
        ui->star3->setVisible(0);
        ui->stackedWidget->setCurrentIndex(3);
        ui->winner_label->setText("You Lose");
        ui->nextLevel_button->setEnabled(false);
    }
    else
    {
        ui->star1->setVisible(1);
        ui->star2->setVisible(1);
        ui->star3->setVisible(1);
        ui->winner_label->setText("You Win!!");
        ui->stackedWidget->setCurrentIndex(3);
        ui->nextLevel_button->setEnabled(false);

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
        else if (money == 0)
        {
            QPixmap greenstar("D:/DS Project Stuff/Images/stargreen.png");
            ui->star1->setPixmap(greenstar);
        }

    }

    //setStars();
}


