#include "spikes.h"
#include <QPen>
#include <QGraphicsScene>

spikes::spikes(QGraphicsScene * _scene, phase_changer * _player, int x, int y, int size, int orient) : player(_player), scene(_scene)
{
    if (orient == 1) { //upwards facing spikes
        setPolygon( QPolygonF( QVector<QPointF>() << QPointF(x,y) << QPointF(x+size,y) << QPointF(x+size,y-10) <<
                               QPointF(x+(size/2),y-20) << QPointF(x,y-10) ));
    } else if (orient == 2) { //downwards facing spikes
        setPolygon( QPolygonF( QVector<QPointF>() << QPointF(x,y) << QPointF(x+size,y) << QPointF(x+size,y+10) <<
                               QPointF(x+(size/2),y+20) << QPointF(x,y+10) ));
    } else if (orient == 3) { //leftward facing spikes
        setPolygon( QPolygonF( QVector<QPointF>() << QPointF(x,y) << QPointF(x,y+size) << QPointF(x-10,y+size) <<
                               QPointF(x-20, y+(size/2)) << QPointF(x-10,y) ));
    } else { //rightward facing spikes
        setPolygon( QPolygonF( QVector<QPointF>() << QPointF(x,y) << QPointF(x,y+size) << QPointF(x+10,y+size) <<
                               QPointF(x+20,y+(size/2)) << QPointF(x+10,y) ));
    }

    setPen( QPen(Qt::darkRed) );
    setBrush( Qt::red);

    scene->addItem(this);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(check_for_death()));
    timer->start(1);

    death_msg = new QGraphicsTextItem("Your original atoms have been lost.\nTry again. ");
    death_msg->setPos(25,0);
    death_msg->setScale(3);
    death_msg->setDefaultTextColor(Qt::white);
}

void spikes::check_for_death()
{
    if (this->collidesWithItem(player)) {
        player->setPos(25,0);

        QTimer::singleShot(50,this,SLOT(death_message()));
    }
}

void spikes::death_message() {

    scene->addItem(death_msg);

    QTimer::singleShot(2000,this, SLOT(reset_message()));

}

void spikes::reset_message(){
    scene->removeItem(death_msg);
}
