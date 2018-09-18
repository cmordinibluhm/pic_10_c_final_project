#include "water.h"
#include <QPen>

water::water(QGraphicsScene * scene, phase_changer* player,int x, int y, int xs, int ys)
{
    substance = new QGraphicsPixmapItem();

    substance->setPixmap(QPixmap(":/images/water.png").scaled(xs,ys));
    substance->setPos(x,y);

    scene->addItem(substance);

}
