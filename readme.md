# Phase Changer
By Casey Mordini-Bluhm

## Table of Contents

- [The Game](#the-game)
    - Objective
    - Instructions
- [Project Journal](#project-journal)
    - [Resources](#resources)
    
## The Game
### Objective
Manipulate your state in order to navigate the obstacles between you and the checkpoint

### Instructions
W- become less dense
S- become more dense
A- move left
D- move right

## Project Journal

### April 10, 2018
    Today I looked at some old PIC 10C final projects on YouTube and had the idea to do a phase changing game.

### Commit 1
    Today I went to Professor Salazar's office hours and asked some questions about the project and about my idea.
    He recommended I keep a journal like this in my readme file. He also said not to worry about choosing a difficult
    project and that it doesn't even have to work at the end. The main thing is the process I go through and how much
    I learn.
	
    I have been practicing markdown a little, and so I'm writing this in markdown.

    I also have a Google Doc with brainstorming about the final project.
	
    I just learned to start nano with -m for mouse support. Sweet!

### Commit 2 and 3
    I talked to Stephanie last week and she gave me the idea of focusing on the physics. Her idea is basically to just do solid/liquid/gas solvers.
    Today I started digging into Qt following a YouTube tutorial from a former PIC 10C student.
    
    The "Playground" Qt project is the physics solid collision solver.
    The "Phase Changer" Qt project is the platformer game.

### Commit 4
    Updated .gitignore to ignore build- and .pro.user.

### Commit 5
    Cleared index with "git rm -r --cached ." and re-added everything.
    
### Commit 6
    Added table of contents to readme.md.
    Added "Resources" section to readme.md.
    Added "The Game" section to readme.me.
    Goal for the day: get gravity and contact force with ground
    This is tough! I've spent several hours researching and trying stuff.
    After an entire afternoon/evening of scouring forums and documentation, I finally figured out how to enforce collisions!
    
### Commit 7
    Need to decide whether the object should begin falling in the constructor, or if there should be another way that makes it easier to turn falling off

    GOAL: Need to decide whether the object should begin falling in the constructor, or if there should be another way that makes it easier to turn falling off
    when the player changes state of matter.
    SOLUTION: The constructor sets up a QTimer and connects its timeout signal the player's slot move(). The player object now has a member variable that tracks
    what state of matter it is in. If this is solid(1) or liquid(0), then the move() function calls the fall() function, and if it's gas(2), then the move() function calls the
    rise() function.
    
    Maybe I should make a custom collision function that let's me know if it is ontop of, next to, or below whatever it is colliding with.
    Alternatively I could have different objects for ceilings, floors, and walls (right and left walls) and the player could interact with each differently
    
    Also would like to allow for multiple key presses at once, so going diagonally. https://stackoverflow.com/questions/3081091/qt-multiple-key-combo-event
    
### Commit 8
    GOAL: Now going to work on being able to seamlessly move left or right when rising or falling, without having to release keys.
    SOLUTION: Changed move right and move left mechanics so that instead of moving with the arrow keys the arrow keys instead change the xvelocity member to -1 or +1.
    Also added a keyReleaseEvent function to player class that detects when the right or left arrow key is released and sets the xvelocity to 0.
    In the constructor for the player, the QTimer now not only connects to the move() function (which in turn calls rise() or fall()) but also to the traverse() function
    which in turn moves left or right based on the xvelocity member.
    This method of storing the velocity with direction of the player seems to be the way that everyone online recommends/assumes it to be done.
    
    Went to Professor Salazar's office hours to ask a few questions and check in. He told me that the project doesn't have to be fancy or perfectly functional since the
    main point of the project is the learning experience.
    
    Regarding collisions, he recommended having some sort of buffer so that when the player jumps ahead by however much, it doesn't accidentally pass the edge of the
    object and not register a collision.
    
    Changes "QTimer timer" to be a member of player class so that its interval can be changed as the type of movement changes.
    
### Commit 9
    Merged with master before attempting to make sideways collisions. Each question I look up leads to another and I now have exactly 40 tabs open in Chrome.
    Current approach is to use the itemAt(Position) method to see if there is an item at certain positions within the player...
    
    Okay, so after a fruitless effort to change the ymovement to be based on velocity member I decided to make an executive decision on how I'm going to go about collisions.
    I am passing a pointer to the player to every surface object that is made. Player's x and y velocities are now public. The surface class is composed of four sides identified
    as right, left, bottom, and top. The surface class has a public slot "collisiondetection" that is connected to a QTimer with an interval of 1 ms. Whenever a left or right
    surface member collides with the player, the players xvelocity is set to zero. So far this is working quite nicely.
    
    I made the sizing for the surface objects depend on the parameters passed which are the same as they would be for a QGraphicsRectItem.
    
    One issue that I'd like to work on is that currently I have to add left, right, bottom, and top members individually in main.cpp for each surface object. I try to do it in the
    constructor with "scene()->addItem(left)" but I get "use of undeclared identifier scene". I am trying to do it like Abdullah does in his tutorial for the bullet item. I don't
    know what I'm missing...
    SOLUTION: My surface class wasn't inheriting from QGraphicsRectItem (because I thought that would enforce requirements I didn't want). It turns out I was wrong and once I inherited
    from QGraphicsRectItem it worked! Well almost. I had to write a separate method "addtoscene" to add the sides of the surface to the scene after the surface itself is added to the
    scene, since when trying to add them in the constructor the object isn't part of a scene yet so scene() must just return 0.
    
    QTransform() returns the identity matrix
    
    Surfaces are working great and movement is pretty good too!
    
    
    
### Resources

YouTube Qt Game Tutorials by Abdullah Aghazada
https://www.youtube.com/watch?v=9lqhMLFHj3A&index=0&list=PLMgDVIa0Pg8WrI9WmZR09xAbfXyfkqKWy

Markdown Help
http://commonmark.org/help/tutorial/index.html

Signals and Slots Explanation
https://doc.qt.io/archives/qt-4.8/signalsandslots.html
