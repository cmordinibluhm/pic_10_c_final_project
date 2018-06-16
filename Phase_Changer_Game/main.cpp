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
#include <QScrollArea>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //----------------------------------- set the scene ---------------------------------------//

    QGraphicsScene * my_scene = new QGraphicsScene();
    //my_scene->setBackgroundBrush(QBrush(QImage(":/images/blackhole.jpg")));
    my_scene->setBackgroundBrush(QBrush(QImage(":/images/stars.jpg")));

    //----------------------------------- set up the view -------------------------------------//

    //add a view
    QGraphicsView * my_view = new QGraphicsView(my_scene);
    //my-view->setScene(scene);

    my_view->setFixedSize(1200,620);
    my_scene->setSceneRect(0,0,2400,600);

    my_view->show();

    //---------------------------------- create the player ------------------------------------//

    phase_changer * player = new phase_changer(my_view);
    my_scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    my_scene->setStickyFocus(true);
    player->setFocus();

    player->setPos(25, 50);

    //------------------------------------- aesthetics ----------------------------------------//

    QGraphicsPixmapItem * sundragon = new QGraphicsPixmapItem();
    sundragon->setPixmap(QPixmap(":/images/sundragon.png").scaled(200,200));
    sundragon->setPos(2000,50);
    my_scene->addItem(sundragon);

    QGraphicsPixmapItem * cloud = new QGraphicsPixmapItem();
    cloud->setPixmap(QPixmap(":/images/cloud.png").scaled(400,200));
    cloud->setPos(50,25);
    my_scene->addItem(cloud);

    //-------------------------------------- surfaces -----------------------------------------//

    surface * start = new surface(my_scene,player,0,350,100,150);

    surface * ground1 = new surface(my_scene,player,0,500,2400,20);

    surface * floatingbox1 = new surface(my_scene,player,150, 250, 50, 50);

    surface * floatingbox2 = new surface(my_scene, player,250,250,50,50);

    surface * groundbox1 = new surface(my_scene, player,350,450,50,50);

    surface * highplatform = new surface(my_scene,player,600, 100, 600, 20);

    surface * mesa1 = new surface(my_scene,player, 600, 350,600, 150);

    surface * mesa2 = new surface(my_scene,player, 1600, 350,600, 150);

    surface * pillar1 = new surface(my_scene,player,700,120,50,205);

    surface * wall1 = new surface(my_scene,player,2000,0,20,620);

    //------------------------------------ set the music --------------------------------------//

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/hyperspace.mp3"));
    music->play();
    music->setVolume(2);


    return a.exec();
}
