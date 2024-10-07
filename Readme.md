# Pong Game - C++ SFML

This is a simple Pong game developed using C++ and SFML. The game was created as a small project to explore object-oriented programming (OOP) concepts in game development.

## Overview
All game objects are derived from two base classes:

DrawableObject: For objects that can be drawn on the screen.
UpdateableObject: For objects that can be updated (move or interact) in the game.
Some objects only need to be drawn (like the game boundary), while others require both drawing and updating (like the ball and paddles).

## Object-Oriented Approach
Instead of using an Entity Component System (ECS), a more traditional OOP approach was used. While ECS offers flexibility and scalability, the scope of this project was small enough to explore the benefits of the classic OOP design pattern.

## Future Enhancements
Although the project was fun and engaging, there are many ways to make the game more interesting and challenging. Here are a few ideas for future updates:

Power-ups: Introducing special items that temporarily change the game dynamics.
Game Modes: Adding different modes like time attack or multiplayer options.
Visual Effects: Incorporating animations, particle effects, or screen transitions to enhance the visual experience.
Due to time constraints, these features will be implemented at a later time.

Requirements
SFML library