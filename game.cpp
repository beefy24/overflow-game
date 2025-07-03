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
    InputCommand inputCommand;
    bool winState;
    
    //Checks whether the player's position overflowed.
    bool checkOverflow () const
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
        inputCommand = NO_INPUT;
        winState = false;
    }

    InputCommand getCurrentInput () const {return inputCommand;}
    
    bool getWinState () const {return winState;}

    //Takes a word from the input stream and translates it.
    void handleInput ()
    {
        print(": ");
        
        string rawInput;

        cin >> rawInput;

        inputCommand = translateInputWord(rawInput);
    }

    void updateGame ()
    {
        player.doAction(inputCommand);
        if (checkOverflow()) winState=true;
    }

    void renderGameScreen ()
    {   
        clearScreen();
        if (inputCommand == GET_HELP) printConcat("Help\n====\n", GameText::helpText , "\n\n");
        printLn(player.getActionText());
        print(player.getPositionText());
        if (winState == true) printConcat (GameText::winText, "\n\n");
        if (inputCommand == EXIT_GAME) printLn (GameText::exitText);
    }

    void renderStartScreen ()
    {
        clearScreen();
        printConcat(GameText::welcomeText, "\n\n");
        print("Press enter to start.");

        flushInputStream(); //Wait for Enter, then flush the input stream.
        
        clearScreen();
        printLn(player.getActionText());
    }
};