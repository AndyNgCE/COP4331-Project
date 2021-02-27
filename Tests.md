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