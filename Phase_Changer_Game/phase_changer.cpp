#include "phase_changer.h"
#include "surface.h"
#include <QKeyEvent>
#include <QGraphicsScene>

phase_changer::phase_changer(QGraphicsView * _view) : my_view(_view), phase(1), xvelocity(0), yvelocity(-1), yacceleration(-1),
distance_risen(300) { //set phase to 1 (solid), x,y velocities to 0

    setPixmap(QPixmap(":/images/my_ice_3.png"));

    xtimer = new QTimer(this); //timer for lateral movement
    ytimer = new QTimer(this); //timer for vertical movement

    connect(ytimer, SIGNAL(timeout()), this, SLOT(vertical_movement())); //connect ytimer to vertical move() function
    connect(xtimer, SIGNAL(timeout()), this, SLOT(traverse())); //connect xtimer to lateral traverse() function
    connect(xtimer, SIGNAL(timeout()), this, SLOT(update_view())); //connect xtimer to lateral traverse() function

    ytimer->start(30); //set ytimer interval
    xtimer->start(15); //set xtimer interval

    playersounds = new QMediaPlayer();
    playersounds->setMedia(QUrl("qrc:/sounds/swoosh.mp3"));
    playersounds->setVolume(30);
}

void phase_changer::keyPressEvent(QKeyEvent *event) { //when a key is pressed

    // LEFT
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left) {

        xvelocity = -1;

        if (phase == 0 ) {
            setPixmap(QPixmap(":/images/jeremiahs_poodle.png").transformed(QTransform().scale(-1,1)));
        }
        if (phase == 2 ) {
            setPixmap(QPixmap(":/images/bluebubble_rightward.png").scaled(52,45).transformed(QTransform().scale(-1,1)));
        }

        setPos(x() - 5, y()); //boost to come out of contact with ground (fix this)

    // RIGHT
    } else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right) {

        xvelocity = 1;

        if (phase == 2 ) {
            setPixmap(QPixmap(":/images/bluebubble_rightward.png").scaled(52,45));
        }
        if (phase == 0 ) {
            setPixmap(QPixmap(":/images/jeremiahs_poodle.png"));
        }

        setPos(x() + 5, y()); //boost to come out of contact with ground (fix this)


    // UP
    } else if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up) {

        if ( phase == 0 ) { //if liquid
            setPixmap(QPixmap(":/images/my_ice_3.png"));
            setPos(x(), y() -40);
            phase = 1; //set to solid
            yvelocity = -1; //accelerate down
            yacceleration = -1;

        } else if (phase == 1 ) { //if solid
            setPixmap(QPixmap(":/images/bluebubble_still.png").scaled(47,47));
            phase = 2; //set to gas
            yvelocity = 1; //accelerate up
            yacceleration = 1;

            setPos(x(), y()-10); //boost to come out of contact with ground (fix this)
        }

    // DOWN
    } else if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down) {

        if ( phase == 2 ) { //if gas
            setPixmap(QPixmap(":/images/my_ice_3.png"));
            phase = 1; //set to solid
            yvelocity = -1; //accelerate down
            yacceleration = -1;

        } else if (phase == 1 ) { //if solid
            setPixmap(QPixmap(":/images/jeremiahs_poodle.png"));
            setPos(x(), y()+40);
            phase = 0; //set liquid
            yvelocity = -1; //keep downward acceleration
            yacceleration = -1;
        }
    }
}

void phase_changer::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_D || event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) {
        xvelocity = 0;

        if (phase == 2) {
            setPixmap(QPixmap(":/images/bluebubble_still.png").scaled(47,47));
        }

    }
}

void phase_changer::traverse() {

    if (xvelocity < 0) {
        setPos(x()-3, y());

    } else if (xvelocity > 0) {
        setPos(x()+3, y());
    }
}

void phase_changer::vertical_movement() {

    if(yacceleration < 0) {
        if (yvelocity < 0) {
            ytimer->setInterval(15);
            setPos(x(), y() + 3);
        } else {
            yvelocity = -1;
        }
    } else if (yacceleration > 0){
        if (yvelocity > 0 && distance_risen < 300) {
            ytimer->setInterval(30);
            setPos(x(), y() - 2);
            distance_risen += 2;
        } else {
            yvelocity = 1;
        }
    }
}

void phase_changer::update_view()
{
    my_view->centerOn(this);
}
