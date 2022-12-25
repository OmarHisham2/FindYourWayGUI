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

#define GREEN "color:#00FF00"
#define WHITE "color:#FFFFFF"
extern int money;
long int med_seed;
extern bool med,easy,seed,hard;
vector<Edge> edges_med = { {0,1},{0,2},{1,4},{1,5},{2,1},{2,3},{2,4},{3,6},{3,8},
     {4,7},{4,8},{5,3},{5,7},{6,9},{7,8},{7,11},{8,9},{9,5},
     {9,10},{10,12},{11,10},{11,13},{12,13}
 };
Graph med_graph(edges_med,14);
bool from[15]={0};
long int num;
void update_from(long int x){
    for (int i =0;i<15;i++){
        from[i]=0;
    }
    from[x]=1;
}

QString make_number(long int x){
    return QString::number(-x);
}


void MainWindow::on_M_seed_button_pressed()
{
    QInputDialog d;
    d.setStyleSheet("color: #FFF;"
                    "background-color: grey;"
                    "selection-color: grey;"
                    "selection-background-color: #000;");
    //d.setAutoFillBackground(0);

    d.exec();
    QString st =  d.textValue(); //add
    ui->stackedWidget->setCurrentIndex(4);
    //med graph ********************************************************
    ui->M_finishButton->setEnabled(0);
    num = med_graph.generateRandomWeights(st.toLong());
    med_seed = num;
    ui->M_seed_label->setText(make_number(-num));
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



  //  QString text = d.getText(this,"Enter Seed","text");

}


void MainWindow::on_medium_button_pressed()
{
    med =true;
    easy=false;
    hard=false;
    ui->stackedWidget->setCurrentIndex(4);
    //med graph ********************************************************
    ui->M_finishButton->setEnabled(0);
    num = med_graph.generateRandomWeights();
    ui->M_seed_label->setText(make_number(-num));
    med_seed =num;
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
    ui->M_finishButton->setEnabled(0);
    ui->M_weight0_1->setStyleSheet(GREEN);
    ui->M_weight0_2->setStyleSheet(GREEN);


}
void MainWindow::on_M_button_1_pressed()
{
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
           QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
           QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
              QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");
              QPixmap normalarrowleft("D:/DS Project Stuff/Images/vw3arrowleft.png");
    ui->M_weight2_1->setStyleSheet(WHITE);
    ui->M_weight2_3->setStyleSheet(WHITE);
    ui->M_weight2_4->setStyleSheet(WHITE);
    ui->M_weight1_5->setStyleSheet(GREEN);
    ui->M_weight1_4->setStyleSheet(GREEN);
    ui->M_weight0_1->setStyleSheet(WHITE);
    ui->M_weight0_2->setStyleSheet(WHITE);
    ui->M_line0_1->setPixmap(normalleft);
     ui->M_line0_2->setPixmap(normalright);
     ui->M_line2_1->setPixmap(normalarrowleft);
     ui->M_line1_4->setPixmap(greenleft);
     ui->M_line1_5->setPixmap(greenright);
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

    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
        QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
        QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
          QPixmap greenvertical("D:/DS Project Stuff/Images/vwgreen.png");
    ui->M_weight1_5->setStyleSheet(WHITE);
    ui->M_weight1_4->setStyleSheet(WHITE);

    ui->M_weight2_3->setStyleSheet(WHITE);
    ui->M_weight2_1->setStyleSheet(WHITE);
    ui->M_weight2_4->setStyleSheet(WHITE);

    ui->M_weight4_7->setStyleSheet(GREEN);
    ui->M_weight4_8->setStyleSheet(GREEN);

    ui->M_line1_4->setPixmap(normalleft);
       ui->M_line1_5->setPixmap(normalright);
       ui->M_line4_7->setPixmap(greenvertical);
       ui->M_line4_8->setPixmap(greenright);
       ui->M_line2_3->setPixmap(normalright);
       ui->M_line2_4->setPixmap(normalleft);

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
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
        QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");

         QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");

          QPixmap greenarrowright("D:/DS Project Stuff/Images/vw3arrowgreen.png");

        QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");

        ui->M_line1_4->setPixmap(normalleft);
         ui->M_line1_5->setPixmap(normalright);
         ui->M_line9_5->setPixmap(bottomleft);
         ui->M_line5_7->setPixmap(greenleft);
         ui->M_line5_3->setPixmap(greenarrowright);
         ui->M_line9_10->setPixmap(normalleft);


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

    QPixmap greenarrowleft("D:/DS Project Stuff/Images/vw3arrowleftgreen.png");
        QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
        QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
        QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
        QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");
        ui->M_line0_1->setPixmap(normalleft);
        ui->M_line0_2->setPixmap(normalright);
        ui->M_line2_1->setPixmap(greenarrowleft);
        ui->M_line2_3->setPixmap(greenright);
        ui->M_line2_4->setPixmap(greenleft);

    ui->M_weight2_1->setStyleSheet(GREEN);
    ui->M_weight2_3->setStyleSheet(GREEN);
    ui->M_weight2_4->setStyleSheet(GREEN);
    ui->M_weight0_1->setStyleSheet(WHITE);
    ui->M_weight0_2->setStyleSheet(WHITE);
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

    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
       QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
       QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");
        QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");

       QPixmap normalarrowleft("D:/DS Project Stuff/Images/vw3arrowleft.png");

       QPixmap normalarrowright("D:/DS Project Stuff/Images/vw3arrow.png");

       ui->M_line2_3->setPixmap(normalright);
       ui->M_line5_3->setPixmap(normalarrowright);
       ui->M_line5_7->setPixmap(normalleft);

       ui->M_line3_8->setPixmap(greenleft);
       ui->M_line3_6->setPixmap(greenright);

       ui->M_line2_1->setPixmap(normalarrowleft);
       ui->M_line2_3->setPixmap(normalright);
       ui->M_line2_4->setPixmap(normalleft);

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

    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
        QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");

          QPixmap greenvertical("D:/DS Project Stuff/Images/vwgreen.png");



        ui->M_line3_8->setPixmap(normalleft);
        ui->M_line3_6->setPixmap(normalright);
        ui->M_line6_9->setPixmap(greenvertical);


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

    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
        QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
        QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");

          QPixmap greenvertical("D:/DS Project Stuff/Images/vwgreen.png");

        QPixmap bottomrightgreen("D:/DS Project Stuff/Images/vw3bottomrightgreen.png");
    QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");
    QPixmap normalarrowright("D:/DS Project Stuff/Images/vw3arrow.png");

        ui->M_line7_11->setPixmap(greenvertical);
        ui->M_line7_8->setPixmap(bottomrightgreen);
        ui->M_line4_7->setPixmap(normalvertical);
        ui->M_line1_5->setPixmap(normalright);
        ui->M_line9_5->setPixmap(bottomleft);
        ui->M_line5_7->setPixmap(normalleft);
        ui->M_line5_3->setPixmap(normalarrowright);
        ui->M_line4_8->setPixmap(normalright); //just in case

    ui->M_button_3->setEnabled(false);
    ui->M_button_4->setEnabled(false);
    ui->M_button_5->setEnabled(false);
    ui->M_button_8->setEnabled(false);
    ui->M_button_7->setEnabled(false);

    ui->M_button_11->setEnabled(true);
    ui->M_button_8->setEnabled(true);

    ui->M_weight4_7->setStyleSheet(WHITE);
    ui->M_weight4_8->setStyleSheet(WHITE);
    ui->M_weight5_7->setStyleSheet(WHITE);
    ui->M_weight5_3->setStyleSheet(WHITE);

    ui->M_weight7_11->setStyleSheet(GREEN);
    ui->M_weight7_8->setStyleSheet(GREEN);

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

    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");
        QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
        QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
        QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");

        QPixmap bottomright("D:/DS Project Stuff/Images/vw3bottomright.png");



        ui->M_line8_9->setPixmap(greenright);
        ui->M_line7_11->setPixmap(normalvertical);
        ui->M_line7_8->setPixmap(bottomright);
        ui->M_line3_8->setPixmap(normalleft);
        ui->M_line3_6->setPixmap(normalright);
        ui->M_line4_7->setPixmap(normalvertical);
        ui->M_line4_8->setPixmap(normalright);


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

    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");

        QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");

         QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");

        QPixmap bottomleftgreen("D:/DS Project Stuff/Images/vw3bottomleftgreen.png");


        ui->M_line9_10->setPixmap(greenleft);
        ui->M_line9_5->setPixmap(bottomleftgreen);
         ui->M_line8_9->setPixmap(normalright);
          ui->M_line6_9->setPixmap(normalvertical);



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


    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");

     QPixmap bottomright("D:/DS Project Stuff/Images/vw3bottomright.png");
      QPixmap bottomleft("D:/DS Project Stuff/Images/vw3bottomleft.png");

   ui->M_line10_12->setPixmap(greenright);
    ui->M_line11_10->setPixmap(bottomright);
   ui->M_line9_10->setPixmap(normalleft);

    ui->M_line9_5->setPixmap(bottomleft);

     ui->M_line11_13->setPixmap(normalright);


    ui->M_button_9->setEnabled(false);
    ui->M_button_5->setEnabled(false);
    ui->M_button_11->setEnabled(false);
    ui->M_button_12->setEnabled(true);
    ui->M_finishButton->setEnabled(false);
    ui->M_button_10->setEnabled(false);

    ui->M_weight11_10->setStyleSheet(WHITE);
    ui->M_weight11_13->setStyleSheet(WHITE);
    ui->M_weight9_5->setStyleSheet(WHITE);
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

    QPixmap normalvertical("D:/DS Project Stuff/Images/vw.png");

        QPixmap greenright("D:/DS Project Stuff/Images/vw3rightgreen.png");


        QPixmap bottomright("D:/DS Project Stuff/Images/vw3bottomright.png");

        ui->M_line11_13->setPixmap(greenright);
        ui->M_line7_11->setPixmap(normalvertical);

        ui->M_line7_8->setPixmap(bottomright);

    ui->M_weight7_8->setStyleSheet(WHITE);
    ui->M_weight7_11->setStyleSheet(WHITE);

    ui->M_weight11_10->setStyleSheet(GREEN);
    ui->M_weight11_13->setStyleSheet(GREEN);

    ui->M_button_11->setEnabled(false);
    ui->M_button_8->setEnabled(false);
    ui->M_button_10->setEnabled(true);

    ui->M_finishButton->setEnabled(true);
    money -= med_graph.get_weight(7,11);
    ui->M_money_label->setText(QString::number(money));
    update_from(11);

}

void MainWindow::on_M_button_12_pressed()
{

    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap greenleft("D:/DS Project Stuff/Images/vw3leftgreen.png");


    ui->M_line12_13->setPixmap(greenleft);
    ui->M_line10_12->setPixmap(normalright);

    ui->M_weight10_12->setStyleSheet(WHITE);
    ui->M_weight12_13->setStyleSheet(GREEN);
    ui->M_finishButton->setEnabled(true);
    ui->M_button_10->setEnabled(false);
    ui->M_button_12->setEnabled(false);
    money -= med_graph.get_weight(10,12);
    ui->M_money_label->setText(QString("Money : ").append(QString::number(money)));
    update_from(12);

}


void MainWindow::on_M_finishButton_pressed()
{
    ui->M_startgame_button->setEnabled(true);
    ui->M_finishButton->setEnabled(false);
    ui->M_button_10->setEnabled(false);
    ui->M_button_11->setEnabled(false);
    ui->M_button_12->setEnabled(false);

    ui->M_weight11_10->setStyleSheet(WHITE);
    ui->M_weight11_13->setStyleSheet(WHITE);
    ui->M_weight12_13->setStyleSheet(WHITE);
    QPixmap normalright("D:/DS Project Stuff/Images/vw3right.png");
    QPixmap normalleft("D:/DS Project Stuff/Images/vw3left.png");


    ui->M_line11_13->setPixmap(normalright);
    ui->M_line12_13->setPixmap(normalleft);
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
        ui->winner_label->setText("You Win");
        ui->stackedWidget->setCurrentIndex(3);
        ui->nextLevel_button->setEnabled(true);

    }
}

void MainWindow::on_M_copy_seed_pressed()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(make_number(-num));
    QMessageBox msg;
    msg.setText("copied");
    msg.exec();
}




