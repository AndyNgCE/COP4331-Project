## Character Movement - Manual Test - character.cpp
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Press up key on keyboard | Move forward
2 | Press left key on keyboard | Turn left
3 | Press right key on keyboard | Turn right
4 | Press back key on keyboard | Move back
5 | Hold shift + press left on keyboard | Moves left(camera locked)
6 | Hold shift and press right on keyboard | Moves right(camera locked)
7 | Move Player in direction of block | Player will stop before passing through any blocktype

## Character Movement Interaction (bombs) - Manual Test - Bombs.cpp
No | Steps to Reproduce | Expected Behavior
--|--------------|-------------------------
1 | Press up key on keyboard | Move forward until reaching bomb
2 | Player reaches bomb after moving forward | Player movement stops
3 | Press back key on keyboard | Move backwards until reaching bomb
4 | Player reaches bomb after moving backwards | Player movement stops
5 | Hold shift + press left on keyboard | Moves left(camera locked) until reaching bomb
6 | Player reaches bomb after moving backwards | Player movement stops
7 | Hold shift and press right on keyboard | Moves right(camera locked) until reaching bomb
8 | Player reaches bomb after moving backwards | Player movement stops
9 | Move Player in direction of block | Player will stop before passing through any blocktype
