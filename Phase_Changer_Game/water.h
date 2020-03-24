#ifndef WATER_H
#define WATER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "phase_changer.h"

class water : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

private:
    friend class phase_changer;

public:

    phase_changer* player;
    QGraphicsPixmapItem* substance;

    /**
     * @brief water ctor creates an area filled with water with accompanying change in mechanics
     * @param scene
     * @param player
     * @param x x-position of the top left corner
     * @param y y-position of the top left corner
     * @param xs width
     * @param ys height
     */
    water(QGraphicsScene * scene, phase_changer* player,int x, int y, int xs, int ys);


};

#endif // WATER_H
