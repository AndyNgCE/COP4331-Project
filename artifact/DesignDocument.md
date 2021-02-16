# Program Organization

# URL Mock-Up and Diagram
![Game Start UI](/Users/andyn/OneDrive/Desktop/KingOfBombsUIStart.png)

![In-Game Player view](InGameView.png)



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
n/a
# Business Rules
n/a

# User Interface Design
UI TBD

# Resource Management
Unreal Engine has a built in garbage collector.

# Security
n/a
# Interoperability
Compiled into binaries for game. Harder to mess with.

# Internationalization/Localization
n/a

# Input/Output
Input handled by UE4

# Error Processing
n/a

# Fault Tolerance
n/a

# Architectural Feasibility

# Overengineering

# Build-vs-Buy Decisions
n/a

# Reuse
n/a

# Change Stategy
Prototype first with Blueprint Implement with C++ if it passes testing.
