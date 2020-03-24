#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include <QGraphicsScene>
#include "phase_changer.h"

class objective : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QGraphicsPixmapItem * objective_image;
    QGraphicsScene * scene;
    phase_changer * player;
    bool has_won;

public:
    objective(QGraphicsScene * _scene, phase_changer * _player);

    void end_dailogue();

signals:

public slots:
    void wait_for_player();
};

#endif // OBJECTIVE_H
