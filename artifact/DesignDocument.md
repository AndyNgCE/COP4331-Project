# Program Organization

# System Context Diagram
![System Context Diagram](https://user-images.githubusercontent.com/71106921/108025748-0c5ca180-6ff5-11eb-869c-7ea994bc655c.jpeg)
Since our goal is to support 2-4 players in the game while on one screen, there is not much complexity on this level. All inputs will be read and processed through one machine. It is just a link between the user(s) and the computer.

# Container Diagram
![Container Diagram](https://user-images.githubusercontent.com/71106921/108025767-1aaabd80-6ff5-11eb-9e6b-5195bc6315cd.jpeg)
As our game runs using the Unreal Engine, most of the heavy lifting is done there. The loop our applications will run in is descibed here as well.

# Component Diagram
![Component Diagram](https://user-images.githubusercontent.com/71106921/108025776-21d1cb80-6ff5-11eb-993f-6771bb6ccdce.jpeg)
Our menu UI is the first thing any player will see, with this in mind we designed it to be easy to understand and familiar.

# Class Diagram
![Class Diagram](https://user-images.githubusercontent.com/71106921/108025845-3ca44000-6ff5-11eb-9007-f1229ed91565.jpeg)
The classes central to our games implementaion and their hierarchy are outlined here.
User story relations: PowerUp[4] - Bomb[2] - Player[1] - Hazard[5] - Block[3]

# Activity Diagram
![Activity Diagram](https://user-images.githubusercontent.com/71106921/108025801-2ac29d00-6ff5-11eb-864d-8ed044fbba00.jpeg)
The basic paths the user can take through our system, several loops stemming from the menu UI include: the tutorial, game settings, and the game itself.

# Sequence Diagram
![Sequence Diagram-page-001](https://user-images.githubusercontent.com/71106921/108026279-0a471280-6ff6-11eb-81d7-85ad1b605b7d.jpg)

# ER Diagram

# URL Mock-Up and Diagram
![KingOfBombsUIStart](https://user-images.githubusercontent.com/71106921/108016462-91898b80-6fe0-11eb-98a6-389839f739b3.png)

![InGameView](https://user-images.githubusercontent.com/71106921/108016477-9d754d80-6fe0-11eb-9387-b51e4690b086.png)


# Code Design
Classes:

Bomb.cpp
  The abstract class for the bomb.
Player.cpp
  Class for the player.
Ghost.cpp
  Class for the dead player.
PlayerController.cpp
  Controller responsible for spawning player and ghost.
 KingOfBombsCharacter.cpp
  abstract class for player movement and camera.
Hazard.cpp
  The abstract class for any map hazards.
PowerUp.cpp
  The abstract class for powerups.
Block.cpp
  The abstract class for the blocks the map will be made out of.

# Data Design


# Business Rules


# User Interface Design
UI TBD 

# Resource Management
Unreal Engine has a built in garbage collector.

# Security


# Interoperability
Compiled into binaries for game. Harder to mess with.

# Internationalization/Localization


# Input/Output
Input handled by UE4

# Error Processing


# Fault Tolerance


# Architectural Feasibility


# Overengineering


# Build-vs-Buy Decisions


# Reuse


# Change Stategy
Prototype first with Blueprint Implement with C++ if it passes testing.
