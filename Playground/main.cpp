#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creates a scene
    QGraphicsScene * my_scene = new QGraphicsScene();

    //create an item to place in the scene
    QGraphicsRectItem * my_rect = new QGraphicsRectItem();
    my_rect->setRect(0,0,100,100);

    //add the item to the scene
    my_scene->addItem(my_rect);

    //add a view
    QGraphicsView * my_view = new QGraphicsView(my_scene);
    //my-view->setScene(scene);

    my_view->show();

    return a.exec();
}
