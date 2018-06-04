#ifndef PHASE_CHANGER_H
#define PHASE_CHANGER_H

#include <QGraphicsEllipseItem>
#include <QObject>

class phase_changer : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
private:
    int phase;
public:
    phase_changer();

    void keyPressEvent(QKeyEvent * event);

public slots:
    void move();
    void fall();
    void rise();

signals:


};



#endif // PHASE_CHANGER_H
