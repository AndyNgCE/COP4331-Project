# Program Organization

## System Context Diagram
![System Context Diagram](https://user-images.githubusercontent.com/71106921/108025748-0c5ca180-6ff5-11eb-869c-7ea994bc655c.jpeg)
Since our goal is to support 2-4 players in the game while on one screen, there is not much complexity on this level. All inputs will be read and processed through one machine. It is just a link between the user(s), King of Bombe excutable, its related system, and external use of the Unreal Engine.

Context | User Story ID 
--------|--------------
King of Bombs User | 001 - 013
King of Bomb.exe | 001, 006, 010, 002, 11
King of Bombs System | 001 - 013
Unreal Engine | 01, 03, 04, 013

## Container Diagram
![Container Diagram](https://user-images.githubusercontent.com/71106921/108025767-1aaabd80-6ff5-11eb-9e6b-5195bc6315cd.jpeg)
With a more in-depth look into the King of Bombs system, the user accesses the King of Bombs system through the King of Bomb.exe and starts with the Main Menu Application where the intial user inputs are collected and pushed into the Game Data Application. Now, this section is primarliy in charge of changing settings and stats to meet the user demand/input. It is also considered the process where assest and libaries are imported from Unreal Engine to run the game. This is then reflected in the game Application which is essentially the outputting of the game to the screen with the maps, player models, and associated elements.

Container | User Story ID 
--------|--------------
King Of Bombs User | 01 - 13, 
King Of Bomb.exe | 01, 06, 10, 02, 11
Game Application | 01, 02 , 09 , 
Main Menu Application |10 , 11 , 13 
Game Data Application | 08, 09
Unreal Engine | 01, 03, 04, 13

## Component Diagram
![Component Diagram](https://user-images.githubusercontent.com/71106921/108025776-21d1cb80-6ff5-11eb-993f-6771bb6ccdce.jpeg)
Our menu UI is the first thing any player will see, with this in mind we designed it to be easy to understand and navigate. This diagram illustrates the different components each button of the inital UI will call and interface with in order to help the user navigate from and to the game.

Component | User Story ID 
--------|--------------
Main Menu Application | 10 , 11 , 13  
Setting Compoment |12 , , 
Tutorial Compoment |06 , 10
Play Component |08 ,09 , , 
Quit Component | , 
Main Game Component | , 
Unreal Engine | 01, 03, 04, 013 
Screen Application | , 

# Code Design

## Class Diagram
![Class Diagram (1)](https://user-images.githubusercontent.com/71106921/108143609-14b8e900-7096-11eb-931c-dbbe02d15bfe.jpeg)
The user(s) will need to have access to the player's data such health, possibly lives, bomb availability, and the Power-ups that their character has collected. While this is stored in the player class, it must make calls to the Bomb and Power-up classes in order to calculate hits an effects. The same logic applies to the Hazard class when the player collides with an element designated a "Hazard". The block class is seperated as it does not have a direct affect on the player class, however, it block movement of the player and players MUST NOT be able to pass through them.

Classes | User Story ID 
--------|--------------
PowerUp | 004, 007
Bomb | 007, 005, 002
Player | 001, 009, 008, 002
Hazard | 003, 005
Block | 003, 005


## Activity Diagram
![Activity Diagram](https://user-images.githubusercontent.com/71106921/108025801-2ac29d00-6ff5-11eb-864d-8ed044fbba00.jpeg)
<br />
The basic paths the user can take through our system, several loops stemming from the menu UI include: the tutorial, game settings, and the game itself.

Activity  | User Story ID 
--------|--------------
Menu Select | , 
Tutorial | , , 
Start Game | , , , 
Chance Settings | , 
Leadership Board | , 
Play Again | , 

## Sequence Diagram
![Sequence Diagram-page-001](https://user-images.githubusercontent.com/71106921/108026279-0a471280-6ff6-11eb-81d7-85ad1b605b7d.jpg)
This is an extremely simplified representation of how a user can quickly access the game with one or more users. This is following the assumption that a user does not use acess tutorial and uses base settings.

# User Interface Design
![KingOfBombsUIStart](https://user-images.githubusercontent.com/71106921/108016462-91898b80-6fe0-11eb-98a6-389839f739b3.png)
This Depicts the UI for the beginning of the game as of now. It gives the player straightforward options for now to initiate play, manipulate the game settings, close the application, and to find information on the game.

![KingOfBombsUISettings](https://user-images.githubusercontent.com/71106921/108136062-48d8dd80-7087-11eb-924d-9d47908ba346.png)
Dependent on the option the user chooses, this is the UI for the settings menu which can be accessed directly from the menu or from selecting the play component and selecting settings there.

![TutorialUI](https://user-images.githubusercontent.com/71106921/108135766-b7696b80-7086-11eb-80ac-ca4078cff707.png)
The tutorial UI will show print information onto the screen as well as models of elements in the game to help new players learn hoow to play. Its being considered if a special button should be implemented to load a special map that can help in teaching players.

![PlayUI](https://user-images.githubusercontent.com/71106921/108135747-ab7da980-7086-11eb-8d93-d8b656cc82af.png)
This is the UI vefore starting the game. Although not depicted yet, its considered if "playmodes" should be added here so player can choose game mode an add vareity to their games. 

![InGameView](https://user-images.githubusercontent.com/71106921/108016477-9d754d80-6fe0-11eb-9387-b51e4690b086.png)
This is the first-person view all players will see while on the map. The gray object on the left and right will be the blocks players can destroy. The players cannot break the "wall" blocks to exit the map. The view will also be similar to for "Ghost" players as well.

![UI diagram](https://user-images.githubusercontent.com/71106921/108139771-c8b67600-708e-11eb-8c16-bb7f0bd70f31.jpeg)
This is a compresive diagram of how the UI will interact and reach one another.

Classes | User Story ID 
--------|--------------
PowerUp | 004, 007
Bomb | 007, 005, 002
Player | 001, 009, 008, 002
Hazard | 003, 005
Block | 003, 005

# Business Rules

# Resource Management
Unreal Engine has a built in garbage collector.

# Security
Users should not be able to modify any code in the executable. Leaderboad scores will also be inaccessable beyond veiwing.

# Performance
We expect our game to run smoothly as we are using a trusted developement environment (Unreal Engine) and our games use of resources is fairly small.

# Interoperability
Compiled into binaries for game. Harder to mess with.

# Internationalization/Localization
There is no plans for localization beyond English.

# Input/Output
Input handled by UE4

# Error Processing
Our error handling will be detective and passive. An single error message will be displayed giving any information relating to the error. The game system will then free all data structures relating to the game settings, current leaderboard, and player stats. Unreal Engine may have some exeption-proccessing of its own that we will let run, we will still include ours.

# Fault Tolerance


# Architectural Feasibility
Given our games scale there should be no problems here, if however the amount of objects spawned by players can impact performance we will cap the maximum amount allowed.

# Overengineering
Any objects detected outside of the intended game world will be deleted to allow the game to continue.

# Build-vs-Buy Decisions
Unreal Engine is very robust and very free making it a high value resource, we chose to code most of our own classes for our game rather than purchase assets from a marketplace.

# Reuse


# Change Stategy
Our player class can interact with multiple other interfaces, these interfaces should allow us the flexibility we need to create new features.
