#include "game_text.h"

game_text::game_text(QGraphicsScene * _scene, phase_changer * _player, const QString text_to_display, int _xbegin, int _xend, int _ybegin, int _yend)
    : scene(_scene), player(_player), xbegin(_xbegin), xend(_xend)
{
    ybegin = _ybegin;
    yend = _yend;

    message = new QGraphicsTextItem(text_to_display);
    message->setPos(xbegin,10);
    message->setScale(2);
    message->setDefaultTextColor(Qt::white);

    QTimer * timer = new QTimer(this);
    timer->start(1);
    connect(timer, SIGNAL(timeout()), this, SLOT(wait_for_player()));
}

void game_text::wait_for_player() {
    if (player->x() < xbegin || player->x() > xend || player->y() < ybegin || player->y() > yend) {
        scene->removeItem(message);
    }
    else if (player->x() > xbegin && player->x() < xend && player->y() > ybegin && player->y() < yend) {
        //message->setPos(player->x()-25, player->y()-25);
        scene->addItem(message);
    }
}
