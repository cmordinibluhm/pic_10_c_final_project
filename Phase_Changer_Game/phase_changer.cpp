#include "phase_changer.h"
#include <QKeyEvent>
#include "surface.h"

phase_changer::phase_changer() : phase(1), xvelocity(0), yvelocity(0) {
    //set size
    setRect(0,0,50,50);
    timer = new QTimer(this);

    //QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(traverse()));
    timer->start(30);

}

void phase_changer::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        xvelocity = -1;
       // setPos(x()-5, y());

    } else if (event->key() == Qt::Key_Right) {
        xvelocity = 1;
      //  setPos(x()+5, y());

    } else if (event->key() == Qt::Key_Up) {

        if ( phase == 0 ) {
            phase = 1;

        } else if (phase == 1 ) {
            phase = 2;
        }

    } else if (event->key() == Qt::Key_Down) {

        if ( phase == 2 ) {
            phase = 1;
        } else if (phase == 1 ) {
            phase = 0;
        }

    } else if (event->key() == Qt::Key_Space) {

        if (phase == 1) {
            phase = 2;

        } else if (phase == 2) {
            phase = 1;
        }
    }

}

void phase_changer::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) {
        xvelocity = 0;
    }
}

void phase_changer::move()
{
    if (phase == 1 || phase == 0) { //if the phase is solid or liquid
        timer->setInterval(10);
        fall();
    } else if (phase == 2) {
        timer->setInterval(30);
        rise();
    }
}

void phase_changer::traverse()
{
    if (xvelocity < 0) {
        setPos(x()-5, y());
    } else if (xvelocity > 0) {
        setPos(x()+5, y());
    }
}

void phase_changer::fall()
{
    if (this->collidingItems().isEmpty()) {
        setPos(x(), y()+4);
    }
    if (!this->collidingItems().isEmpty()) {
        setPos(x(), y() -4);
    }
}

void phase_changer::rise()
{
    if (this->collidingItems().isEmpty()){
        setPos(x(), y()-2);
    }
    if (!this->collidingItems().isEmpty()) {
        setPos(x(), y()+2);
    }
}
