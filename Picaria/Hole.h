#ifndef HOLE_H
#define HOLE_H

#include <QPushButton>
#include <QVector>

class Hole : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int row READ row WRITE setRow)
    Q_PROPERTY(int col READ col WRITE setCol)
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(Hole::State state READ state WRITE setState NOTIFY stateChanged)


public:

    enum State {
        Empty,
        Blue,
        Pink,
        Selectable,
        Selected_blue,
        Selected_pink,
        winner,
    };
    Q_ENUM(State)


    explicit Hole(QWidget *parent = nullptr);
    virtual ~Hole();

    int row() const {
        return m_row;}
    int col() const{
        return m_col;
    }
    void setRow(int row){
        m_row = row;
    }
    void setCol(int col){
        m_col = col;
    }
    void setId(int id){
        m_id = id;
    }
    int id() const{
        return m_id;
    }

    Hole::State state() const { return m_state;}
    void setState(Hole::State m_state);

signals:
    void stateChanged(Hole::State old_state, Hole::State new_state);
private:
    int m_row;
    int m_col;
    int m_id;
    Hole::State m_state;

    static QPixmap state2pixmap(Hole::State state);


private slots:
    void updateHole(Hole::State old_state, Hole::State new_state);

};

#endif // HOLE_H

