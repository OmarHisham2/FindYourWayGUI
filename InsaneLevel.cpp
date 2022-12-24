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


#define GREEN "color:#00FF00"
#define WHITE "color:#FFFFFF"

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
vector<Edge> Insane_edges = { {0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{4,6},{3,7},{7,2},
     {7,6},{7,8},{8,1},{0,13},{13,14},{13,12},{12,11},{11,10},{9,10},
     {8,9},{14,15},{15,21},{21,10},{20,10},{21,20},{16,20},{10,16},
     {16,9},{7,16},{6,17},{16,17},{17,18},{17,19},{19,22},{18,19},{10,15}
 };

Graph Insane_graph(Insane_edges, 23);

QString make_Inumber(int x){
    return QString::number(-x);
}

bool Ifrom[15]={0};

void update_Ifrom(int x){
    for (int i =0;i<15;i++){
        Ifrom[i]=0;
    }
    Ifrom[x]=1;
}

void MainWindow::on_hard_button_pressed()
{
    ui->stackedWidget->setCurrentIndex(5);

    Insane_graph.generateRandomWeights();
    Insane_graph.printGraph();
    money = Insane_graph.BellmanFordSP(0,13);
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
}




void MainWindow::on_I_startgame_button_pressed()
{

    update_Ifrom(0);
    ui->I_button_1->setEnabled(true);
    ui->I_button_13->setEnabled(true);
    ui->I_startgame_button->setEnabled(0);
    ui->I_weight0_1->setStyleSheet("QLabel {color : #00FF00} ");
    ui->I_weight0_13->setStyleSheet("QLabel {color : #00FF00} ");
    is0_or8 = 0;
}




void MainWindow::on_I_button_1_pressed()
{
    is1_or7 = 1;
    ui->I_button_2->setEnabled(true);
    ui->I_button_1->setEnabled(false);
    ui->I_button_13->setEnabled(false);
    ui->I_button_9->setEnabled(false);
    ui->I_weight1_2->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight0_13->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    if(is0_or8 == 0)
    {
        ui->I_weight0_1->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(0,1);
    }else if(is0_or8 == 8)
    {
        ui->I_weight8_9->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight8_1->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(8,1);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}


void MainWindow::on_I_button_13_pressed()
{
    ui->I_button_12->setEnabled(true);
    ui->I_button_14->setEnabled(true);
    ui->I_button_13->setEnabled(false);
    ui->I_button_1->setEnabled(false);
    ui->I_weight13_12->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight13_14->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight0_1->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight0_13->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    ui->I_button_13->setEnabled(false);
    money-= Insane_graph.get_weight(0,13);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}


void MainWindow::on_I_button_2_pressed()
{
    ui->I_button_3->setEnabled(true);
    ui->I_button_2->setEnabled(false);
    ui->I_weight2_3->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_button_13->setEnabled(false);
    if(is1_or7 == 1)
    {
        ui->I_weight1_2->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(1,2);
    }else if(is1_or7 == 7)
    {
        ui->I_button_16->setEnabled(false);
        ui->I_button_8->setEnabled(false);
        ui->I_button_6->setEnabled(false);
        ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(7,2);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}



void MainWindow::on_I_button_3_pressed()
{
    ui->I_button_4->setEnabled(true);
    ui->I_button_7->setEnabled(true);
    ui->I_button_3->setEnabled(false);
    ui->I_weight3_4->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight3_7->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight2_3->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(2,3);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}


void MainWindow::on_I_button_4_pressed()
{
    ui->I_button_5->setEnabled(true);
    ui->I_button_6->setEnabled(true);
    ui->I_button_3->setEnabled(false);
    ui->I_button_7->setEnabled(false);
    ui->I_weight4_5->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight4_6->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight3_7->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight3_4->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    ui->I_button_4->setEnabled(false);
    money-= Insane_graph.get_weight(3,4);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is5_4_or7 = 4;
}



void MainWindow::on_I_button_5_pressed()
{
    ui->I_button_6->setEnabled(true);
    ui->I_button_4->setEnabled(false);
    ui->I_button_5->setEnabled(false);
    ui->I_weight5_6->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight4_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight4_5->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(4,5);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    //is5_or_6 = true;
    is5_4_or7 = 5;
}


void MainWindow::on_I_button_6_pressed()
{
    ui->I_button_17->setEnabled(true);
    ui->I_button_6->setEnabled(false);
    ui->I_weight6_17->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    if(is5_4_or7 == 5)
    {
        ui->I_weight4_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight4_5->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight5_6->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(5,6);
    }else if(is5_4_or7 == 4)
    {
        ui->I_button_5->setEnabled(false);
        ui->I_weight4_5->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight4_6->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(4,6);
    }else if(is5_4_or7 == 7)
    {
        ui->I_button_16->setEnabled(false);
        ui->I_button_8->setEnabled(false);
        ui->I_button_2->setEnabled(false);
        ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        ui->I_button_7->setEnabled(false);
        money-= Insane_graph.get_weight(7,6);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is6_or16 = 6;
}



void MainWindow::on_I_button_7_pressed()
{
    ui->I_button_6->setEnabled(true);
    ui->I_button_2->setEnabled(true);
    ui->I_button_8->setEnabled(true);
    ui->I_button_16->setEnabled(true);
    ui->I_button_7->setEnabled(false);
    ui->I_button_4->setEnabled(false);
    ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight3_4->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight3_7->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(3,7);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is1_or7 = 7;
    is10_or7 = 7;
    is5_4_or7 = 7;
}


void MainWindow::on_I_button_8_pressed()
{

    ui->I_button_1->setEnabled(true);
    ui->I_button_9->setEnabled(true);
    ui->I_button_2->setEnabled(false);
    ui->I_button_6->setEnabled(false);
    ui->I_button_16->setEnabled(false);
    ui->I_button_8->setEnabled(false);
    ui->I_weight8_1->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight8_9->setStyleSheet("QLabel {background-color: transparent; color : #00FF00} ");
    ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(7,8);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is0_or8 = 8;
    is8_or16 = 8;
}


void MainWindow::on_I_button_9_pressed()
{
    ui->I_button_10->setEnabled(true);
    ui->I_button_17->setEnabled(false);
    ui->I_button_20->setEnabled(false);
    ui->I_button_16->setEnabled(false);
    ui->I_button_1->setEnabled(false);
    ui->I_button_9->setEnabled(false);
    ui->I_weight9_10->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is8_or16 == 8)
    {
        ui->I_weight8_1->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight8_9->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(8,9);

    }else if(is8_or16 == 16)
    {
        ui->I_weight16_17->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_20->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_9->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(16,9);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is9_11_20_or21 = 9;
}

void MainWindow::on_I_button_10_pressed()
{
    ui->I_button_16->setEnabled(true);
    ui->I_button_15->setEnabled(true);
    ui->I_button_10->setEnabled(false);
    ui->I_button_20->setEnabled(false);
    ui->I_weight10_16->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight10_15->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is9_11_20_or21 == 9)
    {
        ui->I_weight9_10->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(9,10);

    }else if(is9_11_20_or21 == 11)
    {
        ui->I_weight11_10->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(11,10);
    }else if(is9_11_20_or21 == 20)
    {
        ui->I_weight20_10->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(20,10);
    }else if(is9_11_20_or21 == 21)
    {
        ui->I_weight21_20->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight21_10->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(21,10);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is14_or10 = 10;
    is10_or7 =10;
}

void MainWindow::on_I_button_12_pressed()
{
    ui->I_button_11->setEnabled(true);
    ui->I_button_14->setEnabled(false);
    ui->I_button_12->setEnabled(false);
    ui->I_weight12_11->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight13_14->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight13_12->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(13,12);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}

void MainWindow::on_I_button_11_pressed()
{
    ui->I_button_10->setEnabled(true);
    ui->I_button_11->setEnabled(false);
    ui->I_weight11_10->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight12_11->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(12,11);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is9_11_20_or21 = 11;
}

void MainWindow::on_I_button_14_pressed()
{
    ui->I_button_15->setEnabled(true);
    ui->I_button_12->setEnabled(false);
    ui->I_button_14->setEnabled(false);
    ui->I_weight14_15->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight13_12->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight13_14->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(13,14);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is14_or10 = 14;
}

void MainWindow::on_I_button_15_pressed()
{
    ui->I_button_21->setEnabled(true);
    ui->I_button_16->setEnabled(false);
    ui->I_button_15->setEnabled(false);
    ui->I_weight15_21->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is14_or10 == 14)
    {
        ui->I_weight13_12->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight14_15->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(14,15);

    }else if(is14_or10 == 10)
    {
        ui->I_weight10_16->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight10_15->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(10,15);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}

void MainWindow::on_I_button_16_pressed()
{
    ui->I_button_9->setEnabled(true);
    ui->I_button_20->setEnabled(true);
    ui->I_button_17->setEnabled(true);
    ui->I_button_15->setEnabled(false);
    ui->I_button_8->setEnabled(false);
    ui->I_button_2->setEnabled(false);
    ui->I_button_6->setEnabled(false);
    ui->I_button_16->setEnabled(false);
    ui->I_weight16_17->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight16_20->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight16_9->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");


    if(is10_or7 == 10)
    {
        ui->I_weight10_15->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight10_16->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(10,16);

    }else if(is10_or7 == 7)
    {
        ui->I_weight7_8->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_2->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_6->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight7_16->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(7,16);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is8_or16 = 16;
    is6_or16 = 16;
    is21_or16 = 16;
}


void MainWindow::on_I_button_17_pressed()
{
    ui->I_button_18->setEnabled(true);
    ui->I_button_19->setEnabled(true);
    ui->I_button_9->setEnabled(false);
    ui->I_button_20->setEnabled(false);
    ui->I_button_17->setEnabled(false);
    ui->I_weight17_18->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight17_19->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is6_or16 == 6)
    {
        ui->I_weight6_17->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(6,17);

    }else if(is6_or16 == 16)
    {
        ui->I_weight16_9->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_20->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_17->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(16,17);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is17_or_18 = 17;
}


void MainWindow::on_I_button_18_pressed()
{
    ui->I_button_19->setEnabled(true);
    ui->I_button_18->setEnabled(false);
    ui->I_weight18_19->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight17_19->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
    ui->I_weight17_18->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(17,18);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is17_or_18 = 18;
}

void MainWindow::on_I_button_19_pressed()
{
    ui->I_finishButton->setEnabled(true);
    ui->I_button_19->setEnabled(false);
    ui->I_weight19_22->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is17_or_18 == 17)
    {
        ui->I_button_18->setEnabled(false);
        ui->I_weight17_18->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight17_19->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(17,19);

    }else if(is17_or_18 == 18)
    {
        ui->I_weight18_19->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(18,19);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
}

void MainWindow::on_I_button_20_pressed()
{
    ui->I_button_10->setEnabled(true);
    ui->I_button_9->setEnabled(false);
    ui->I_button_17->setEnabled(false);
    ui->I_button_20->setEnabled(false);
    ui->I_weight20_10->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");

    if(is21_or16 == 21)
    {
        ui->I_weight21_10->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight21_20->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(21,20);

    }else if(is21_or16 == 16)
    {
        ui->I_weight16_17->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_9->setStyleSheet("QLabel {background-color: transparent; color : #FFF} ");
        ui->I_weight16_20->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
        money-= Insane_graph.get_weight(16,20);
    }
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is9_11_20_or21 = 20;
}

void MainWindow::on_I_button_21_pressed()
{
    ui->I_button_10->setEnabled(true);
    ui->I_button_20->setEnabled(true);
    ui->I_button_21->setEnabled(false);
    ui->I_weight21_20->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight21_10->setStyleSheet("QLabel {background-color: transparent; color : #00FF00;} ");
    ui->I_weight15_21->setStyleSheet("QLabel {background-color: transparent; color : #FF001B} ");
    money-= Insane_graph.get_weight(15,21);
    cout<<"\nMoney = "<<money;
    ui->I_money_label->setText(QString("Money : ").append(QString::number(money)));
    is9_11_20_or21 = 21;
    is21_or16 = 21;
}

void MainWindow::on_I_finishButton_pressed()
{
    buttonsfx->setAudioOutput(leveloutput);
    leveloutput->setVolume(0.8);
    buttonsfx->setSource(QUrl("qrc:/D:/DS Project Stuff/SFX/finish.mp3"));
    buttonsfx->play();

    money-= Insane_graph.get_weight(19,22);

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


