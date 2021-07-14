/*****************************************************************************
 * AUTHOR   : Osbaldo Gonzalez Jr. && Sasha Saaed-Marmorstein
 * LAB #14  : Minotaur Maze (Recursive)
 * CLASS    : CS 3A
 * SECTION  : 71206
 * DUE DATE : 7/13/2021
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

//CONSTANTS && ENUMS
const int ROWS = 19;
const int COLS = 23;
const bool IS_WALL = true;
const int BREAK_NUM_WALLS = 2;
enum Direction {NORTH = 0, SOUTH, WEST, EAST};

//FUNCTION PROTOTYPES
/*****************************************************************************
 * Minotaur
 *  This function takes in a boolean 2D array, map, and an x and y
 *  position. It carves out the map, by removing walls until it
 *  can't remove any more walls.
 * 
 * ReadyForBreak
 *  Usually paired in tandel with the BreakWalls function, used to
 *  check if the random direction and current x and y position will
 *  allow to break BREAK_NUM_WALLS consecutively.
 * 
 * BreakWalls
 *  Removes walls from the map (sets an index to !IS_WALL)
 *
 * RangeCheck
 *  Checks if x and y positions are valid for the boolean map 2D array.
 *  Meaning, the x and y positions are within the inside walls of map.
 *
 * DisplayMap
 *  Displays walls and blank characters based on the boolean map.
 *  If index is true, then display a wall, other wise display 
 *  a passed in blank_char.   
*****************************************************************************/
void Minotaur(bool map[ROWS][COLS], int x, int y);
bool ReadyForBreak(const bool map[ROWS][COLS], int x, int y, int direction);
void BreakWalls(bool map[ROWS][COLS], int x, int y, int direction);
bool RangeCheck(int x, int y);
void DisplayMap(bool map[ROWS][COLS], const char *wall_char,
                const char *blank_char);


/*******************************************************************************
 *  FUNCTION - main
 *      first the rows and columns of the map array are filled with 
 *      Is_Wall(true) statements then an entrance and exit to the maze
 *      are determined to be a random odd number not on the sides of 
 *      the maze. the entrance and exit are then set to not be walls 
 *      the minotaur recursive loop is then called and the resulting
 *      maze is displayed.
 *  Pre-Conditions:
 *      none
 *
 *  Post-Conditions:
 *     none
 *
 * ****************************************************************************/
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

/*******************************************************************************
 *  FUNCTION - DisplayMap(bool map[ROWS][COLS],
 *                 const char *wall_char, const char *blank_char)
 *
 *   for every location in the map array, if map at that location is true,
 *  a character representing a wall is printed, otherwise a blank character is
 *   printed, resulting in a maze
 *
 *  Pre-Conditions:
 *bool map[rows][cols]- boolean array that determines where there is or isn't a wall
 *const char *wall_char- what will be displayed if map returns true
 *  const char *blank_char- what will be displayed if map returns false
 *
 *  Post-Conditions:
 *      
 * ****************************************************************************/
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

/*******************************************************************************
 *  FUNCTION -Minotaur(bool map[ROWS][COLS],int x, int y)
 *
 *    a random direction is chosen, and if readyforbreak returns true,
 *     break_num_walls walls are erased and the function calls itself recursively.
 *     in the case readyforbreak returns false,
 *     a new random direction is chosen and tracked in a direction tracker.
 *     if no directions return true the function ends ,
 *
 *  Pre-Conditions:
 * bool map[ROWS][COLS]: array that keeps track of where there are and aren't walls
 * int x- current x location of the minotaur(tells where walls should be broken 
 * and where to check for what moves are allowed)
 * int y-current y location of the minotaur(tells where walls should be broken
 * and where to check for what moves are allowed)
 *
 *  Post-Conditions:
 *      bool map[ROWS][COLS]:when walls are broken it is permanently changed
 *        in map because it is called by reference
 *
 * ****************************************************************************/
void Minotaur(bool map[ROWS][COLS], int x, int y)
{
    int randDir;            //PROC - choose a random direction
    bool trackDirection[4]; //PROC - track if a direction has been done already

    //set to all false, no direction has been "activated" yet
    trackDirection[0] = trackDirection[1]
    = trackDirection[2] = trackDirection[3]
    = false;
    
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

/*******************************************************************************
 *  FUNCTION - RangeCheck
 *    checks to make sure that the x and y values are not going to be on the edges 
 *     of the map if shipped into the map array.
 *     only returns true if x and y are not on the sides.
 *     
 *
 *  Pre-Conditions:
 *      int x-x value to be shipped into the map array
        int y-y value to be shipped into the map array
 *
 *  Post-Conditions:
 *      bool RangeCheck- true if x and y are within our limitations
 *
 * ****************************************************************************/
bool RangeCheck(int x, int y)
{
    return x > 0 && x < COLS - 1 && y > 0 && y < ROWS - 1;
}

/*****************************************************************************
 * FUNCTION ReadyForBreak
 *______________________________________________________________________________
 *  This function decides if, based on the current x (column) and 
 *  y (rows) position and direction, if removing the walls from map
 *  is OK to do. This will do a bounds check to make sure that the
 *  projected x and y positions are inside the map, and are not
 *  touching the corners. If the "new" x and y positions are invalid
 *  will just return false. The function will also make sure that
 *  there are still walls to remove in the direction of choice. If not
 *  then the function will return false.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *      The direction arg should be equivalent to one of the
 *      Direction enum values (NORTH, SOUTH, WEST, EAST). If
 *      not, will simply return false. 
 *      If the passed in x and y arguments are not in range,
 *      the function will return false even before the indicies
 *      in map can be touched.
 * 
 * POST-CONDITIONS
 *      The boolean map array passed in is not modified; no
 *      "walls" are removed in this function, we only check for
 *      the existence of the walls, and if they do exits, then
 *      we return true, else false. The number of walls we check
 *      for is defined by the global constant BREAK_NUM_WALLS.
*****************************************************************************/
bool ReadyForBreak(const bool map[ROWS][COLS], int x, int y, int direction)
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

/*****************************************************************************
 * FUNCTION BreakWalls
 *______________________________________________________________________________
 *  This function will set the indicies right in front of 
 *  the passed in x (column) and y (row) positions to empty. The
 *  number of indicies set to not a wall is defined by the
 *  global constant, BREAK_NUM_WALLS. The direction parameter
 *  serves to handle in which direction we will traverse the
 *  map, removing the existing walls.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *      The x (column) and y (row) positions are not bounds
 *      checked. If you are close to the edge of the map 
 *      2D array, you will access invalid memory.
 * 
 * POST-CONDITIONS
 *      The passed in x, y, and direction arguments are not
 *      not modified. map is assured to be modified. All 
 *      the indicies affected/changed are all set to !IS_WALL (false).
*****************************************************************************/
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