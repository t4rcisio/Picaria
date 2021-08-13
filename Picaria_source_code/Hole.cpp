#include "Hole.h"

using namespace std;

Hole::Hole(QWidget *parent)
    : QPushButton(parent), m_row(0),m_col(0), m_state(Hole::Empty){
    QObject::connect(this, SIGNAL(stateChanged(Hole::State,Hole::State)),
                     this, SLOT(updateHole(Hole::State, Hole::State)));

}

Hole::~Hole(){

}

void Hole::setState(Hole::State state){
    if(m_state != state){
        Hole::State old = m_state;

        m_state = state;
        emit stateChanged(old, state);
    }
}

QPixmap Hole::state2pixmap(Hole::State state){
    switch (state) {
        case  Hole::Empty:
            return QPixmap(":/empty"); break;
        case  Hole::Blue:
            return QPixmap(":/blue"); break;
        case  Hole::Pink:
            return QPixmap(":/pink"); break;
        case  Hole::Selectable:
            return QPixmap(":/selectable"); break;
        case  Hole::Selected_pink:
            return QPixmap(":/selected_pink"); break;
        case  Hole::Selected_blue:
            return QPixmap(":/selected_blue"); break;
        case Hole::winner:
            return QPixmap(":/selected_blue"); break;

    default:
        return QPixmap(":/empty"); break;
    }
}

void Hole::updateHole(Hole::State old_state, Hole::State new_state){
    Q_UNUSED(old_state);

    this->setIcon(Hole::state2pixmap(new_state));
}
