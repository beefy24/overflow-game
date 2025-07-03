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
    string actionText;
    string positionText;
    int steps;

    void updatePositionText ()
    {
        positionText = concatenate("You are now at position x:", position.x, "; y:", position.y, " and made ", steps, " steps.\n");
    }
    
public:    
    Player (Vector2 pos = {0,0}) {
        position = {pos.x, pos.y};
        lastPosition = position;
        steps = 0;
        actionText = concatenate("You start at position x:", position.x, "; y:", position.y, ".");
        positionText = "";
    };

    Vector2 getPosition () const {return position;}
    
    Vector2 getLastPosition () const {return lastPosition;}

    const string& getActionText() const
    {
        return actionText;
    };

    const string& getPositionText() const
    {
        return positionText;
    };
    
    void doAction (const InputCommand input) {
        
        lastPosition = position;
        
        switch (input)
        {
            case MOVE_UP:
            {
                actionText = "moved up";
                position.y += 1;
                ++steps;
                break;
            };
            
            case MOVE_DOWN:
            {
                actionText = "moved down";
                position.y -= 1;
                ++steps;
                break;
            };

            case MOVE_LEFT:
            {
                actionText = "moved left";
                position.x -= 1;
                ++steps;
                break;
            };

            case MOVE_RIGHT:
            {
                actionText = "moved right";
                position.x += 1;
                ++steps;
                break;
            };
            
            case DO_NOTHING:
            {
                actionText = "did nothing";
                break;
            };

            case TELEPORT:
            {
                actionText = "were teleported";
                Vector2 newPosition = Vector2::getRandomVectorNearOverflow(5,10);
                lastPosition = position = newPosition;
                break;
            };
            
            case NO_INPUT:
            {
                actionText = "What do you mean?";
                updatePositionText();
                return;
            };

            default:
                return;
        }

        actionText = "You " + actionText + ".";
        updatePositionText();
    };
};