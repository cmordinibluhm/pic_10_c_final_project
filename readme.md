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
    After an entire afternoon of scouring forums and documentation, I finally figured out how to enforce collisions! 


### Resources

YouTube Qt Game Tutorials by Abdullah Aghazada
https://www.youtube.com/watch?v=9lqhMLFHj3A&index=0&list=PLMgDVIa0Pg8WrI9WmZR09xAbfXyfkqKWy

Markdown Help
http://commonmark.org/help/tutorial/index.html

Signals and Slots Explanation
https://doc.qt.io/archives/qt-4.8/signalsandslots.html
