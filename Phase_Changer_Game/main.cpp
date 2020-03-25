#include <QApplication>
#include <QGraphicsScene>
#include "phase_changer.h"
#include "objective.h"
#include "surface.h"
#include "spikes.h"
#include "water.h"
#include "game_text.h"
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

    player->setPos(25, 0);

    //------------------------------------- objective -----------------------------------------//

    objective * my_objective = new objective(my_scene, player);
    my_objective->setPos(2000,50);

    //------------------------------------- aesthetics ----------------------------------------//

    QGraphicsPixmapItem * cloud = new QGraphicsPixmapItem();
    cloud->setPixmap(QPixmap(":/images/cloud.png").scaled(400,200));
    cloud->setPos(200,0);
    my_scene->addItem(cloud);

    QGraphicsPixmapItem * bolt = new QGraphicsPixmapItem();
    bolt->setPixmap(QPixmap(":/images/my_lightning.png"));
    bolt->setPos(450,165);
    my_scene->addItem(bolt);

    QGraphicsPixmapItem * rain = new QGraphicsPixmapItem();
    rain->setPixmap(QPixmap(":/images/light_rain.png"));
    rain->setPos(1800,0);
    my_scene->addItem(rain);

    QGraphicsPixmapItem * lava = new QGraphicsPixmapItem();
    lava->setPixmap(QPixmap(":/images/lava.png").scaled(300, 40));
    lava->setPos(1700,310);
    my_scene->addItem(lava);

    //-------------------------------------- surfaces -----------------------------------------//

    surface * test = new surface(my_scene,player,0,250,100,150);

    surface * start = new surface(my_scene,player,0,350,100,150);

    surface * ground1 = new surface(my_scene,player,0,500,600,120);
    surface * ground2 = new surface(my_scene,player,600,590,1800,30);

    surface * floatingcolumn = new surface(my_scene,player,150, 0, 50, 300);

    surface * floatingbox = new surface(my_scene, player,250,250,50,50);
    surface * groundbox1 = new surface(my_scene, player,350,400,50,100);

    surface * volcano_baseleft = new surface(my_scene,player, 570, 400,285, 100);
    surface * volcano_botleft = new surface(my_scene,player, 600, 350,285, 50);
    surface * volcano_midleft = new surface(my_scene,player, 625, 200,260, 150);
    surface * volcano_topleft = new surface(my_scene,player, 650, 100,235, 100);

    surface * volcano_baseright = new surface(my_scene,player, 1005, 400,355, 175);
    surface * volcano_botright = new surface(my_scene,player, 975, 350,325, 50);
    surface * volcano_midright = new surface(my_scene,player, 975, 200,300, 150);
    surface * volcano_topright = new surface(my_scene,player, 975, 100,275, 100);

    surface * volcano_upper = new surface(my_scene,player, 1075, 0,925, 100);

    surface * wall = new surface(my_scene, player, 1500,160,20,500);

    surface * mesa2 = new surface(my_scene,player, 1600, 350,600, 130);
    surface * wall1 = new surface(my_scene,player,2000,0,20,350);

    //--------------------------------------- hazards -----------------------------------------//

    spikes * floatingcolumnbottom = new spikes(my_scene, player, 150,300,50,2);

    spikes * obstacle1 = new spikes(my_scene,player,100,500,250,1); //bottom
    spikes * obstacle2 = new spikes(my_scene,player,600,350,50,3); //left
    spikes * obstacle3 = new spikes(my_scene,player,250,300,50,2); //top
    spikes * obstacle4 = new spikes(my_scene,player,300,250,50,4); //right

    spikes * volcano_left = new spikes(my_scene,player,880,105,290,4);
    spikes * volcano_right= new spikes(my_scene,player,980,105,290,3);
    //spikes * volcano_lava = new spikes(my_scene,player,600,600,350,1);

    spikes * mine_field1 = new spikes(my_scene,player,1400,470,40,2);
    spikes * mine_field2 = new spikes(my_scene,player,1450,370,40,2);
    spikes * mine_fieldtop1 = new spikes(my_scene,player,1360,250,40,2);
    spikes * mine_fieldtop = new spikes(my_scene,player,1400,250,40,2);

    spikes * wall_top = new spikes(my_scene,player,1500,170,20,1);

    spikes * tunnel_bottom = new spikes(my_scene,player,1600,600,700,1);
    spikes * tunnel_top = new spikes(my_scene,player,1600,470,600,2);

    //---------------------------------------- water ------------------------------------------//

    //water * volcano = new water(my_scene,player,600,480,600,130);

    //---------------------------------------- music ------------------------------------------//

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/hyperspace.mp3"));
    music->play();
    music->setVolume(2);

    //----------------------------------------- text ------------------------------------------//
    //game_text * text = new game_text(scene,player,string,xlow,xhigh,ylow,yhigh);

    QString string1 = "Use W to decrease density, and S to increase density.\nUse A and D to move left and right.";
    game_text * text1 = new game_text(my_scene,player,string1,0,200,0,600);

    QString string2 = "When in the gas state, you can only float a certain cumulative height.\nYou must land on a hard surface to reset.";
    game_text * text2 = new game_text(my_scene,player,string2,250,650,0,600);

    QString string3 = "Increase your density until you are liquid to flow under low obstacles.";
    game_text * text3 = new game_text(my_scene,player,string3,650,1300,400,600);

    QString string4 = "Can you figure out how to use\n the height limit to your advantage?";
    game_text * text4 = new game_text(my_scene,player,string4,1500,2000,100,600);

    return a.exec();
}
