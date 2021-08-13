/********************************************************************************
** Form generated from reading UI file 'picaria.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICARIA_H
#define UI_PICARIA_H

#include <Hole.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Picaria
{
public:
    QAction *n_game;
    QAction *game09_buracos;
    QAction *game13_buracos;
    QAction *aboutGame;
    QAction *actionSair;
    QWidget *centralwidget;
    Hole *Hole00;
    Hole *Hole02;
    Hole *Hole04;
    Hole *Hole22;
    Hole *Hole24;
    Hole *Hole20;
    Hole *Hole42;
    Hole *Hole44;
    Hole *Hole40;
    Hole *Hole11;
    Hole *Hole31;
    Hole *Hole13;
    Hole *Hole33;
    QMenuBar *menubar;
    QMenu *menuJogo;
    QMenu *menuModo;
    QMenu *menuSobre;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Picaria)
    {
        if (Picaria->objectName().isEmpty())
            Picaria->setObjectName(QString::fromUtf8("Picaria"));
        Picaria->resize(400, 440);
        Picaria->setMinimumSize(QSize(400, 440));
        Picaria->setMaximumSize(QSize(400, 440));
        Picaria->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        n_game = new QAction(Picaria);
        n_game->setObjectName(QString::fromUtf8("n_game"));
        n_game->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/selectable"), QSize(), QIcon::Normal, QIcon::Off);
        n_game->setIcon(icon);
        n_game->setShortcutContext(Qt::WidgetShortcut);
        game09_buracos = new QAction(Picaria);
        game09_buracos->setObjectName(QString::fromUtf8("game09_buracos"));
        game09_buracos->setCheckable(false);
        game09_buracos->setChecked(false);
        game09_buracos->setEnabled(true);
        game09_buracos->setIcon(icon);
        game13_buracos = new QAction(Picaria);
        game13_buracos->setObjectName(QString::fromUtf8("game13_buracos"));
        game13_buracos->setCheckable(false);
        game13_buracos->setIcon(icon);
        aboutGame = new QAction(Picaria);
        aboutGame->setObjectName(QString::fromUtf8("aboutGame"));
        aboutGame->setEnabled(true);
        aboutGame->setIcon(icon);
        aboutGame->setIconVisibleInMenu(true);
        actionSair = new QAction(Picaria);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        actionSair->setIcon(icon);
        centralwidget = new QWidget(Picaria);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(16777215, 16777215));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"	background: url(':grid');\n"
"}"));
        Hole00 = new Hole(centralwidget);
        Hole00->setObjectName(QString::fromUtf8("Hole00"));
        Hole00->setEnabled(true);
        Hole00->setGeometry(QRect(-10, 0, 100, 100));
        Hole00->setMinimumSize(QSize(100, 100));
        Hole00->setMaximumSize(QSize(100, 100));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/empty"), QSize(), QIcon::Normal, QIcon::Off);
        Hole00->setIcon(icon1);
        Hole00->setIconSize(QSize(70, 70));
        Hole00->setAutoRepeatDelay(300);
        Hole00->setFlat(true);
        Hole00->setProperty("row", QVariant(0));
        Hole00->setProperty("col", QVariant(0));
        Hole00->setProperty("id", QVariant(0));
        Hole02 = new Hole(centralwidget);
        Hole02->setObjectName(QString::fromUtf8("Hole02"));
        Hole02->setGeometry(QRect(150, 0, 100, 100));
        Hole02->setMinimumSize(QSize(100, 100));
        Hole02->setMaximumSize(QSize(100, 100));
        Hole02->setIcon(icon1);
        Hole02->setIconSize(QSize(70, 70));
        Hole02->setAutoRepeatDelay(300);
        Hole02->setFlat(true);
        Hole02->setProperty("row", QVariant(0));
        Hole02->setProperty("col", QVariant(2));
        Hole02->setProperty("id", QVariant(1));
        Hole04 = new Hole(centralwidget);
        Hole04->setObjectName(QString::fromUtf8("Hole04"));
        Hole04->setGeometry(QRect(310, 0, 100, 100));
        Hole04->setMinimumSize(QSize(100, 100));
        Hole04->setMaximumSize(QSize(100, 100));
        Hole04->setIcon(icon1);
        Hole04->setIconSize(QSize(70, 70));
        Hole04->setAutoRepeatDelay(300);
        Hole04->setFlat(true);
        Hole04->setProperty("row", QVariant(0));
        Hole04->setProperty("col", QVariant(4));
        Hole04->setProperty("id", QVariant(2));
        Hole22 = new Hole(centralwidget);
        Hole22->setObjectName(QString::fromUtf8("Hole22"));
        Hole22->setGeometry(QRect(150, 150, 100, 100));
        Hole22->setMinimumSize(QSize(100, 100));
        Hole22->setMaximumSize(QSize(100, 100));
        Hole22->setIcon(icon1);
        Hole22->setIconSize(QSize(70, 70));
        Hole22->setAutoRepeatDelay(300);
        Hole22->setFlat(true);
        Hole22->setProperty("row", QVariant(2));
        Hole22->setProperty("col", QVariant(2));
        Hole22->setProperty("id", QVariant(6));
        Hole24 = new Hole(centralwidget);
        Hole24->setObjectName(QString::fromUtf8("Hole24"));
        Hole24->setGeometry(QRect(310, 150, 100, 100));
        Hole24->setMinimumSize(QSize(100, 100));
        Hole24->setMaximumSize(QSize(100, 100));
        Hole24->setIcon(icon1);
        Hole24->setIconSize(QSize(70, 70));
        Hole24->setAutoRepeatDelay(300);
        Hole24->setFlat(true);
        Hole24->setProperty("row", QVariant(2));
        Hole24->setProperty("col", QVariant(4));
        Hole24->setProperty("id", QVariant(7));
        Hole20 = new Hole(centralwidget);
        Hole20->setObjectName(QString::fromUtf8("Hole20"));
        Hole20->setGeometry(QRect(-10, 150, 100, 100));
        Hole20->setMinimumSize(QSize(100, 100));
        Hole20->setMaximumSize(QSize(100, 100));
        Hole20->setIcon(icon1);
        Hole20->setIconSize(QSize(70, 70));
        Hole20->setAutoRepeatDelay(300);
        Hole20->setFlat(true);
        Hole20->setProperty("row", QVariant(2));
        Hole20->setProperty("col", QVariant(0));
        Hole20->setProperty("id", QVariant(5));
        Hole42 = new Hole(centralwidget);
        Hole42->setObjectName(QString::fromUtf8("Hole42"));
        Hole42->setGeometry(QRect(150, 300, 100, 100));
        Hole42->setMinimumSize(QSize(100, 100));
        Hole42->setMaximumSize(QSize(100, 100));
        Hole42->setIcon(icon1);
        Hole42->setIconSize(QSize(70, 70));
        Hole42->setAutoRepeatDelay(300);
        Hole42->setFlat(true);
        Hole42->setProperty("row", QVariant(4));
        Hole42->setProperty("col", QVariant(2));
        Hole42->setProperty("id", QVariant(11));
        Hole44 = new Hole(centralwidget);
        Hole44->setObjectName(QString::fromUtf8("Hole44"));
        Hole44->setGeometry(QRect(310, 300, 100, 100));
        Hole44->setMinimumSize(QSize(100, 100));
        Hole44->setMaximumSize(QSize(100, 100));
        Hole44->setIcon(icon1);
        Hole44->setIconSize(QSize(70, 70));
        Hole44->setAutoRepeatDelay(300);
        Hole44->setFlat(true);
        Hole44->setProperty("row", QVariant(4));
        Hole44->setProperty("col", QVariant(4));
        Hole44->setProperty("id", QVariant(12));
        Hole40 = new Hole(centralwidget);
        Hole40->setObjectName(QString::fromUtf8("Hole40"));
        Hole40->setGeometry(QRect(-10, 300, 100, 100));
        Hole40->setMinimumSize(QSize(100, 100));
        Hole40->setMaximumSize(QSize(100, 100));
        Hole40->setIcon(icon1);
        Hole40->setIconSize(QSize(70, 70));
        Hole40->setAutoRepeatDelay(300);
        Hole40->setFlat(true);
        Hole40->setProperty("row", QVariant(4));
        Hole40->setProperty("col", QVariant(0));
        Hole40->setProperty("id", QVariant(10));
        Hole11 = new Hole(centralwidget);
        Hole11->setObjectName(QString::fromUtf8("Hole11"));
        Hole11->setGeometry(QRect(70, 70, 100, 100));
        Hole11->setMinimumSize(QSize(100, 100));
        Hole11->setMaximumSize(QSize(100, 100));
        Hole11->setIcon(icon1);
        Hole11->setIconSize(QSize(70, 70));
        Hole11->setAutoRepeatDelay(300);
        Hole11->setFlat(true);
        Hole11->setProperty("row", QVariant(1));
        Hole11->setProperty("col", QVariant(1));
        Hole11->setProperty("id", QVariant(3));
        Hole31 = new Hole(centralwidget);
        Hole31->setObjectName(QString::fromUtf8("Hole31"));
        Hole31->setGeometry(QRect(70, 230, 100, 100));
        Hole31->setMinimumSize(QSize(100, 100));
        Hole31->setMaximumSize(QSize(100, 100));
        Hole31->setIcon(icon1);
        Hole31->setIconSize(QSize(70, 70));
        Hole31->setAutoRepeatDelay(300);
        Hole31->setFlat(true);
        Hole31->setProperty("row", QVariant(3));
        Hole31->setProperty("col", QVariant(1));
        Hole31->setProperty("id", QVariant(8));
        Hole13 = new Hole(centralwidget);
        Hole13->setObjectName(QString::fromUtf8("Hole13"));
        Hole13->setGeometry(QRect(230, 70, 100, 100));
        Hole13->setMinimumSize(QSize(100, 100));
        Hole13->setMaximumSize(QSize(100, 100));
        Hole13->setIcon(icon1);
        Hole13->setIconSize(QSize(70, 70));
        Hole13->setAutoRepeatDelay(300);
        Hole13->setFlat(true);
        Hole13->setProperty("row", QVariant(1));
        Hole13->setProperty("col", QVariant(3));
        Hole13->setProperty("id", QVariant(4));
        Hole33 = new Hole(centralwidget);
        Hole33->setObjectName(QString::fromUtf8("Hole33"));
        Hole33->setGeometry(QRect(230, 230, 100, 100));
        Hole33->setMinimumSize(QSize(100, 100));
        Hole33->setMaximumSize(QSize(100, 100));
        Hole33->setIcon(icon1);
        Hole33->setIconSize(QSize(70, 70));
        Hole33->setAutoRepeatDelay(300);
        Hole33->setFlat(true);
        Hole33->setProperty("row", QVariant(3));
        Hole33->setProperty("col", QVariant(3));
        Hole33->setProperty("id", QVariant(9));
        Picaria->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Picaria);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 20));
        menuJogo = new QMenu(menubar);
        menuJogo->setObjectName(QString::fromUtf8("menuJogo"));
        menuModo = new QMenu(menubar);
        menuModo->setObjectName(QString::fromUtf8("menuModo"));
        menuSobre = new QMenu(menubar);
        menuSobre->setObjectName(QString::fromUtf8("menuSobre"));
        Picaria->setMenuBar(menubar);
        statusbar = new QStatusBar(Picaria);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Picaria->setStatusBar(statusbar);

        menubar->addAction(menuJogo->menuAction());
        menubar->addAction(menuModo->menuAction());
        menubar->addAction(menuSobre->menuAction());
        menuJogo->addSeparator();
        menuJogo->addAction(n_game);
        menuJogo->addAction(actionSair);
        menuModo->addAction(game09_buracos);
        menuModo->addAction(game13_buracos);
        menuSobre->addAction(aboutGame);

        retranslateUi(Picaria);

        QMetaObject::connectSlotsByName(Picaria);
    } // setupUi

    void retranslateUi(QMainWindow *Picaria)
    {
        Picaria->setWindowTitle(QCoreApplication::translate("Picaria", "Picaria", nullptr));
        n_game->setText(QCoreApplication::translate("Picaria", "New game", nullptr));
        game09_buracos->setText(QCoreApplication::translate("Picaria", "9 Holes", nullptr));
        game13_buracos->setText(QCoreApplication::translate("Picaria", "13 Holes", nullptr));
        aboutGame->setText(QCoreApplication::translate("Picaria", "About", nullptr));
        actionSair->setText(QCoreApplication::translate("Picaria", "Exit", nullptr));
        menuJogo->setTitle(QCoreApplication::translate("Picaria", "Picaria", nullptr));
        menuModo->setTitle(QCoreApplication::translate("Picaria", "Mode", nullptr));
        menuSobre->setTitle(QCoreApplication::translate("Picaria", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Picaria: public Ui_Picaria {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICARIA_H
