/********************************************************************************
** Form generated from reading UI file 'othello.ui'
**
** Created: Mon Dec 3 02:19:35 2012
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHELLO_H
#define UI_OTHELLO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Othello
{
public:
    QAction *actionNew_Game;
    QAction *actionHow_to_play;
    QAction *actionAbout;
    QAction *actionExit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Othello)
    {
        if (Othello->objectName().isEmpty())
            Othello->setObjectName(QString::fromUtf8("Othello"));
        Othello->resize(326, 366);
        actionNew_Game = new QAction(Othello);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        actionHow_to_play = new QAction(Othello);
        actionHow_to_play->setObjectName(QString::fromUtf8("actionHow_to_play"));
        actionAbout = new QAction(Othello);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit = new QAction(Othello);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(Othello);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Othello->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Othello);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 326, 22));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        Othello->setMenuBar(menuBar);
        statusBar = new QStatusBar(Othello);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Othello->setStatusBar(statusBar);

        menuBar->addAction(menuGame->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuGame->addAction(actionNew_Game);
        menuGame->addSeparator();
        menuGame->addAction(actionExit);
        menuAbout->addAction(actionHow_to_play);
        menuAbout->addAction(actionAbout);

        retranslateUi(Othello);

        QMetaObject::connectSlotsByName(Othello);
    } // setupUi

    void retranslateUi(QMainWindow *Othello)
    {
        Othello->setWindowTitle(QApplication::translate("Othello", "Othello", 0, QApplication::UnicodeUTF8));
        actionNew_Game->setText(QApplication::translate("Othello", "New Game", 0, QApplication::UnicodeUTF8));
        actionNew_Game->setShortcut(QApplication::translate("Othello", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionHow_to_play->setText(QApplication::translate("Othello", "How to play", 0, QApplication::UnicodeUTF8));
        actionHow_to_play->setShortcut(QApplication::translate("Othello", "F1", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("Othello", "About", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("Othello", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("Othello", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        menuGame->setTitle(QApplication::translate("Othello", "Game", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("Othello", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Othello: public Ui_Othello {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHELLO_H
