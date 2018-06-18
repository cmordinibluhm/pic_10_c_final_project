#ifndef SURFACE_H
#define SURFACE_H

#include <QGraphicsRectItem>
#include <QObject>
#include "phase_changer.h"

class surface  :  public QObject, public QGraphicsRectItem {
   Q_OBJECT

    bool osc;

    friend class phase_changer;

public:

    phase_changer* player;

    QGraphicsPixmapItem* body;

    QGraphicsRectItem* left;
    QGraphicsRectItem* right;
    QGraphicsRectItem* top;
    QGraphicsRectItem* bottom;

    surface(QGraphicsScene * scene, phase_changer* player,int x, int y, int xs, int ys);

public slots:
    void detectcollision();

};



#endif // SURFACE_H
