#ifndef PHASE_CHANGER_H
#define PHASE_CHANGER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>

class phase_changer : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
private:
    int phase; //the current state of matter

    int xvelocity; //the horizontal velocity
    int yvelocity; //the vertical velocity

    QTimer * timer; //timer for the player's movement

public:
    phase_changer(); //constructor



    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

public slots:
    void move(); //vertical movement
    void traverse(); //horizontal movement
    void fall(); //solid/liquid vertical movement
    void rise(); //gas vertical movement

signals:


};



#endif // PHASE_CHANGER_H
