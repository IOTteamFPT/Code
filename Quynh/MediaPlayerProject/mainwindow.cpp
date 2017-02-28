#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QStringList>
#include <QString>
#include <iostream>
#include <music.h>
#include <musicqlistwidgetitem.h>
#include "slist.h"
#include <QQuickItem>
#include <QGenericArgument>
#include <QMediaPlayer>
#include <QTime>
#include "dialog.h"
bool isItemSameName (void* src, void* dst) {
    return !strcmp (((MusicQListWidgetItem*)src)->getPath(), ((MusicQListWidgetItem*)dst)->getPath());
}

void freeItem (void* item){
    delete (MusicQListWidgetItem*) item;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl::fromLocalFile("Transition.qml"));
    ui->quickWidget->show();
    object = ui->quickWidget->rootObject();
    player = new QMediaPlayer;
    connect(player,SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT (positionChanged(qint64)));
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));
    ui->horizontalSlider_duration->setRange(0, player->duration());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete player;
    delete object;
}

void MainWindow::on_pushButton_open_clicked()
{
    QStringList pathfiles = QFileDialog::getOpenFileNames(
          this,
          tr("Open Document"),
          QDir::currentPath(),
          tr("Music (*.mp3);;") );

    myslist = slist_delete_all_x(myslist, freeItem);

    for (int i = 0; i < pathfiles.size(); ++i) {
        QFileInfo fileInfo(pathfiles[i]);
        QListWidgetItem *item = new MusicQListWidgetItem(fileInfo.fileName(),
                                                           fileInfo.fileName().toStdString().c_str(),
                                                           fileInfo.filePath().toStdString().c_str());
        ui->listWidget->addItem(item);
        myslist = slist_append(myslist, (void*)item);
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString listpic[3];
    MusicQListWidgetItem* castitem = dynamic_cast <MusicQListWidgetItem*> (item);
    activeslist = slist_find (myslist, castitem, isItemSameName);
    tmpactiveslist = activeslist;
    ID3_Tag itemtag;
    itemtag.Link(((MusicQListWidgetItem*)activeslist->data)->getPath(), ID3TT_ALL);
    QString picpath = QString (((MusicQListWidgetItem*)activeslist->data)->getName()) + ".jpg";
    ((MusicQListWidgetItem*)activeslist->data)->setTag(itemtag, picpath.toStdString().c_str());
    listpic[1] = QString (((MusicQListWidgetItem*)activeslist->data)->getTag()->picpath);
    if (activeslist->next) {
        ID3_Tag itemtag;
        itemtag.Link(((MusicQListWidgetItem*)activeslist->next->data)->getPath(), ID3TT_ALL);
        QString picpath = QString (((MusicQListWidgetItem*)activeslist->next->data)->getName()) + ".jpg";
        ((MusicQListWidgetItem*)activeslist->next->data)->setTag(itemtag, picpath.toStdString().c_str());
        listpic[2] = QString(((MusicQListWidgetItem*)activeslist->next->data)->getTag()->picpath);
    }
    if (activeslist->previous) {
        ID3_Tag itemtag;
        itemtag.Link(((MusicQListWidgetItem*)activeslist->previous->data)->getPath(), ID3TT_ALL);
        QString picpath = QString (((MusicQListWidgetItem*)activeslist->previous->data)->getName()) + ".jpg";
        ((MusicQListWidgetItem*)activeslist->previous->data)->setTag(itemtag, picpath.toStdString().c_str());
        listpic[0] = QString(((MusicQListWidgetItem*)activeslist->previous->data)->getTag()->picpath);
    }
    QObject *ob = object->findChild<QObject*> ("page");
    if (ob) {
        QMetaObject::invokeMethod(ob, "showit"
                                  ,Q_ARG(QString, listpic[0] )
                                  ,Q_ARG(QString, listpic[1] )
                                  ,Q_ARG(QString, listpic[2] ));
    }
    QString filepath = QString(((MusicQListWidgetItem*)activeslist->data)->getPath());
    player->setMedia(QUrl::fromLocalFile(filepath));
    player->play();

}

void MainWindow::on_pushButton_next_clicked()
{
    if (activeslist) {
        if (activeslist->next) {
            QString picpath;
            activeslist = activeslist->next;
            tmpactiveslist = activeslist;
            if (activeslist->next) {
                ID3_Tag itemtag;
                itemtag.Link(((MusicQListWidgetItem*)activeslist->next->data)->getPath(), ID3TT_ALL);
                picpath = QString (((MusicQListWidgetItem*)activeslist->next->data)->getName()) + ".jpg";
                ((MusicQListWidgetItem*)activeslist->next->data)->setTag(itemtag, picpath.toStdString().c_str());
                qDebug () << picpath;
            }
            QObject *ob = object->findChild<QObject*> ("page");
            if (ob) {
                QMetaObject::invokeMethod(ob, "pagenext", Q_ARG (QString, picpath));
            }
            QString filepath = QString(((MusicQListWidgetItem*)activeslist->data)->getPath());
            player->setMedia(QUrl::fromLocalFile(filepath));
            player->play();
            ui->listWidget->setCurrentItem((QListWidgetItem*)activeslist->data);
        }
    }
}

void MainWindow::on_pushButton_previous_clicked()
{
    if (activeslist) {
        if (activeslist->previous) {
            QString picpath;
            activeslist = activeslist->previous;
            tmpactiveslist = activeslist;
            if (activeslist->previous) {
                ID3_Tag itemtag;
                itemtag.Link(((MusicQListWidgetItem*)activeslist->previous->data)->getPath(), ID3TT_ALL);
                picpath = QString (((MusicQListWidgetItem*)activeslist->previous->data)->getName()) + ".jpg";
                ((MusicQListWidgetItem*)activeslist->previous->data)->setTag(itemtag, picpath.toStdString().c_str());
                qDebug () << picpath;
            }
            QObject *ob = object->findChild<QObject*> ("page");
            if (ob) {
                QMetaObject::invokeMethod(ob, "pageprevious", Q_ARG (QString, picpath));
            }
            QString filepath = QString(((MusicQListWidgetItem*)activeslist->data)->getPath());
            player->setMedia(QUrl::fromLocalFile(filepath));
            player->play();
            ui->listWidget->setCurrentItem((QListWidgetItem*)activeslist->data);
        }
    }
}

void MainWindow::on_horizontalSlider_duration_sliderMoved(int position)
{
    player->setPosition(position * 1000);
}
void MainWindow::durationChanged(qint64 duration)
{
    this->duration = duration/1000;
    ui->horizontalSlider_duration->setMaximum(duration / 1000);
}

void MainWindow::positionChanged(qint64 position){
    if (!ui->horizontalSlider_duration->isSliderDown()) {
        ui->horizontalSlider_duration->setValue(position/1000);
    }
    updateDurationInfo (position / 1000);
}
void MainWindow::updateDurationInfo(qint64 currentInfo)
{
    QString tStr;
    if (currentInfo || duration) {
        QTime currentTime((currentInfo/3600)%60, (currentInfo/60)%60, currentInfo%60, (currentInfo*1000)%1000);
        QTime totalTime((duration/3600)%60, (duration/60)%60, duration%60, (duration*1000)%1000);
        QString format = "mm:ss";
        if (duration > 3600)
            format = "hh:mm:ss";
        tStr = currentTime.toString(format) + " / " + totalTime.toString(format);
    }
    ui->label_duration->setText(tStr);
}
void MainWindow::mediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if (status == QMediaPlayer::EndOfMedia) {
        on_pushButton_next_clicked();
    }
}

void MainWindow::on_pushButton_play_clicked()
{
    if (activeslist) {
        if (activeslist != tmpactiveslist) {
            activeslist = tmpactiveslist;
            QString listpic[3];
            ID3_Tag itemtag;
            itemtag.Link(((MusicQListWidgetItem*)activeslist->data)->getPath(), ID3TT_ALL);
            QString picpath = QString (((MusicQListWidgetItem*)activeslist->data)->getName()) + ".jpg";
            ((MusicQListWidgetItem*)activeslist->data)->setTag(itemtag, picpath.toStdString().c_str());
            listpic[1] = QString (((MusicQListWidgetItem*)activeslist->data)->getTag()->picpath);
            if (activeslist->next) {
                ID3_Tag itemtag;
                itemtag.Link(((MusicQListWidgetItem*)activeslist->next->data)->getPath(), ID3TT_ALL);
                QString picpath = QString (((MusicQListWidgetItem*)activeslist->next->data)->getName()) + ".jpg";
                ((MusicQListWidgetItem*)activeslist->next->data)->setTag(itemtag, picpath.toStdString().c_str());
                listpic[2] = QString(((MusicQListWidgetItem*)activeslist->next->data)->getTag()->picpath);
            }
            if (activeslist->previous) {
                ID3_Tag itemtag;
                itemtag.Link(((MusicQListWidgetItem*)activeslist->previous->data)->getPath(), ID3TT_ALL);
                QString picpath = QString (((MusicQListWidgetItem*)activeslist->previous->data)->getName()) + ".jpg";
                ((MusicQListWidgetItem*)activeslist->previous->data)->setTag(itemtag, picpath.toStdString().c_str());
                listpic[0] = QString(((MusicQListWidgetItem*)activeslist->previous->data)->getTag()->picpath);
            }
            QObject *ob = object->findChild<QObject*> ("page");
            if (ob) {
                QMetaObject::invokeMethod(ob, "showit"
                                          ,Q_ARG(QString, listpic[0] )
                                          ,Q_ARG(QString, listpic[1] )
                                          ,Q_ARG(QString, listpic[2] ));
            }
            QString filepath = QString(((MusicQListWidgetItem*)activeslist->data)->getPath());
            player->setMedia(QUrl::fromLocalFile(filepath));
            player->play();
            ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(:/icons/pause-button_(1).png);}");
        }
        else if (activeslist == tmpactiveslist) {
            if (player->state() == QMediaPlayer::PausedState || player->state() == QMediaPlayer::StoppedState) {
                player->play();
                ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(:/icons/pause-button_(1).png);}");
            }
            else if (player->state() == QMediaPlayer::PlayingState) {
                player->pause();
                ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(:/icons/play-button_(1).png);}");
            }
        }
    }
    else {
        if (myslist) {
            activeslist = myslist;
            tmpactiveslist = activeslist;
            on_listWidget_itemDoubleClicked((QListWidgetItem*)myslist->data);
            ui->pushButton_play->setStyleSheet("QPushButton {qproperty-icon: url(:/icons/pause-button_(1).png);}");
            ui->listWidget->setCurrentItem((QListWidgetItem*)myslist->data);
        }
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    MusicQListWidgetItem* castitem = dynamic_cast <MusicQListWidgetItem*> (item);
    tmpactiveslist = slist_find (myslist, castitem, isItemSameName);
}

void MainWindow::on_pushButton_stop_clicked()
{
    player->stop();
}


void MainWindow::on_actionSlow_triggered()
{
    QObject *page = object->findChild<QObject*>("page");
    if (page)
        page->setProperty("duration", 2000);
}

void MainWindow::on_actionFast_triggered()
{
    QObject *page = object->findChild<QObject*>("page");
    if (page)
        page->setProperty("duration", 500);
}

void MainWindow::on_actionOpen_triggered()
{
    on_pushButton_open_clicked();
}

void MainWindow::on_actionExit_triggered()
{
     QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    Dialog dialog;
    dialog.exec();
}
