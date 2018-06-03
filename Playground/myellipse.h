#ifndef MYELLIPSE_H
#define MYELLIPSE_H

#include <QGraphicsEllipseItem>
#include <QObject>

class phase_changer : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    phase_changer();

    void keyPressEvent(QKeyEvent * event);

public slots:
    void move();
};


#endif // MYELLIPSE_H
