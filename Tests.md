## Character Movement - Manual Test - character.cpp
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Press up key on keyboard | Move forward
2 | Press left key on keyboard | Turn left
3 | Press right key on keyboard | Turn right
4 | Press back key on keyboard | Move back
5 | Hold shift + press left on keyboard | Moves left(camera locked)
6 | Hold shift and press right on keyboard | Moves right(camera locked)

## Character Movement Interaction (Bombs) - Manual Test - Bombs.cpp
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Press up key on keyboard | Move forward until reaching collision range of bomb
2 | Player reaches bomb after moving forward | Player movement stops
3 | Press back key on keyboard | Move backwards until reaching collision range of bomb
4 | Player reaches bomb after moving backwards | Player movement stops
5 | Hold shift + press left on keyboard | Moves left(camera locked) until reaching collision range of bomb
6 | Player reaches bomb after moving backwards | Player movement stops
7 | Hold shift and press right on keyboard | Moves right(camera locked) until reaching collision range of bomb
8 | Player reaches bomb after moving backwards | Player movement stops

## Character Movement Interaction (Blocks)- Manual Test
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Press up key on keyboard | Move forward until reaching collision range of block
2 | Player reaches block after moving forward | Player movement stops
3 | Press back key on keyboard | Move backwards until reaching collision range of block
4 | Player reaches block after moving backwards | Player movement stops
5 | Hold shift + press left on keyboard | Moves left(camera locked) until reaching collision range of block
6 | Player reaches block after moving backwards | Player movement stops
7 | Hold shift and press right on keyboard | Moves right(camera locked) until reaching collision range of block
8 | Player reaches block after moving backwards | Player movement stops
9 | Move Player in direction of block | Player will stop before passing through any blocktype

## Character Movement Interaction (Power-Up)- Manual Test
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Press up key on keyboard | Move forward until reaching collision range of Power-Up(s).
2 | Player reaches  Power-Up(s) after moving forward | Player movement continues and Power-Up(s) de-spawn.
3 | Press back key on keyboard | Move backwards until reaching collision range of  Power-Up(s).
4 | Player reaches  Power-Up(s) after moving backwards | Player movement continues and Power-Up(s) despawn.
5 | Hold shift + press left on keyboard | Moves left (camera locked) until reaching collision range of Power-Up(s).
6 | Player reaches block after moving backwards | Player movement continues and Power-Up(s) despawn.
7 | Hold shift and press right on keyboard | Moves right(camera locked) until reaching collision range of Power-Up(s).
8 | Player reaches  Power-Up(s) after moving backwards | Player movement continues and Power-Up(s) despawn.
9 | Move Player in any direction of Power-Up(s)| Player will continue moving and Power-Up(s) will ALWAYS despawn.

## Power-Up Pickup(All) - Manual Test
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Press forward or "W" on keyboard to walk forward | Power-Up despawns and affilated effect applies.
2 | Press down or "S" on keyboard to walk backwards | Power-Up despawns and affilated effect applies.
3 | Press right or "D" on keyboard to move right | Power-Up despawns and affilated effect applies.
4 | Press left or "A" on keyboard to move left | Power-Up despawns and affilated effect applies.

## Power-Up Pickup Timer - Manual Test
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Press forward or "W" on keyboard to walk forward towards Power-Up Movement | Power-Up Movement becomes hidden in-game and affilated effect applies and deactivates after 20 in-game frames.
2 | Press down or "S" on keyboard to walk backwards Power-Up Movement | Power-Up Movement becomes hidden in-game and affilated effect applies and deactivates after 20 in-game frames.
3 | Press right or "D" on keyboard to move right Power-Up Movement | Power-Up Movement becomes hidden in-game and affilated effect applies and deactivates after 20 in-game frames.
4 | Press left or "A" on keyboard to move left Power-Up Movement | Power-Up Movement becomes hidden in-game and affilated effect applies and deactivates after 20 in-game frames.

## Power-Up Pickup - Automated Test
Expectant behavior:
On Power-Up grab, a line should be printed on the screen automatically indicating action.

## Hazard(All) - Manual Test
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Move player onto hazard | Player effect is applied.
2 | Wait several seconds | No additional effect is applied.
3 | Move player off hazard | Hazard effect removed.

## Hazard(All) - Automated Test
Expectant behavior:
On hazards contact with player character, a debug message will display.
Once player ceases contact, a different debug message displays.

## TeleportHazard - Manual Test
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Move player onto hazard | Player is teleported.
2 | Wait several seconds | No additional effect is applied.
3 | Move player onto hazard again | Player is teleported to same spot as before.

## BreakableBlock  - Manual Test
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | spawn a bomb neat to Breakable block | Breakable block will be destroy
2 | Player can not pass to block | Player movement stops
3 | Press up key on keyboard | Move forward until reaching collision range of block
4 | Player reaches block after moving forward | Player movement stops
5 | Press back key on keyboard | Move backwards until reaching collision range of block
6 | Player reaches block after moving backwards | Player movement stops
7 | Hold shift + press left on keyboard | Moves left(camera locked) until reaching collision range of block
8 | Player reaches block after moving backwards | Player movement stops
9 | Hold shift and press right on keyboard | Moves right(camera locked) until reaching collision range of block
10 | Player reaches block after moving backwards | Player movement stops
11 | Move Player in direction of block | Player will stop before passing through any blocktype

## UI Menu- Manual Test
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Click to play button  | It will open the map
2 | Click to Settings button | It will chance the game setings
3 | Click to Tutorial button | It will show the Tutorial page and Tutorial game mode
4 | Click to Quit button | It will Quit the game
5 | Settings and Tutorial pages has back button| It will open the main menu again

## Bomb Pickup - Automated Test
Expectant behavior:
On Raycast emitting an collsion with actors (blocks, people, and power-ups), a debug message appears in the top left screen to deatil what actor(s) were hit.

## Player Bombs - Manual Test - Bomb.cpp
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Press R key on keyboard | Bomb spawns in front of player
2 | User waits | Bomb turns from red to black and back to red
3 | User waits | Bombsize variable changes in bomb based on player's explosionRadiusSizeLevel
4 | User waits | Bombhitbox spawns
5 | User waits | Emitter spawns showing visual of explosion
6 | User waits | Bomb changes the hitbox's radius
7 | User waits | Bomb actor is destroyed
8 | User waits | If close enough, Player health will decrease
9 | User waits | If close enough, breakable block health will decrease and get darker
10 | User waits | If close enough and if breakable block already has low health, breakable block actor gets destroyed
11 | User waits | If close enough and Player health is low enough, players dies
