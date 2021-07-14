#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int ROWS = 19;
const int COLS = 23;
const bool IS_WALL = true;
const int BREAK_NUM_WALLS = 2;

enum Direction {NORTH = 0, SOUTH, WEST, EAST};

void Minotaur(bool map[ROWS][COLS], int x, int y);
bool ReadyForBreak(bool map[ROWS][COLS], int x, int y, int direction);
void BreakWalls(bool map[ROWS][COLS], int x, int y, int direction);
bool RangeCheck(int x, int y);
void DisplayMap(bool map[ROWS][COLS], const char *wall_char,
                const char *blank_char);

int main(void)
{
    #if DEBUG
    srand(333);
    #else
    srand(time(NULL));  //seeding the randomness
    #endif

    bool map[ROWS][COLS];
    int entrance, exit;

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            map[i][j] = IS_WALL;
    
    //setting entrance and exit
    entrance = (rand()%(COLS - 3)) + 1;
    exit = (rand()%(COLS - 3)) + 1;
    if (entrance % 2 == 0)
        entrance += 1;
    if (exit % 2 == 0)
        exit += 1;
    
    map[0][entrance] = !IS_WALL;
    map[ROWS-1][exit] = !IS_WALL;

    Minotaur(map, entrance, 1); 
    DisplayMap(map, "\u25A0", " ");
}

void DisplayMap(bool map[ROWS][COLS], const char *wall_char, const char *blank_char)
{
    #if DEBUG
    std::cout << "  ";
    for (int i = 0; i < COLS && i < 9; i++)
        std::cout << i << " ";
    for (int i = 9; i < COLS; i++)
        std::cout << i;
    std::cout << "\n";
    #endif

    for (int i = 0; i < ROWS; i++)
    {   
        #if DEBUG
        std::cout << std::setw(2) << i;
        #endif
        for (int j = 0; j < COLS; j++)
            std::cout << ((map[i][j]) ? wall_char : blank_char) << " ";
        std::cout << "\n";
    }
}

void Minotaur(bool map[ROWS][COLS], int x, int y)
{
    int randDir;    //PROC - choose a random direction
    bool trackDirection[4] = {false, false, false, false};
    
    do
    {
        randDir = rand()%4; //4 directions, N, S, W, E
        trackDirection[randDir] = true;
        if (ReadyForBreak(map, x, y, randDir))
        {
            BreakWalls(map, x, y, randDir);
            switch (randDir)
            {
                case NORTH:
                    Minotaur(map, x, y - BREAK_NUM_WALLS);
                    break;
                case SOUTH:
                    Minotaur(map, x, y + BREAK_NUM_WALLS);
                    break;
                case WEST:
                    Minotaur(map, x - BREAK_NUM_WALLS, y);
                    break;
                case EAST:
                    Minotaur(map, x + BREAK_NUM_WALLS, y);
                    break;
            }
        }
    } while (!(trackDirection[0] && trackDirection[1] && trackDirection[2]
             && trackDirection[3]));
   
    return; //have no more direction to go to!.
}

bool RangeCheck(int x, int y)
{
    return x > 0 && x < COLS - 1 && y > 0 && y < ROWS - 1;
}

//pass in unmodified (x, y) as the direction
//paramter will allow the function to deal with
bool ReadyForBreak(bool map[ROWS][COLS], int x, int y, int direction)
{
    bool isReady;   //PROC - Used to track if direction chosen has wall

    isReady = true; //default value
    switch (direction)
    {
        case NORTH:
            if (!RangeCheck(x, y - BREAK_NUM_WALLS))
                return false;
            for (int i = 1; i <= BREAK_NUM_WALLS; i++)
                isReady &= map[y - i][x];
            return isReady;
        case SOUTH:
            if (!RangeCheck(x, y + BREAK_NUM_WALLS))
                return false;
            for (int i = 1; i <= BREAK_NUM_WALLS; i++)
                isReady &= map[y + i][x];
            return isReady;
        case WEST:
            if (!RangeCheck(x - BREAK_NUM_WALLS, y))
                return false;
            for (int i = 1; i <= BREAK_NUM_WALLS; i++)
                isReady &= map[y][x - i];
            return isReady;
        case EAST:
            if (!RangeCheck(x + BREAK_NUM_WALLS, y))
                return false;
            for (int i = 1; i <= BREAK_NUM_WALLS; i++)
                isReady &= map[y][x + i];
            return isReady;
        default:    //another direction value that is not allowed.
            return false;
    }
}

void BreakWalls(bool map[ROWS][COLS], int x, int y, int direction)
{
    switch (direction)
    {
        case NORTH:
            for (int i = 1; i <= BREAK_NUM_WALLS; i++)
                map[y - i][x] = !IS_WALL;
            break;
        case SOUTH:
            for (int i = 1; i <= BREAK_NUM_WALLS; i++)
                map[y + i][x] = !IS_WALL;
            break;
        case WEST:
            for (int i = 1; i <= BREAK_NUM_WALLS; i++)
                map[y][x - i] = !IS_WALL;
            break;
        case EAST:
            for (int i = 1; i <= BREAK_NUM_WALLS; i++)
                map[y][x + i] = !IS_WALL;
            break;
        default:    //another direction value that is not allowed.
            return;
    }
}