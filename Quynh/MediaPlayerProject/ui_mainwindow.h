/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtQuickWidgets/QQuickWidget"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionSlow;
    QAction *actionFast;
    QAction *actionAbout;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_open;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_2;
    QQuickWidget *quickWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_duration;
    QSlider *horizontalSlider_duration;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_play;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_previous;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_next;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(626, 300);
        MainWindow->setMaximumSize(QSize(900, 300));
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(5, 22, 49);\n"
""));
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSlow = new QAction(MainWindow);
        actionSlow->setObjectName(QStringLiteral("actionSlow"));
        actionFast = new QAction(MainWindow);
        actionFast->setObjectName(QStringLiteral("actionFast"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setStyleSheet(QStringLiteral("background-color: rgb(245, 252, 250);"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_open = new QPushButton(centralWidget);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_open->sizePolicy().hasHeightForWidth());
        pushButton_open->setSizePolicy(sizePolicy1);
        pushButton_open->setMinimumSize(QSize(80, 35));
        pushButton_open->setMaximumSize(QSize(80, 35));
        pushButton_open->setStyleSheet(QLatin1String("QPushButton:hover { \n"
"background-color: rgb(186, 189, 182); }\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/open-folder_(1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_open->setIcon(icon);
        pushButton_open->setIconSize(QSize(30, 25));
        pushButton_open->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_open);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_6 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        quickWidget = new QQuickWidget(centralWidget);
        quickWidget->setObjectName(QStringLiteral("quickWidget"));
        quickWidget->setMaximumSize(QSize(700, 300));
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        verticalLayout_2->addWidget(quickWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_duration = new QLabel(centralWidget);
        label_duration->setObjectName(QStringLiteral("label_duration"));
        label_duration->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236);"));

        horizontalLayout_3->addWidget(label_duration);

        horizontalSlider_duration = new QSlider(centralWidget);
        horizontalSlider_duration->setObjectName(QStringLiteral("horizontalSlider_duration"));
        horizontalSlider_duration->setStyleSheet(QStringLiteral(""));
        horizontalSlider_duration->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_duration);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_play = new QPushButton(centralWidget);
        pushButton_play->setObjectName(QStringLiteral("pushButton_play"));
        sizePolicy1.setHeightForWidth(pushButton_play->sizePolicy().hasHeightForWidth());
        pushButton_play->setSizePolicy(sizePolicy1);
        pushButton_play->setMinimumSize(QSize(60, 35));
        pushButton_play->setMaximumSize(QSize(60, 35));
        pushButton_play->setStyleSheet(QLatin1String("QPushButton:hover { \n"
"background-color: rgb(186, 189, 182); }\n"
"\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/play-button_(1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_play->setIcon(icon1);
        pushButton_play->setIconSize(QSize(30, 20));
        pushButton_play->setFlat(true);

        horizontalLayout->addWidget(pushButton_play);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_previous = new QPushButton(centralWidget);
        pushButton_previous->setObjectName(QStringLiteral("pushButton_previous"));
        sizePolicy1.setHeightForWidth(pushButton_previous->sizePolicy().hasHeightForWidth());
        pushButton_previous->setSizePolicy(sizePolicy1);
        pushButton_previous->setMinimumSize(QSize(40, 35));
        pushButton_previous->setMaximumSize(QSize(40, 35));
        pushButton_previous->setStyleSheet(QLatin1String("QPushButton:hover { \n"
"background-color: rgb(186, 189, 182); }\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/fast-rewind-button_(1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_previous->setIcon(icon2);
        pushButton_previous->setIconSize(QSize(35, 20));
        pushButton_previous->setFlat(true);

        horizontalLayout->addWidget(pushButton_previous);

        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        sizePolicy1.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy1);
        pushButton_stop->setMinimumSize(QSize(40, 35));
        pushButton_stop->setMaximumSize(QSize(40, 35));
        pushButton_stop->setStyleSheet(QLatin1String("QPushButton:hover { \n"
"background-color: rgb(186, 189, 182); }\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/stop-button_(1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon3);
        pushButton_stop->setIconSize(QSize(35, 15));
        pushButton_stop->setFlat(true);

        horizontalLayout->addWidget(pushButton_stop);

        pushButton_next = new QPushButton(centralWidget);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));
        sizePolicy1.setHeightForWidth(pushButton_next->sizePolicy().hasHeightForWidth());
        pushButton_next->setSizePolicy(sizePolicy1);
        pushButton_next->setMinimumSize(QSize(40, 35));
        pushButton_next->setMaximumSize(QSize(40, 35));
        pushButton_next->setStyleSheet(QLatin1String("QPushButton:hover { \n"
"background-color: rgb(186, 189, 182); }\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/fast-forward-button_(1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_next->setIcon(icon4);
        pushButton_next->setIconSize(QSize(35, 20));
        pushButton_next->setFlat(true);

        horizontalLayout->addWidget(pushButton_next);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 626, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);
        menuView->addAction(actionSlow);
        menuView->addAction(actionFast);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Music Player IOT", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionSlow->setText(QApplication::translate("MainWindow", "Slow", Q_NULLPTR));
        actionFast->setText(QApplication::translate("MainWindow", "Fast", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        pushButton_open->setText(QString());
        label_duration->setText(QApplication::translate("MainWindow", "__:__", Q_NULLPTR));
        pushButton_play->setText(QString());
        pushButton_previous->setText(QString());
        pushButton_stop->setText(QString());
        pushButton_next->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
