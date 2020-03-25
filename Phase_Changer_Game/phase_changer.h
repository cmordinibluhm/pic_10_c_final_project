#ifndef PHASE_CHANGER_H
#define PHASE_CHANGER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QGraphicsView>

class phase_changer : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

    friend class surface;
private:

    QGraphicsView * my_view;

    int phase; //the current state of matter- 0 for liquid, 1 for solid, 2 for gas

    QTimer * xtimer; //timer for the player's horizontal movement
    QTimer * ytimer; //timer for the player's vertical movement

public:

    QMediaPlayer * playersounds;

    int xvelocity; //the horizontal velocity
    int yvelocity; //the vertical velocity
    int xacceleration; //the horizontal acceleration of the player
    int yacceleration; //vertical acceleration of the player

    int distance_risen;

    phase_changer(QGraphicsView * _view); //constructor

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

public slots:

    void traverse(); //horizontal movement
    void vertical_movement(); //solid/liquid vertical movement
    void update_view();

};

#endif // PHASE_CHANGER_H
