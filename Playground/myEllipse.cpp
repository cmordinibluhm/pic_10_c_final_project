#include "myEllipse.h"
#include <QKeyEvent>
#include <QTimer>

myEllipse::myEllipse() {
    //set size
    setRect(150,250,50,50);

}


void myEllipse::keyPressEvent(QKeyEvent *event) {
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

void myEllipse::move() {
    //move bullet right
    setPos(x()+10,y());
}
