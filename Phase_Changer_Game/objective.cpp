#include "objective.h"
#include <QFont>

objective::objective(QGraphicsScene * _scene, phase_changer * _player) : scene(_scene), player(_player), has_won(false)
{
    objective_image = new QGraphicsPixmapItem();
    objective_image->setPixmap(QPixmap(":/images/sundragon.png").scaled(200,200));
    scene->addItem(objective_image);

    QTimer * timer = new QTimer(this);
    timer->start(1);
    connect(timer, SIGNAL(timeout()), this, SLOT(wait_for_player()));
}

void objective::end_dailogue()
{
    if (!has_won && objective_image->collidesWithItem(player)) {
        QGraphicsTextItem * end_msg = new QGraphicsTextItem("You made it!");
        scene->addItem(end_msg);
        end_msg->setPos(player->x() - 400,player->y()-30);
        end_msg->setScale(5);
        end_msg->setDefaultTextColor(Qt::white);
        has_won = true;
    }
}

void objective::wait_for_player()
{
    if (!objective_image->collidesWithItem(player)) {
       objective_image->setPos(x()+25,y()+25);
       objective_image->setPixmap(QPixmap(":/images/sundragon.png").scaled(200,200));
    }
    else if (objective_image->collidesWithItem(player)) {
        objective_image->setPos(x()-25,y()-25);
        objective_image->setPixmap(QPixmap(":/images/sundragon.png").scaled(300,300));
        this->end_dailogue();
    }
}
