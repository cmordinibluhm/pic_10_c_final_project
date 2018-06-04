#ifndef PHASE_CHANGER_H
#define PHASE_CHANGER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>

class phase_changer : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
private:
    int phase;
    int xvelocity;
    int yvelocity;

    QTimer * timer;

public:
    phase_changer();



    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

public slots:
    void move();
    void traverse();
    void fall();
    void rise();

signals:


};



#endif // PHASE_CHANGER_H
