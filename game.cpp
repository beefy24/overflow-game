#include "input.h"
#include "output.h"
#include "vector2.h"
#include "player.cpp"
#include <iostream>
#include <string>

using namespace std;

class Game
{
protected:
    Player player;
    string rawInput;
    InputToken input;
    bool winState;
    
    //Checks whether the player's position overflowed.
    bool checkOverflow ()
    { 
        short newValue;
        short oldValue;
        
        if (player.getPosition().x != player.getLastPosition().x)
        {
            newValue = player.getPosition().x;
            oldValue = player.getLastPosition().x;
        }
        else if (player.getPosition().y != player.getLastPosition().y)
        {
            newValue = player.getPosition().y;
            oldValue = player.getLastPosition().y;
        }
        else { return false; }
        
        if (newValue == SHORT_INT_MAX && oldValue == SHORT_INT_MIN || newValue == SHORT_INT_MIN && oldValue == SHORT_INT_MAX)
        { return true; } else { return false; }
    }

public:
    Game() : player(Vector2::getRandomVector())
    {
        winState = false;
    }

    bool getWinState () {return winState;}

    InputToken getCurrentInput () {return input;}

    void handleInput ()
    {
        print(": ");
        
        cin >> rawInput;

        input = parseInputString(rawInput);
    }

    void updateGame ()
    {
        player.doAction(input);
        if (checkOverflow()) winState=true;
    }

    void renderGameScreen ()
    {   
        system("clear");
        if (input == GET_HELP) print("Help\n====\n", GameText::helpText);
        print(player.getActionText());
        print(player.getPositionText());
        if (winState == true) print (GameText::winText);
        if (input == EXIT_GAME) print (GameText::exitText);
    }

    void renderStartScreen ()
    {
        system("clear");
        print(GameText::welcomeText);
        print("Press enter to start.");

        flushInputStream(); //Wait for Enter, then flush the input stream.
        
        system("clear");
        print(player.getActionText());
    }
};