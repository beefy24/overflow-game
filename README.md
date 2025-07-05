## What is this?
This is a text-based walking game, and its sole purpose is to be a beginner learning exrecise in C++.
The only goal in this game is to walk far enough so that one of the integers overflows.

## How does it work?
- A player provides control inputs by entering text commands in a trun-based manner.  
- The program runs in a loop of 3 steps: take an input, update the game state, and render the output.  
- The game has only two states: play and win.
Once a player wins, the game ends.  
- The code is split into .cpp files containing the logic, and .h files containing common functions and data.
