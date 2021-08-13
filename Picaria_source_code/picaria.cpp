#include "picaria.h"
#include "ui_picaria.h"
#include <QDebug>
#include <QSignalMapper>
#include <QMessageBox>
#include <QVector>





Picaria::Picaria(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Picaria)
{
    Picaria::rules;
    Picaria::table;
    Hole* hole;


    ui->setupUi(this);
    QObject::connect(ui->actionSair,SIGNAL(triggered(bool)),qApp,SLOT(quit()));          // Sair
    QObject::connect(ui->game13_buracos,SIGNAL(triggered(bool)),this,SLOT(set13holes()));// 13 buracos
    QObject::connect(ui->game09_buracos,SIGNAL(triggered(bool)),this,SLOT(set09holes()));// 09 buracos
    QObject::connect(ui->n_game,SIGNAL(toggled(bool)),this,SLOT(reset()));               // Limpa para 13 buracos
    QObject::connect(ui->aboutGame, SIGNAL(triggered(bool)), this, SLOT(showAbout()));
    bottomWindow();

    for(int line = 0, column = 0, id = 0; id<13; column++){

        if(column > 4 && line%2 == 0){
          column = 1;
          line++;
          }if(column > 4){
              line++;
              column = 0;
          }

            hole = this->findChild<Hole*>(QString("Hole%1%2").arg(line).arg(column));
            rules.buttons.push_back(hole);
            table[line][column] = hole;
            QObject::connect(hole,SIGNAL(clicked(bool)),this,SLOT(play()));
        column++;

        id++;
        }

}

Picaria::~Picaria()
{
    delete ui;
}

void Picaria::selected(Hole *hole){
    //Hole* hole = qobject_cast<Hole*>(QObject::sender());
    qDebug() << "Estado : " << hole->state();

    if(hole->state() != Hole::Empty && hole->state() == rules.getState()){
        qDebug() << "Aqui 22";
        rules.check_selected(hole);
        hole->setState(rules.getSelected_icon(hole));
        rules.setSelectable();

    }else{
        if(hole->state() == Hole::Selectable && rules.isSelected()){
            qDebug() << "Aqui 99";
            rules.setEmpty();
            rules.MoveHole(hole);
            rules.nextPlayer();
            if(rules.checkWin(table)){
                qDebug() << "We have a win!";
            }
            qDebug() << "moveButton";
            qDebug() << "Row " << hole->row();
            qDebug() << "Col " << hole->col();
        }

    }


}


void Picaria::play(){
    Hole* hole = qobject_cast<Hole*>(QObject::sender());
    if(hole->state() == Hole::State::Empty && rules.getCounter() <6 && !rules.have_a_winner()){
        rules.addCounter();
        hole->setState(rules.getState());
        if(rules.checkWin(table)){
            qDebug() << "We have a win!";
        }
        qDebug() << "Row " << hole->row();
        qDebug() << "Col " << hole->col();
        qDebug() << "Counter: " << rules.getCounter();
        rules.nextPlayer();
     }
    if(rules.getCounter() == 6){
        rules.changeFase();
        //rules.setState(rules.getState());
        rules.addCounter();

    }else{
        qDebug() << "Contador ff : " << rules.getCounter();
        qDebug() << "Rules state: " << rules.getState();
        if(rules.getCounter() >6 && !rules.have_a_winner() && hole->state() != Hole::Empty){
            selected(hole);
            qDebug() << "Aqui 1";
        }
    }
    bottomWindow();
}

void Picaria::reset(){
    rules.setGameMode(1);
    rules.resetCounter();
    rules.restart_winner();
     for(int line = 0, column = 0, id = 0; id<13; column++){
         if(column > 4 && line%2 == 0){
           column = 1;
           line++;
           }if(column > 4){
               line++;
               column = 0;
           }

                Hole* hole = this->findChild<Hole*>(QString("Hole%1%2").arg(line).arg(column));
                hole->setState(Hole::Empty);
                hole->setVisible(true);
            column++;
            id++;
            }

}

void Picaria:: set09holes(){

    reset();
    rules.setGameMode(0);
    for(int line = 1, column = 1, id = 0; id<4; column++){

            if(column > 4){
                line = 3;
                column = 1;
            }
            Hole* hole = this->findChild<Hole*>(QString("Hole%1%2").arg(line).arg(column));
            hole->setVisible(false);
            column++;
        id++;
        }
}

void Picaria:: set13holes(){
    reset();
    rules.setGameMode(1);
}

void Picaria::bottomWindow () {
 if(rules.have_a_winner()){

     QString arg1(rules.getWinner() == Hole::Blue ? "Miraitowa (AZUL)" : "Someity (ROSA)");
     QMessageBox winnerBox;
     QString a1 = "Fim de jogo - "+arg1+" ganhou!";
     ui->statusbar->showMessage((a1));
     //winnerBox.setText(("Fim de jogo - "+arg1+" ganhou!"));
     //winnerBox.setIconPixmap( QPixmap(":/winner") );


     const QString message ="<p style='text-align: center;'><img src=':/winner'></p>"
                            "<p style='text-align: center;'><strong>"+a1+"</strong></p>";
     winnerBox.setInformativeText(message);
     winnerBox.setWindowIcon(QIcon(":/empty"));
     winnerBox.show();
     winnerBox.exec();



 }
 else{
    QString arg1 = rules.gameFase();
    QString arg2 = rules.getStringState();
    ui->statusbar->showMessage(tr("Fase de %1 - Vez do jogador %2").arg(arg1).arg(arg2));
 }
}

void Picaria::showAbout() {




    QMessageBox AboutBox;
    const QString message = "<p style='text-align: center;'><img width='200' height='200' src=':/logo'></p>"
                            "<h3 style='text-align: center;'><strong>""Author<br>Tarcísio Prates""</strong></h3>"
                            "<h4 style='text-align: center;'><strong>""CEFET-MG, 2021""</strong></h4>"
                            "<h1><HR WIDTH=50%></h1>"
                            "<table><tr><td><img  width='30' height='30' src=':/rules'/></td><td>""<a href='https://en.wikipedia.org/wiki/Picaria'>""Rules and gameplay""</a>""""</td></tr></table>"
                            "<table><tr><td><img  width='30' height='30' src=':/ms'/></td><td>""<a href='https://en.wikipedia.org/wiki/Miraitowa_and_Someity'>""Miraitowa and Someity""</a>""""</td></tr></table>"
                            "<table><tr><td><img  width='30' height='30' src=':/gmail'/></td><td>""<a href='mailto:tarcisiobatistaprates@gmail.com'>""Write for me""</a>""""</td></tr></table>"
                           "<table><tr><td><img  width='30' height='30' src=':/git'/></td><td>""<a href='https://github.com/t4rcisio/Picaria'>""Picaria repository""</a>""""</td></tr></table>"
                           "<p style='text-align: center;'><strong>""</strong></p>";

    AboutBox.setInformativeText(message);
    AboutBox.setWindowIcon(QIcon(":/empty"));
    AboutBox.show();
    AboutBox.exec();
}

