#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include <QObject>
#include <QGraphicsScene>
#include "phase_changer.h"


class game_text : public QObject
{
    Q_OBJECT

private:
    QGraphicsTextItem * message;
    QGraphicsScene * scene;
    phase_changer * player;
    const int xbegin;
    const int xend;
    int ybegin;
    int yend;

public:
    game_text(QGraphicsScene * _scene, phase_changer * _player, const QString text_to_display, int _xbegin, int _xend, int _ybegin, int _yend);


signals:

public slots:

    void wait_for_player();

};

#endif // GAME_TEXT_H
