#ifndef PICARIA_H
#define PICARIA_H

#include <QMainWindow>
#include "Hole.h"
#include <QVector>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Picaria; }
QT_END_NAMESPACE


class adjacency{

public:
    QVector<int> getAdj(int id_buttom, int gamemode){
        QVector<int> b_arround;
        switch (id_buttom) {
            case 0 :
                if(gamemode)
                b_arround = {1,3,5};
                else
                    b_arround = {1,5,6};
                break;
            case 1 :
                if(gamemode)
                b_arround = {0,2,3,4,6};
                else
                    b_arround = {0,2,6,5,7};
                break;
            case 2 :
                if(gamemode)
                b_arround = {1,4,7};
                else
                    b_arround = {1,7,6};
                break;
            case 3 :
                b_arround = {0,1,5,6}; break;
            case 4 :
                b_arround = {1,2,6,7}; break;
            case 5 :
                if(gamemode)
                b_arround = {0,3,6,8,10};
                else
                    b_arround = {0,1,6,11,10};
                break;
            case 6 :
                if(gamemode)
                b_arround = {1,3,4,5,7,8,9,11};
                else
                    b_arround = {1,0,2,5,7,10,12,11};
                break;
            case 7 :
                if(gamemode)
                b_arround = {2,4,6,9,12};
                else
                   b_arround = {2,1,6,11,12};
                break;
            case 8 :
                b_arround = {5,6,10,11}; break;
            case 9 :
                b_arround = {6,7,11,12}; break;
            case 10 :
                if(gamemode)
                b_arround = {5,8,11};
                else
                    b_arround = {5,6,11};
                break;
            case 11 :
                if(gamemode)
                b_arround = {6,8,9,10,12};
                else
                    b_arround = {5,7,6,10,12};
                break;
            case 12 :
                if(gamemode)
                b_arround = {7,9,11};
                else
                    b_arround = {7,6,11};
                break;
            case 13 :
                b_arround = {2,4,6,8,10}; break;
            case 14 :
                b_arround = {0,3,6,9,12}; break;
            case 20 :
                b_arround = {14,13,0,2,12,10}; break;
        }
        return b_arround;
    }

};

class Rules{

private:
    Hole::State state = Hole::Blue;
    Hole* selected_hole = NULL;
    Hole::State selected_state;
    int counter = 0;
    bool selected = false;
    int gameMode = 1;
    int fase = 0;
    adjacency adj;
    Hole::State winner;
    bool b_winner = false;
public:
    QVector<Hole*> buttons;


public:
    void changeFase(){fase = 1;}

    Hole::State nextPlayer(){
        if(state == Hole::State::Blue)
            state = Hole::State::Pink;

        else
            state = Hole::State::Blue;

        return state;
    }

    QString gameFase(){
        if(fase == 0)
            return "seleção";
        else
            return "movimentação";
    }

    Hole::State getState(){
        return state;
    }
    void setState(Hole::State st){
        state = st;
    }
    QString getStringState(){


        if(state == Hole::Blue)
            return "Miraitowa (AZUL)";
        else
            return "Someity (ROSA)";


    }
    int getGameMode(){return gameMode;}
    void setGameMode(int m_mode){gameMode = m_mode;}

    bool have_a_winner(){return b_winner;}
    void restart_winner(){b_winner = false;}
    Hole::State getWinner(){return winner;}

    bool addCounter(){
        counter = counter + 1;
        if(counter <= 6){
            return true;
        }else
            return false;

    }
    int getCounter(){
        return counter;
    }
    void resetCounter(){counter=0;}

    bool isSelected(){return selected;}

    void setButtonList(QVector<Hole*> m_buttons){
        buttons = m_buttons;
    }

    void setSelectable(){
        QVector<int> neighborhood =  adj.getAdj(selected_hole->id(), gameMode);
        for(int i = 0; i < neighborhood.size(); i++){
            if(buttons[neighborhood[i]]->state() == Hole::Empty){
                buttons[neighborhood[i]]->setState(Hole::Selectable);
             }
        }

    }
    void setEmpty(){
        QVector<int> neighborhood =  adj.getAdj(selected_hole->id(),gameMode);

        for(int i = 0; i < neighborhood.size(); i++){
            if(buttons[neighborhood[i]]->state() == Hole::Selectable)
                buttons[neighborhood[i]]->setState(Hole::Empty);
        }

    }

    void check_selected(Hole *m_hole){

        if(selected_hole == NULL){//Armazena o último botão clicado
            selected_hole = m_hole;
            selected_state = selected_hole->state();
        }else{
            setEmpty();
            selected_hole->setState(selected_state);
            selected_hole = m_hole;
            selected_state = selected_hole->state();
        }
        selected = true;

    }
    Hole::State getSelected_icon(Hole *m_hole){
        if(m_hole->state() == Hole::State::Blue)
            return Hole::Selected_blue;
        else
            return Hole::Selected_pink;
    }

    void MoveHole(Hole *hole){
        hole->setState(selected_state);
        selected_hole->setState(Hole::Empty);
        selected_hole = NULL;
        selected = false;

    }
    void filltable(Hole *table[]){
        for(int line = 0; line < 5; line++){
            for(int column = 0; column < 5; column++){
                table[line][column].setState(Hole::Empty);
            }
        }
    }

    bool checkWin(Hole *table[5][5]){
        int counter = 0;
        for(int i = 0; i <5; i = i=i+2){
            counter = 0;
            for(int j = 0; j <5 ; j = j=j+2){
                if(table[i][0]->state() == table[i][j]->state() && table[i][0]->state() != Hole::Empty){
                    qDebug() << table[i][j]->state();
                    counter++;
                }else{
                    counter = 0;
                }
                //qDebug() << table[i][j]->state() << " ";
            }
            if(counter == 3){
                winner = table[i][0]->state();
                b_winner = true;
                return b_winner;
            }
        }
        for(int i = 0; i <5; i = i=i+2){
            counter = 0;
            for(int j = 0; j <5 ; j = j=j+2){
                if(table[0][i]->state() == table[j][i]->state() && table[0][i]->state() != Hole::Empty){
                    qDebug() << table[i][j]->state();
                    counter++;
                }else{
                    counter = 0;
                }
                //qDebug() << table[i][j]->state() << " ";
            }
            if(counter == 3){
                winner = table[0][i]->state();
                b_winner = true;
                return b_winner;
            }
        }
        if(gameMode){
        counter = 0;
            Hole::State atual_state = Hole::Empty;
            QVector<int> b_list;
            QVector<int> find_list;
            b_list = adj.getAdj(20, gameMode);

            for(int i = 0; i <b_list.size(); i++){
                find_list = adj.getAdj(b_list[i],gameMode);
                counter = 0; atual_state = Hole::Empty;
                for(int j = 0; j < find_list.size(); j++){
                    if(buttons[find_list[j]]->state() != Hole::Empty && buttons[find_list[j]]->state() != atual_state){
                        atual_state = buttons[find_list[j]]->state();
                        counter=0;
                    }
                    if(atual_state == buttons[find_list[j]]->state() && buttons[find_list[j]]->state() != Hole::Empty){
                        qDebug() << "Linha: " << find_list;
                        qDebug() << buttons[find_list[j]]->state();
                        qDebug() << "contagem: "<< counter;
                        counter++;
                    }else{
                        counter = 0;
                        atual_state = Hole::Empty;
                    }
                    if(counter == 3){
                        winner = atual_state;
                        b_winner = true;
                        return b_winner;
                    }
                }
            }
        }else{
            if(buttons[0]->state() == buttons[6]->state() && buttons[0]->state() == buttons[12]->state() && buttons[0]->state() != Hole::Empty){
                winner = buttons[0]->state();
                b_winner = true;
                return b_winner;
            }
            if(buttons[2]->state() == buttons[6]->state() && buttons[2]->state()== buttons[10]->state() && buttons[2]->state() != Hole::Empty ){
                winner = buttons[2]->state();
                b_winner = true;
                return b_winner;
            }
        }
        return false;

    }

};



class Picaria : public QMainWindow
{
    Q_OBJECT

public:
    Picaria(QWidget *parent = nullptr);
    ~Picaria();
    Rules rules;
    Hole  *table[5][5];


private:
    Ui::Picaria *ui;

private slots:
    void play();
    void set13holes();
    void set09holes();
    void reset();
    void selected(Hole *hole);
    void bottomWindow();
    void showAbout();
};
#endif // PICARIA_H
