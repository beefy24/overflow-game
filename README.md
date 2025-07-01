## What is this?
This is a text-based walking game, and its sole purpose is to be a beginner game development learning exrecise in C++.
The only goal in this game is to walk far enough so that one of the integers overflows.  

### How does it work?
The program is a loop of three simple steps: take an input, update the game state, and render the output.  
The game has only two states: a play state and a win state.
Once the player wins, the game ends.  
The code is split into three .cpp files containing the logic, and three .h files containing common functions and data.

### Improvement ideas:
- Prompt the player to enter their name at the beginning.
- Store a leaderboard in a file ranking players by the highest number of steps.
- Add randomly placed obstacles (walls) forcing the player to move around them.
- Add randomly placed traps (pits, mines, monsters) requiring the player to type a special command or solve a puzzle before continuing.
