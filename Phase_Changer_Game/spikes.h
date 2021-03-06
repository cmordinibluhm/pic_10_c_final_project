#ifndef SPIKES_H
#define SPIKES_H

#include <QObject>
#include <QGraphicsPolygonItem>
#include "phase_changer.h"

class spikes : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT

    phase_changer * player;
    QGraphicsScene * scene;
    QGraphicsTextItem * death_msg;
    int orientation;

public:

    spikes(QGraphicsScene * _scene, phase_changer * _player, int x, int y, int xs,int orient);

public slots:

    void check_for_death();
    void death_message();
    void reset_message();


};

#endif // SPIKES_H
