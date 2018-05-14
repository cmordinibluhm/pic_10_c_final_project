#ifndef MYELLIPSE_H
#define MYELLIPSE_H

#include <QGraphicsEllipseItem>
#include <QObject>

class myEllipse : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    myEllipse();

    void keyPressEvent(QKeyEvent * event);

public slots:
    void move();
};


#endif // MYELLIPSE_H
