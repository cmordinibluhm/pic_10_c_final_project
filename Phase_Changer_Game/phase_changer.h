#ifndef PHASE_CHANGER_H
#define PHASE_CHANGER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class phase_changer : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

    friend class surface;
private:
    int phase; //the current state of matter- 0 for liquid, 1 for solid, 2 for gas

    QTimer * xtimer; //timer for the player's horizontal movement
    QTimer * ytimer; //timer for the player's vertical movement



public:

    QMediaPlayer * playersounds;

    int xvelocity; //the horizontal velocity
    int yvelocity; //the vertical velocity
    int yacceleration; //vertical acceleration of the player

    phase_changer(); //constructor

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);


public slots:

    void traverse(); //horizontal movement
    void fall(); //solid/liquid vertical movement

};



#endif // PHASE_CHANGER_H
