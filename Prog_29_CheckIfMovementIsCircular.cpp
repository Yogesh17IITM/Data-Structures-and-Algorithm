/*
    Check if a given sequence of moves for a robot is circular or not

    Given a sequence of moves for a robot, check if the sequence is circular or not. 
    A sequence of moves is circular if first and last positions of robot are same. 

    A move can be on of the following:
            G - Go one unit
            L - Turn left
            R - Turn right 

    Examples:

        Input: path[] = "GLGLGLG"
        Output: Given sequence of moves is circular

        Input: path[] = "GLLG"
        Output: Given sequence of moves is circular                         
*/

#include<iostream>
using namespace std;

#define NORTH 0     // ('L' --> 'West',  'R' --> 'East')
#define EAST 1      // ('L' --> 'North', 'R' --> 'South')
#define SOUTH 2     // ('L' --> 'East',  'R' --> 'West')
#define WEST 3      // ('L' --> 'South', 'R' --> 'North')

/*
                N (0 , 1)
                |
                |
W (-1, 0) ____(0,0) ____ E (1, 0)
                |
                |
                S (0, -1)
*/

bool IsRobotSequenceCircular(string iStrPath)
{
    bool obIsCircular = false;
    pair<int, int> Coordinates(0,0);    // x,y Coordinates
    int CurrDirection = EAST;           // Assuming 'East' facing

    for (int idx=0; idx<iStrPath.length(); idx++)
    {
        // 'G' -> Actual Movement for 1 units
        if (iStrPath[idx] == 'G')   // Move the robot position
        {
            switch (CurrDirection)
            {
            case EAST:
                Coordinates.first += 1;
                break;
            case WEST:
                Coordinates.first -= 1;
                break;
            case NORTH:
                Coordinates.second += 1;
                break;
            case SOUTH:
                Coordinates.second -= 1;
                break;
            default:
                break;
            }
        }        
        else    // Set/Change the direction
        {
            // 'L' and 'R' refers to direction
            if (iStrPath[idx] == 'R')
            {
                CurrDirection = (CurrDirection + 1) % 4;        // 0 1 2 3 
            }
            else
            {
                CurrDirection = (4 + (CurrDirection - 1)) % 4;  // 3 2 1 0
            }
        }
    }

    if (Coordinates.first == 0 && Coordinates.second == 0)
        obIsCircular = true;

    return obIsCircular;
}

int main()
{

    if (IsRobotSequenceCircular("GLLG"))
        cout << "Sequence is Circular" << endl;
    else
        cout << "Sequence is NOT circular" << endl;

    return 0;
}
