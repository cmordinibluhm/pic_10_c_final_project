#include <QApplication>
#include <QGraphicsScene>
#include "myEllipse.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creates a scene
    QGraphicsScene * my_scene = new QGraphicsScene(100,100,600,400);

    //create an item to place in the scene
    myEllipse * ellipse1 = new myEllipse();

    //add the item to the scene
    my_scene->addItem(ellipse1);

    //make ellipse1 focusable
    ellipse1->setFlag(QGraphicsItem::ItemIsFocusable);
    ellipse1->setFocus();

    //create a second item to place in the scene
    QGraphicsEllipseItem * ellipse2 = new QGraphicsEllipseItem();
    ellipse2->setRect(550,250,50,50);

    //add the item to the scene
    my_scene->addItem(ellipse2);


    //add a view
    QGraphicsView * my_view = new QGraphicsView(my_scene);
    //my-view->setScene(scene);

    my_view->show();

    return a.exec();
}
