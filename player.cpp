#include "input.h"
#include "output.h"
#include "vector2.h"
#include <string>

using namespace std;

class Player
{
protected:
    Vector2 position;
    Vector2 lastPosition;
    string feedbackText;
    int steps;
    
public:    
    Player (Vector2 pos = {0,0}) {
        position.x = pos.x;
        position.y = pos.y;
        lastPosition = position;
        steps = 0;
        feedbackText = concatenate("You start at position x:", position.x, "; y:", position.y, ".");
    };
    
    void doAction (const InputToken input) {
        
        lastPosition = position;
        
        switch (input)
        {
            case MOVE_UP:
            {
                feedbackText = "moved up";
                position.y += 1;
                ++steps;
                break;
            };
            
            case MOVE_DOWN:
            {
                feedbackText = "moved down";
                position.y -= 1;
                ++steps;
                break;
            };

            case MOVE_LEFT:
            {
                feedbackText = "moved left";
                position.x -= 1;
                ++steps;
                break;
            };

            case MOVE_RIGHT:
            {
                feedbackText = "moved right";
                position.x += 1;
                ++steps;
                break;
            };
            
            case DO_NOTHING:
            {
                feedbackText = "did nothing";
                break;
            };

            case TELEPORT:
            {
                feedbackText = "were teleported";
                Vector2 newPosition = Vector2::getRandomVectorNearOverflow(5,10);
                position = newPosition;
                lastPosition = newPosition;
                break;
            };
            
            case NO_INPUT:
            {
                feedbackText = "What do you mean?";
                return;
            };

            default:
                return;
        }

        feedbackText = "You " + feedbackText + ".";
    };

    string getActionText()
    {
        return feedbackText + "\n";
    };

    string getPositionText()
    {
        return concatenate("You are now at position x:", position.x, "; y:", position.y, " and made ", steps, " steps.\n");
    };

    Vector2 getPosition () {return position;}
    
    Vector2 getLastPosition () {return lastPosition;}
};
