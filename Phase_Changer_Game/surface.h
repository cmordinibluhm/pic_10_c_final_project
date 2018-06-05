#ifndef SURFACE_H
#define SURFACE_H

#include <QGraphicsRectItem>
#include <QObject>
#include "phase_changer.h"

class surface  :  public QObject, public QGraphicsRectItem {
   Q_OBJECT
public:

    phase_changer* player;

    QGraphicsRectItem* body;
    QGraphicsRectItem* left;
    QGraphicsRectItem* right;

    QGraphicsRectItem* top;
    QGraphicsRectItem* bottom;

    surface(phase_changer* player,int x, int y, int xs, int ys);

    void addtoscene();


public slots:
    void detectcollision();

};



#endif // SURFACE_H
