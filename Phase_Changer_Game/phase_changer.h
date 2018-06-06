#ifndef PHASE_CHANGER_H
#define PHASE_CHANGER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>

class phase_changer : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
private:
    int phase; //the current state of matter- 0 for liquid, 1 for solid, 2 for gas


    QTimer * xtimer; //timer for the player's movement
    QTimer * ytimer;

public:
    int xvelocity; //the horizontal velocity
    int yvelocity; //the vertical velocity
    int yacceleration;

    phase_changer(); //constructor

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

public slots:

    void traverse(); //horizontal movement
    void fall(); //solid/liquid vertical movement

};



#endif // PHASE_CHANGER_H
