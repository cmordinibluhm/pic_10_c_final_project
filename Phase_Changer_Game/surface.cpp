#include "surface.h"
#include <QGraphicsScene>


surface::surface(phase_changer* player_, int x, int y, int xs, int ys) : player(player_)
{
      left = new QGraphicsRectItem(x, y + 5, 5, ys - 10);
      right = new QGraphicsRectItem(x + xs - 5, y + 5, 5, ys - 10);
      bottom = new QGraphicsRectItem(x + 5, y + ys - 5, xs - 10, 5);
      top = new QGraphicsRectItem(x + 5, y, xs - 10, 5);
      scene()->addItem(this);

      QTimer * timer = new QTimer(this);
      timer->start(1);
      connect(timer,SIGNAL(timeout()),this,SLOT(detectcollision()));
}

void surface::addtoscene() {
    scene()->addItem(left);
    scene()->addItem(right);
    scene()->addItem(bottom);
    scene()->addItem(top);
}

void surface::detectcollision() {
    if (left->collidesWithItem(player)){
        player->xvelocity = 0;
    } else if (right->collidesWithItem(player)){
        player->xvelocity = 0;
    }
    if (top->collidesWithItem(player)){
        player->yvelocity = 0;
    } else if (bottom->collidesWithItem(player)){
        player->yvelocity = 0;
    }
}
