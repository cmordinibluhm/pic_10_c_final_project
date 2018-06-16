#include "surface.h"
#include <QGraphicsScene>
#include <QBrush>

surface::surface(QGraphicsScene * scene, phase_changer* player_, int x, int y, int xs, int ys) : player(player_)
{
      left = new QGraphicsRectItem(x, y + 5, 5, ys - 10);
      right = new QGraphicsRectItem(x + xs - 5, y + 5, 5, ys - 10);
      bottom = new QGraphicsRectItem(x + 5, y + ys - 5, xs - 10, 5);
      top = new QGraphicsRectItem(x + 5, y, xs - 10, 5);

      body = new QGraphicsPixmapItem();
      body->setPixmap(QPixmap(":/images/rock.jpg").scaled(xs,ys));
      body->setPos(x,y);

      scene->addItem(this);
      scene->addItem(left);
      scene->addItem(right);
      scene->addItem(bottom);
      scene->addItem(top);
      scene->addItem(body);

      QTimer * timer = new QTimer(this);
      timer->start(1);
      connect(timer,SIGNAL(timeout()),this,SLOT(detectcollision()));
      connect(timer,SIGNAL(timeout()),this,SLOT(detectcollision()));

}

void surface::detectcollision() {

    if (left->collidesWithItem(player)){

        player->xvelocity = 0;
        player->setPos(player->x() - 1,player->y());
        if (player->playersounds->state() == QMediaPlayer::PlayingState){
            player->playersounds->setPosition(0);
        } else {
            player->playersounds->play();
        }
    } else if (right->collidesWithItem(player)){
        player->xvelocity = 0;
        player->setPos(player->x() + 1,player->y());
        if (player->playersounds->state() == QMediaPlayer::PlayingState){
            player->playersounds->setPosition(0);
        } else {
            player->playersounds->play();
        }
    }
    if (top->collidesWithItem(player)){
        player->yvelocity = 0;
        if (player->playersounds->state() == QMediaPlayer::PlayingState){
            player->playersounds->setPosition(0);
        } else {
            player->playersounds->play();
        }
    } else if (bottom->collidesWithItem(player)){
        player->yvelocity = -1;

        if (player->playersounds->state() == QMediaPlayer::PlayingState){
            player->playersounds->setPosition(0);
        } else {
            player->playersounds->play();
        }
    }
}

