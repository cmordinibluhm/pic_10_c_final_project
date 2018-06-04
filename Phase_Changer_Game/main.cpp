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

    QGraphicsRectItem * box = new QGraphicsRectItem();
    box->setRect(350,450,50,50);
    my_scene->addItem(box);

    QGraphicsRectItem * ground = new QGraphicsRectItem();
    ground->setRect(0,500,1200,20);
    my_scene->addItem(ground);

    surface * platform = new surface();
    platform->setRect(600, 100, 600, 20);
    my_scene->addItem(platform);

    //add a view
    QGraphicsView * my_view = new QGraphicsView(my_scene);
    //my-view->setScene(scene);

    my_view->show();
    my_view->setFixedSize(1200,600);
    my_scene->setSceneRect(0,0,1200,600);

    player->setPos(100, 400);

    return a.exec();
}
