#include "phase_changer.h"
#include "surface.h"
#include <QKeyEvent>
#include <QGraphicsScene>

phase_changer::phase_changer() : phase(1), xvelocity(0), yvelocity(-1), yacceleration(-1) { //set phase to 1 (solid), x,y velocities to 0

    setRect(0,0,50,50); //set player's size

    ytimer = new QTimer(this); //timer for lateral movement
    xtimer = new QTimer(this); //timer for vertical movement

    connect(ytimer, SIGNAL(timeout()), this, SLOT(fall())); //connect ytimer to vertical move() function
    connect(xtimer, SIGNAL(timeout()), this, SLOT(traverse())); //connect xtimer to lateral traverse() function

    ytimer->start(30); //set ytimer interval
    xtimer->start(1); //set xtimer interval
}

void phase_changer::keyPressEvent(QKeyEvent *event) { //when a key is pressed

    if (event->key() == Qt::Key_Left) { // if LEFT

        if (scene()->itemAt(x(), y()+5, QTransform()) ) {
            xvelocity = 0;
        } else {
            xvelocity = -1;
        }
    } else if (event->key() == Qt::Key_Right) { // else if RIGHT

        if (scene()->itemAt(x()+50, y()+5, QTransform()) ) {
            xvelocity = 0;
        } else {
            xvelocity = 1;
        }

    } else if (event->key() == Qt::Key_Up) { // else if UP

        if ( phase == 0 ) { //if liquid
            phase = 1; //set to solid
            yvelocity = -1; //accelerate down
            yacceleration = -1;

        } else if (phase == 1 ) { //if solid
            phase = 2; //set to gas
            yvelocity = 1; //accelerate up
            yacceleration = 1;

            setPos(x(), y()-4); //boost to come out of contact with ground (fix this)
        }

    } else if (event->key() == Qt::Key_Down) { // else if DOWN

        if ( phase == 2 ) { //if gas
            phase = 1; //set to solid
            yvelocity = -1; //accelerate down
            yacceleration = -1;
            setPos(x(), y()+2);

        } else if (phase == 1 ) { //if solid
            phase = 0; //set liquid
            yvelocity = -1; //keep downward acceleration
            yacceleration == -1;
            setPos(x(), y()+2);
        }
    }
}

void phase_changer::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) {
        xvelocity = 0;
    }
}

void phase_changer::traverse()
{
    if (xvelocity < 0) {
        setPos(x()-2, y());

    } else if (xvelocity > 0) {
        setPos(x()+2, y());
    }
}

void phase_changer::fall()
{
    if(yacceleration < 0) {
        if (yvelocity < 0) {
            ytimer->setInterval(10);
            setPos(x(), y() + 2);
        } else {
            yvelocity = -1;
        }
    } else if (yacceleration > 0){
        if (yvelocity > 0) {
            ytimer->setInterval(30);
            setPos(x(), y() - 2);
        } else {
            yvelocity = 1;
        }
    }
//    if (this->collidingItems().isEmpty()) {
//        setPos(x(), y() + 3);
//    }
//    if (!this->collidingItems().isEmpty()) {
//        setPos(x(), y() -4);
//    }
}

