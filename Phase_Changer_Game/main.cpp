#include <QApplication>
#include <QGraphicsScene>
#include "phase_changer.h"
#include "surface.h"
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * my_scene = new QGraphicsScene();
    //my_scene->setBackgroundBrush(QBrush(QImage(":/images/blackhole.jpg")));
    my_scene->setBackgroundBrush(QBrush(QImage(":/images/stars.jpg")));

    phase_changer * player = new phase_changer();
    my_scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

//    QGraphicsPixmapItem * sun = new QGraphicsPixmapItem();
//    sun->setPixmap(QPixmap(":/images/sun.png").scaled(200,200));
//    sun->setPos(50,50);

//    my_scene->addItem(sun);

    QGraphicsPixmapItem * sundragon = new QGraphicsPixmapItem();
    sundragon->setPixmap(QPixmap(":/images/sundragon.png").scaled(200,200));
    sundragon->setPos(50,50);

    my_scene->addItem(sundragon);




    surface * start = new surface(my_scene,player,0,350,100,150);

    surface * floatingbox = new surface(my_scene, player,250,250,50,50);

    surface * box = new surface(my_scene, player,350,450,50,50);

    surface * ground = new surface(my_scene,player,0,500,1200,20);

    surface * platform = new surface(my_scene,player,600, 100, 600, 20);

    surface * surface_box = new surface(my_scene,player,100, 250, 50, 50);

    surface * bigbox = new surface(my_scene,player, 600, 350,600, 150);


    //add a view
    QGraphicsView * my_view = new QGraphicsView(my_scene);
    //my-view->setScene(scene);

    my_view->show();
    my_view->setFixedSize(1200,600);
    my_scene->setSceneRect(0,0,1200,600);

    player->setPos(25, 50);

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/hyperspace.mp3"));
    music->play();
    music->setVolume(2);

    return a.exec();
}
