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


vector<Edge> edges_med = { {0,1},{0,2},{1,4},{1,5},{2,1},{2,3},{2,4},{3,6},{3,8},
     {4,7},{4,8},{5,3},{5,7},{6,9},{7,8},{7,11},{8,9},{9,5},
     {9,10},{10,12},{11,10},{11,13},{12,13}
 };
Graph med_graph(edges_med,14);
bool from[15]={0};

void update_from(int x){
    for (int i =0;i<15;i++){
        from[i]=0;
    }
    from[x]=1;
}

QString make_number(int x){
    return QString::number(-x);
}


void MainWindow::on_medium_button_pressed()
{
    ui->stackedWidget->setCurrentIndex(4);
    //med graph ********************************************************

    med_graph.generateRandomWeights();
    med_graph.printGraph();
    money = med_graph.BellmanFordSP(0,13);
    ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    ui->M_weight0_1->setText(make_number(med_graph.get_weight(0,1)));
    ui->M_weight0_2->setText(make_number(med_graph.get_weight(0,2)));
    ui->M_weight1_4->setText(make_number(med_graph.get_weight(1,4)));
    ui->M_weight1_5->setText(make_number(med_graph.get_weight(1,5)));
    ui->M_weight2_1->setText(make_number(med_graph.get_weight(2,1)));
    ui->M_weight2_3->setText(make_number(med_graph.get_weight(2,3)));
    ui->M_weight2_4->setText(make_number(med_graph.get_weight(2,4)));
    ui->M_weight3_6->setText(make_number(med_graph.get_weight(3,6)));
    ui->M_weight3_8->setText(make_number(med_graph.get_weight(3,8)));
    ui->M_weight4_7->setText(make_number(med_graph.get_weight(4,7)));
    ui->M_weight4_8->setText(make_number(med_graph.get_weight(4,8)));
    ui->M_weight5_3->setText(make_number(med_graph.get_weight(5,3)));
    ui->M_weight5_7->setText(make_number(med_graph.get_weight(5,7)));
    ui->M_weight6_9->setText(make_number(med_graph.get_weight(6,9)));
    ui->M_weight7_8->setText(make_number(med_graph.get_weight(7,8)));
    ui->M_weight7_11->setText(make_number(med_graph.get_weight(7,11)));
    ui->M_weight8_9->setText(make_number(med_graph.get_weight(8,9)));
    ui->M_weight9_5->setText(make_number(med_graph.get_weight(9,5)));
    ui->M_weight9_10->setText(make_number(med_graph.get_weight(9,10)));
    ui->M_weight10_12->setText(make_number(med_graph.get_weight(10,12)));
    ui->M_weight11_10->setText(make_number(med_graph.get_weight(11,10)));
    ui->M_weight11_13->setText(make_number(med_graph.get_weight(11,13)));
    ui->M_weight12_13->setText(make_number(med_graph.get_weight(12,13)));

}


void MainWindow::on_M_startgame_button_pressed()
{
    update_from(0);
    ui->M_button_1->setEnabled(true);
    ui->M_button_2->setEnabled(true);
    ui->M_startgame_button->setEnabled(0);

}
void MainWindow::on_M_button_1_pressed()
{
    ui->M_weight2_1->setStyleSheet(WHITE);
    ui->M_weight2_3->setStyleSheet(WHITE);
    ui->M_weight2_4->setStyleSheet(WHITE);
    ui->M_weight1_5->setStyleSheet(GREEN);
    ui->M_weight1_4->setStyleSheet(GREEN);
    ui->M_startgame_button->setEnabled(false);
    ui->M_button_2->setEnabled(false);
    ui->M_button_3->setEnabled(false);
    ui->M_button_4->setEnabled(true);
    ui->M_button_5->setEnabled(true);
    ui->M_button_1->setEnabled(0);
    if(from[0]){
        money-= med_graph.get_weight(0,1);
    }else{
        money -=med_graph.get_weight(2,1);
    }
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(1);

}

void MainWindow::on_M_button_4_pressed()
{
    ui->M_weight1_5->setStyleSheet(WHITE);
    ui->M_weight1_4->setStyleSheet(WHITE);

    ui->M_weight2_3->setStyleSheet(WHITE);
    ui->M_weight2_1->setStyleSheet(WHITE);
    ui->M_weight2_4->setStyleSheet(WHITE);

    ui->M_weight4_7->setStyleSheet(GREEN);
    ui->M_weight4_8->setStyleSheet(GREEN);
    ui->M_button_4->setEnabled(false);
    ui->M_button_5->setEnabled(false);
    ui->M_button_3->setEnabled(false);
    ui->M_button_1->setEnabled(false);
    ui->M_button_7->setEnabled(true);
    ui->M_button_8->setEnabled(true);
    if(from[1]){
        money -= med_graph.get_weight(1,4);
    }else{
        money -=med_graph.get_weight(2,4);
    }
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(4);
}

void MainWindow::on_M_button_5_pressed()
{
    ui->M_weight1_5->setStyleSheet(WHITE);
    ui->M_weight1_4->setStyleSheet(WHITE);

    ui->M_weight9_5->setStyleSheet(WHITE);
    ui->M_weight9_10->setStyleSheet(WHITE);

    ui->M_weight5_7->setStyleSheet(GREEN);
    ui->M_weight5_3->setStyleSheet(GREEN);
    ui->M_button_4->setEnabled(false);
    ui->M_button_5->setEnabled(false);
    ui->M_button_10->setEnabled(false);
    ui->M_button_9->setEnabled(false);
    ui->M_button_7->setEnabled(true);
    ui->M_button_3->setEnabled(true);
    if(from[1]){
        money -= med_graph.get_weight(1,5);
    }else{
        money -= med_graph.get_weight(9,5);
    }
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(5);
}

void MainWindow::on_M_button_2_pressed()
{
    ui->M_weight2_1->setStyleSheet(GREEN);
    ui->M_weight2_3->setStyleSheet(GREEN);
    ui->M_weight2_4->setStyleSheet(GREEN);
    ui->M_startgame_button->setEnabled(false);
    ui->M_button_2->setEnabled(false);
    ui->M_button_4->setEnabled(true);
    ui->M_button_3->setEnabled(true);
    ui->M_button_1->setEnabled(true);
    money -= med_graph.get_weight(0,2);
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(2);

}

void MainWindow::on_M_button_3_pressed()
{
    ui->M_weight2_1->setStyleSheet(WHITE);
    ui->M_weight2_3->setStyleSheet(WHITE);
    ui->M_weight2_4->setStyleSheet(WHITE);
    ui->M_weight5_7->setStyleSheet(WHITE);
    ui->M_weight5_3->setStyleSheet(WHITE);

    ui->M_weight3_6->setStyleSheet(GREEN);
    ui->M_weight3_8->setStyleSheet(GREEN);

    ui->M_startgame_button->setEnabled(false);
    ui->M_button_2->setEnabled(false);
    ui->M_button_7->setEnabled(false);
    ui->M_button_4->setEnabled(false);
    ui->M_button_3->setEnabled(false);
    ui->M_button_1->setEnabled(false);
    ui->M_button_8->setEnabled(true);
    ui->M_button_6->setEnabled(true);
    if(from[2]){
        money -= med_graph.get_weight(2,3);
    }else{
        money -= med_graph.get_weight(5,3);
    }
    ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(3);
}

void MainWindow::on_M_button_6_pressed()
{
    ui->M_button_8->setEnabled(false);
    ui->M_button_9->setEnabled(true);
    ui->M_weight3_8->setStyleSheet(WHITE);
    ui->M_weight3_6->setStyleSheet(WHITE);
    ui->M_weight6_9->setStyleSheet(GREEN);
    if(from[3]){
        money -= med_graph.get_weight(3,6);
    }
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(6);

}

void MainWindow::on_M_button_7_pressed()
{
    ui->M_button_3->setEnabled(false);
    ui->M_button_4->setEnabled(false);
    ui->M_button_5->setEnabled(false);
    ui->M_button_8->setEnabled(false);
    ui->M_button_7->setEnabled(false);

    ui->M_button_11->setEnabled(true);

    ui->M_weight4_7->setStyleSheet(WHITE);
    ui->M_weight4_8->setStyleSheet(WHITE);
    ui->M_weight5_7->setStyleSheet(WHITE);
    ui->M_weight5_3->setStyleSheet(WHITE);

    ui->M_weight7_11->setStyleSheet(GREEN);

    if(from[4]){
        money -= med_graph.get_weight(4,7);
    }else{
        money -= med_graph.get_weight(5,7);
    }
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(7);
}

void MainWindow::on_M_button_8_pressed()
{
    ui->M_button_3->setEnabled(false);
    ui->M_button_4->setEnabled(false);
    ui->M_button_6->setEnabled(false);
    ui->M_button_7->setEnabled(false);
    ui->M_button_11->setEnabled(false);
    ui->M_button_8->setEnabled(false);

    ui->M_button_9->setEnabled(true);

    ui->M_weight7_11->setStyleSheet(WHITE);
    ui->M_weight4_7->setStyleSheet(WHITE);
    ui->M_weight7_8->setStyleSheet(WHITE);
    ui->M_weight4_8->setStyleSheet(WHITE);
    ui->M_weight3_8->setStyleSheet(WHITE);
    ui->M_weight3_6->setStyleSheet(WHITE);

    ui->M_weight8_9->setStyleSheet(GREEN);

    if(from[7]){
        money -= med_graph.get_weight(7,8);
    }else if (from[4]){
        money -= med_graph.get_weight(4,8);
    }else if(from[3]){
        money -= med_graph.get_weight(3,8);
    }
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(8);
}

void MainWindow::on_M_button_9_pressed()
{
    ui->M_button_6->setEnabled(false);
    ui->M_button_8->setEnabled(false);
    ui->M_button_9->setEnabled(false);
    ui->M_button_10->setEnabled(true);
    ui->M_button_5->setEnabled(true);
    ui->M_weight8_9->setStyleSheet(WHITE);
    ui->M_weight6_9->setStyleSheet(WHITE);

    ui->M_weight9_10->setStyleSheet(GREEN);
    ui->M_weight9_5->setStyleSheet(GREEN);
    if(from[8]){
        money -= med_graph.get_weight(8,9);
    }else{
        money -= med_graph.get_weight(6,9);
    }
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(9);

}


void MainWindow::on_M_button_10_pressed()
{
    ui->M_button_9->setEnabled(false);

    ui->M_button_11->setEnabled(false);
    ui->M_button_12->setEnabled(true);
    ui->M_finishButton->setEnabled(false);
    ui->M_button_10->setEnabled(false);

    ui->M_weight11_10->setStyleSheet(WHITE);
    ui->M_weight11_13->setStyleSheet(WHITE);
    ui->M_weight9_10->setStyleSheet(WHITE);

    ui->M_weight10_12->setStyleSheet(GREEN);

    if(from[11]){
        money -= med_graph.get_weight(11,10);
    }else{
        money -= med_graph.get_weight(9,10);
    }
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(10);


}

void MainWindow::on_M_button_11_pressed()
{

    ui->M_weight7_8->setStyleSheet(WHITE);
    ui->M_weight7_11->setStyleSheet(WHITE);

    ui->M_weight11_10->setStyleSheet(GREEN);
    ui->M_weight11_13->setStyleSheet(GREEN);

    ui->M_button_11->setEnabled(false);
    ui->M_button_10->setEnabled(true);

    ui->M_finishButton->setEnabled(true);
    money -= med_graph.get_weight(7,11);
    ui->M_money_label->setText(QString::number(money));
    update_from(11);

}

void MainWindow::on_M_button_12_pressed()
{
    ui->M_weight10_12->setStyleSheet(WHITE);
    ui->M_weight12_13->setStyleSheet(GREEN);
    ui->M_finishButton->setEnabled(true);
    ui->M_button_10->setEnabled(false);
    money -= med_graph.get_weight(10,12);
     ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(12);

}


void MainWindow::on_M_finishButton_pressed()
{
    if(from[11]){
        money -= med_graph.get_weight(11,13);
    }else{
        money -= med_graph.get_weight(12,13);
    }

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




