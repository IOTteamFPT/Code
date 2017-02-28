#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "musicqlistwidgetitem.h"
#include <QQuickItem>
#include "slist.h"
#include <QMediaPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateDurationInfo(qint64 currentInfo);

private slots:
    void on_pushButton_open_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_next_clicked();

    void on_pushButton_previous_clicked();

    void on_horizontalSlider_duration_sliderMoved(int position);

    void durationChanged(qint64 duration);

    void positionChanged(qint64 position);

    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

    void on_pushButton_play_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_stop_clicked();

    void on_actionSlow_triggered();

    void on_actionFast_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QObject* object;
    slist* myslist = NULL;
    slist* activeslist = NULL;
    slist* tmpactiveslist = NULL;
    QMediaPlayer* player;
    qint64 duration;
};

#endif // MAINWINDOW_H
