g# Phase Changer
By Casey Mordini-Bluhm

***
## YouTube Demo
how to embed a youtube video: https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet

***

## Table of Contents

- [The Game](#the-game)
    - [Objective](#objective)
    - [Instructions](#instructions)
- [Project Journal](#project-journal)
    - [Reflection](#reflection)
    - [Resources](#resources)
    
***
    
## The Game
### Objective
Manipulate your state in order to navigate the obstacles between you and the checkpoint

### Instructions

UP- become less dense

DOWN- become more dense

LEFT- move left

RIGHT- move right

***

## Project Journal

### Ideas

- Add graphics
    - Escape from laboratory?
    - space
- Add picture of controls
- Add controls/instruction screen
- Add enemies
- Add hazards of some sort
- add water

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
    
QTransform() returns the identity matrix (needed in the call to itemAt() function I'm using in collisions)
    https://forum.qt.io/topic/43990/solved-itemat-in-5-3-depreciated
    
Surfaces are working great and movement is pretty good too!
    
### Commit 10
Still learning more about git. I've been checking out master before committing changes without realizing that was a problem.
    https://stackoverflow.com/questions/5531362/why-git-keeps-showing-my-changes-when-i-switch-branches-modified-added-deleted
    
GOAL:   Improve movement. (CHECK)
            Clean up velocity, phase state, and movement logic. (CHECK)
            Make it so that the player continues to rise/fall when in contact with a vertical surface. (CHECK)
    SOLUTION: Created yacceleration member for player. When it was just yvelocity the velocity would be set to zero and then the player wouldn't be able to get off the ground again
    and the object wouldn't accelerate if it "walked" off of a ledge. Acceleration was a good addition and the fact that I didn't have it before is indicative of how I have been
    figuring this out as I go along. The right/best way to do it is clearly with actual concepts from phsyics, and it is cool that I am heading that direction organically as
    I troubleshoot and solve issues.
    Removed the move() and rise() functions to that now the y-movement is linked just to fall(), and the x-movement is linked just to traverse(), rather than the y-movement being
    linked to move() which in turn called rise() or traverse().
    Wrote a surface::addtoscene() function to add the left, right, top, and bottom faces of a surface object to a scene.
    
The movement and collisions are working great!!
    The player no longer collides with standard QGraphicsItems, but only my own custom surface items(this is a good thing). The player accelerates when an obstruction is removed
    and can slide against walls when floating upward or falling downward.
    
    BUGS:   By repeatedly switching between up and down you can embed youself into a surface. (FIXED)
            If you go at a corner of a surface you can get inside of it. (MOSTLY FIXED)
            
For the last two days git had refused to push to my remote repo. Every time I tried "git commmit -u origin master" the terminal froze. I tried several fixes recommended
    online and nothing worked, but I tried the same command again after a few days and the push was successful! I don't know if it was a wifi-strength or network thing or what.
    
Hard deadline is Monday in the week after finals.
    Post a video on YouTube.
            
### Commit 11
Got rid of the surface::addtoscene() function that I made and instead added a pointer to the scene in the constructor for surface so that all the adding can be done
    automatically in the constructor.
    
FIGURED SOMETHING OUT: I was having trouble with collision detection before because when I used itemAt(x,y,transform) I was checking a position WITHIN the player itself, so it
    always returned true! I set the position to be (x -1, y + x, transform) where x varies across a little less than the height of the player and it works great! This also does a lot
    towards fixing the bug where the player's bottom can go through surfaces!
    
Made the player into a rectangle instead of a circle to simplify collisions.
    
I got burnt out on collisions so I decided to add graphics. I changed my player object so that it inherits from QGraphicsPixmapItem instead of QGraphicsRectItem.
    I then used photoshop to remove the background of an image that I found online and resize it to the right pixel count and then added that image to the resource file
    folder that I added to the project.
    
Added the classic windows background as the background for my game. Changed background to space.
    Added a wooden plank texture to the surfaces but it looked terrible. Changed it to a rocky texture.
    
Right now all my textures are just stretched out images from google. It would be nice to make my own repeatable textures and figure out how to tile-fill my different sized
    surfaces, but I should probably focus on other things.
    
Got an mp3 of some space-rock to add to play at the start of the game    http://freemusicarchive.org/genre/Space-Rock/#
    This required learning about the QMediaPlayer class, and also required that I add the "multimedia" module to the project file, my first time editing the project file.
    
Apparently .wav sound files are raw data, uncompressed and should be used in game design for interface and game sounds, while .mp3 files are compressed, take more
    processing power, and are best used for music and ambient sounds    https://www.gamedev.net/forums/topic/170689-mp3-vs-wav-cpu-usage/
    
Got an mp3 (it wasn't in wav format) for when the player comes in contact with a surface. I think this is enough sound for now.
    
### Commit 12
Add final_project_repo.txt for upload to CCLE.

Remove unwanted resource files from .qrc

Modifying readme.md markdown formatting: experimenting with horizontal rule, taking all these entries out of code blocks (oops)

### Commit 13
Uploaded final_project_repo.txt to CCLE
Markdown formatting changes were successful, applying to the rest of this document.

    Current goals:
        Try to incorporate a ternary operator somewhere! Those things are some cool syntactic sugar.
        Add scrolling capabilities. (CHECK)
        Add an objective.

Addition: player skin changes to a gas cloud when the phase changes to gas (changed to bubble)

ADDITION: Used photoshop to make my own liquid/puddle skin that is 10 pixels tall. Now when the player presses down they turn into a puddle and can flow under low obstacles. The player turns into a bubble and floats when up
is pressed. Awesome. I'd like to make more of my own graphics.

Learned how to use QTransform to flip a QPixmap, so that when the player presses the left or right keys the water or bubble changes directions accordingly.

So I got distracted and did not accomplish any of the goals I listed, but I did firgure out some cool stuff about graphics!

I also reviewed the CCLE submission page which had some "Other things to keep in mind." Based on these I added a few sections to this readme file, like "Reflection," "Course Concepts," "What's Next?", and a place for a YouTube
video demonstration of my project.

### Commit 14
Pushed to github and reviewed markdown formatting again, made a few more changes with indenting and newlines.

Cleaned up main.cpp by organizing the main routine into sections such as "set the scene", "set up the view", "create the player". The "aesthetics" section will have all the declatations of graphics that the player does not collide with.
The "surfaces" section will have all the surfaces the player collides with. I am also changing the names of the surfaces to be more descriptive.

set my scene's stickyfocus tag to true so that you don't ever have to click on the player to resume using the arrow keys to control it.

ADDITION: After a lot of troubleshooting, I figured out how to make my QGraphicsView follow the player! What I ended up doing is changing my player constructor to take a pointer to the view. Then, I added a public slot to the
phase_changer class called update_view() that calls centerOn(player). I then connected this SLOT to a QTimer in the phase_changer constructor! Before this I had a few other ideas like adding a QScrollBar and connecting the player's
position to the scrollbar's position. Another idea was to use a moveEvent in the phase_changer class to set the view/scrollbar position. Perhaps these could have worked as well but this implementation I figured out works great!

I added a few new obstacles.

Things to work on:
- the player disappears when you go out of the page
- the game is boring, there is no objective or danger (I need hazards or enemies or jumping instead of floating)

### Commit 15

So the application output has been showing "libpng warning: iCCP: known incorrect sRGB profile".  It turns out this can be safely ignored.

After searching for quite a while for a new png for the solid state of my phase_changer, ( I decided to make it ice instead of a dark matter ball) I decided to create my own in photoshop.
I made a few different versions of my_ice.png and settled on one. My friend from high school who has been into making games for quite a while came to visit and made his own version of a puddle texture, and I decided to keep
it because it looks good and for sentimental reasons. (Puddle artwork credit to Jeremiah Zagala).

Anyways, hopefully I will be able to present the different iterations of my ice artwork here once I push to github and have their urls.
![alt text](http://url/to/img.png)


I added an "objective" class inheriting from QPixmapItem. When the player reaches it, the objective growing in size and the text "You win!"  appears on the screen beneath the player.

Now I am going to add a spikes class which will cause the player to return to the starting point if touched. I am going to use the QGraphicsPolygonItem class to do this, since I haven't used this class yet and it seems like it offers
more flexibility than the other QGraphicsItems.

SUCCESS: spikes class sends player back to the starting point successfully. The spikes only come to one point in the middle of the object, but it works. It's a little too touchy right now, in that the player gets sent back when it
seems like it is far enough away that it shouldnt be. I might have to figure out how to add a hitbox to the phase_changer class.

***

### Reflection

#### How I came up with the idea and why I settled on it:
Early in the quarter, before the final project had really been talked about, I had done a google search and found a website with links to a ton of past PIC 10C students' final projects, I saw that a lot of them had used Qt to make
games and this seemed pretty cool to me. I also found a YouTube series by a former PIC 10C student Abdullah Aghazada. I watched the first parts of his tutorial and it seemed like something cool that I had never done before.

At first I was a little discouraged and doubted my ability to come up with an original game concept. Before too long, though, it just kind of came to me while I was thinking about physics. It was pretty much my first idea and I was
    very excited that I had come up with it.
    
### Course Concepts
Generic algorithms don't really apply here since Qt has so much of its own stuff and since I am using the QTimer in all the places that I normally would have used a for loop.
    
#### What's Next?
I definitely am not done with this project. There's a lot to do, and it will continue to evolve in ways I can't predict right now, but I definitely want to do a few things including:
    - making my own resources for graphics and sound. I already downloaded GarageBand and plan to make my own background music and sound effects
    - enemies
    - multiple levels
    - random generation of obstacles
    
***
***

### Resources

The resources here represent just a fraction of the places that I visited and got some information from. Literally hundreds of webages have contributed to my still limited knowledge of Qt and game design.

YouTube Qt Game Tutorials by Abdullah Aghazada
https://www.youtube.com/watch?v=9lqhMLFHj3A&index=0&list=PLMgDVIa0Pg8WrI9WmZR09xAbfXyfkqKWy

Markdown Help
http://commonmark.org/help/tutorial/index.html

Markdown Cheatsheet (code blocks, embedding a youtube video, line breaks)
https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet

Signals and Slots Explanation
https://doc.qt.io/archives/qt-4.8/signalsandslots.html

Collision Detection Thread
https://forum.qt.io/topic/21047/collision-detection

Git Push Troubleshooting
https://stackoverflow.com/questions/16906161/git-push-hangs-when-pushing-to-github

MP3 vs WAV
https://www.gamedev.net/forums/topic/170689-mp3-vs-wav-cpu-usage/

Free PNG's
https://pngtree.com/


#### Classes

QGraphicsScene
https://doc.qt.io/qt-5/qgraphicsscene.html

QGraphicsView
https://doc.qt.io/qt-5/qgraphicsview.html

QPixmap
https://doc.qt.io/qt-5/qpixmap.html

QTransform
https://doc.qt.io/qt-5/qtransform.html

QGraphicsItem (and inherited QGraphicsRectItem QGraphicsEllipseItem)

QObject



