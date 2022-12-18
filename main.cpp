#include "mainwindow.h"
#include "qaudiooutput.h"
#include "qmediaplayer.h"

#include <QApplication>

QMediaPlayer * music = new QMediaPlayer();
QAudioOutput * musicoutput = new QAudioOutput();

QMediaPlayer * buttonsfx = new QMediaPlayer();
QAudioOutput * sfxoutput = new QAudioOutput();

QMediaPlayer * levelButtons = new QMediaPlayer();
QAudioOutput * leveloutput = new QAudioOutput();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


