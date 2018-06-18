#include "phase_changer.h"
#include "surface.h"
#include <QKeyEvent>
#include <QGraphicsScene>

phase_changer::phase_changer(QGraphicsView * _view) : my_view(_view), phase(1), xvelocity(0), yvelocity(-1), yacceleration(-1) { //set phase to 1 (solid), x,y velocities to 0

    //setRect(0,0,40,40); //set player's size

    setPixmap(QPixmap(":/images/my_ice_3.png"));

    ytimer = new QTimer(this); //timer for lateral movement
    xtimer = new QTimer(this); //timer for vertical movement

    connect(ytimer, SIGNAL(timeout()), this, SLOT(vertical_movement())); //connect ytimer to vertical move() function
    connect(xtimer, SIGNAL(timeout()), this, SLOT(traverse())); //connect xtimer to lateral traverse() function
    connect(xtimer, SIGNAL(timeout()), this, SLOT(update_view())); //connect xtimer to lateral traverse() function

    ytimer->start(30); //set ytimer interval
    xtimer->start(1); //set xtimer interval

    playersounds = new QMediaPlayer();
    playersounds->setMedia(QUrl("qrc:/sounds/swoosh.mp3"));
    playersounds->setVolume(30);
}

void phase_changer::keyPressEvent(QKeyEvent *event) { //when a key is pressed

    if (event->key() == Qt::Key_Left) { // if LEFT

//        if (right == false) {
//            right = true;
//        }

//        if (scene()->itemAt(x(), y()+5, QTransform()) ) {
//            xvelocity = 0;
//        } else {
//            xvelocity = -1;
//        }
        if (phase == 0 ) {
            setPixmap(QPixmap(":/images/jeremiahs_poodle.png").transformed(QTransform().scale(-1,1)));
        }
        if (phase == 2 ) {
            setPixmap(QPixmap(":/images/bluebubble.png").scaled(55,50));
        }
            xvelocity = -1;

    } else if (event->key() == Qt::Key_Right) { // else if RIGHT

//        if (left == false) {
//            left = true;
//        }
//        for (int ypos = y() + 4; ypos != y() + 40; ++ypos){
//            if (scene()->itemAt(x() + 51, ypos, QTransform())){
//                xvelocity = 0;
//                return;
//            }
//        }

//        if (scene()->itemAt(x()+50, y()+5, QTransform()) ) {
//            xvelocity = 0;
//        } else {
        if (phase == 2 ) {
            setPixmap(QPixmap(":/images/bluebubble.png").scaled(55,50).transformed(QTransform().scale(-1,1)));
        }
        if (phase == 0 ) {
            setPixmap(QPixmap(":/images/jeremiahs_poodle.png"));
        }
        xvelocity = 1;

//        }

    } else if (event->key() == Qt::Key_Up) { // else if UP

        if ( phase == 0 ) { //if liquid
            setPixmap(QPixmap(":/images/my_ice_3.png"));
            setPos(x(), y() -40);
            phase = 1; //set to solid
            yvelocity = -1; //accelerate down
            yacceleration = -1;

        } else if (phase == 1 ) { //if solid
            setPixmap(QPixmap(":/images/bluebubble.png").scaled(55,50));
            phase = 2; //set to gas
            yvelocity = 1; //accelerate up
            yacceleration = 1;

            setPos(x(), y()-4); //boost to come out of contact with ground (fix this)
        }

    } else if (event->key() == Qt::Key_Down) { // else if DOWN

        if ( phase == 2 ) { //if gas
            setPixmap(QPixmap(":/images/my_ice_3.png"));
            phase = 1; //set to solid
            yvelocity = -1; //accelerate down
            yacceleration = -1;
            //setPos(x(), y()+2);

        } else if (phase == 1 ) { //if solid
            setPixmap(QPixmap(":/images/jeremiahs_poodle.png"));
            setPos(x(), y()+40);
            phase = 0; //set liquid
            yvelocity = -1; //keep downward acceleration
            yacceleration = -1;
          //  setPos(x(), y() + 2);
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

void phase_changer::vertical_movement()
{
    if(yacceleration < 0) {
        if (yvelocity < 0) {
            ytimer->setInterval(1);
            setPos(x(), y() + 3);
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
}

void phase_changer::update_view()
{
    my_view->centerOn(this);
}

