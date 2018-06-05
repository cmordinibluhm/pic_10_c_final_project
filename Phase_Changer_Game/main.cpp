#include <QApplication>
#include <QGraphicsScene>
#include "phase_changer.h"
#include "surface.h"
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creates a scene
    QGraphicsScene * my_scene = new QGraphicsScene();

    //create an item to place in the scene
    phase_changer * player = new phase_changer();

    //add the item to the scene
    my_scene->addItem(player);

    //make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create a second item to place in the scene
    QGraphicsEllipseItem * ellipse2 = new QGraphicsEllipseItem();
    ellipse2->setRect(550,250,50,50);
    //add the item to the scene
    my_scene->addItem(ellipse2);

    //create a third item to place in the scene
    surface * floatingbox = new surface(player,250,250,50,50);
    //add the item to the scene
    my_scene->addItem(floatingbox);
    floatingbox->addtoscene();

    surface * box = new surface(player,350,450,50,50);
    my_scene->addItem(box);
    box->addtoscene();

    surface * ground = new surface(player,0,500,1200,20);
    my_scene->addItem(ground);
    ground->addtoscene();

    surface * platform = new surface(player,600, 100, 600, 20);
    my_scene->addItem(platform);
    platform->addtoscene();

    surface * surface_box = new surface(player,100, 250, 50, 50);
    my_scene->addItem(surface_box);
    surface_box->addtoscene();

    //add a view
    QGraphicsView * my_view = new QGraphicsView(my_scene);
    //my-view->setScene(scene);

    my_view->show();
    my_view->setFixedSize(1200,600);
    my_scene->setSceneRect(0,0,1200,600);

    player->setPos(100, 400);

    return a.exec();
}
