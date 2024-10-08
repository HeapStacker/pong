# Pong Game - C++ SFML

This is a simple Pong game developed using C++ and SFML.

## Overview
All game objects are derived from two base classes:

DrawableObject: For objects that can be drawn on the screen.
UpdateableObject: For objects that can be updated (move or interact) in the game.
Some objects only need to be drawn (like the game boundary), while others require both drawing and updating (like the ball and paddles).

## Object-Oriented Approach
Instead of using an Entity Component System (ECS), a more traditional OOP approach was used. While ECS offers flexibility and scalability, the scope of this project was small enough to explore the benefits of the classic OOP design pattern.

## Future Enhancements
Although the project is technically complete, I’m aware that certain aspects are not perfectly implemented due to time constraints:

* the text isn’t properly centered.
* the ball sometimes bounces off the side and back of the paddle, which is unintended
* Occasionally, the ball gets stuck along the wall
* there’s no game menu yet
* music and sound effects haven’t been added
* some power-ups, like the speed-up buff, could be improved. For example, the speed buff can remain active after hitting both the wall and paddle
* the code could use better refactoring, as there are a few code smells that I intend to address

I plan to revisit these points and refine the project further on demand
