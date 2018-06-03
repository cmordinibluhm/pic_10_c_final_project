#include "phase_changer.h"
#include <QKeyEvent>
#include <QTimer>

phase_changer::phase_changer() {
    //set size
    setRect(0,0,50,50);

}

void phase_changer::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        setPos(x()-10, y());

    } else if (event->key() == Qt::Key_Right) {
        setPos(x()+10, y());

    } else if (event->key() == Qt::Key_Up) {
        setPos(x(), y()-10);

    } else if (event->key() == Qt::Key_Down) {
        setPos(x(), y()+10);

    } else if (event->key() == Qt::Key_Space) {
        //connect
        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));

        timer->start(100);
    }

}

void phase_changer::move() {
    //move bullet right
    setPos(x()+10,y());

}
