#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int ROWS = 19;
const int COLS = 23;
const bool IS_WALL = true;
const int BREAK_NUM_WALLS = 2;

void DisplayMap(bool map[ROWS][COLS], const char *wall_char, const char *blank_char);
bool IsExit(int x, int y, int exit);
bool RangeCheck(int x, int y);
void Minotaur(bool map[ROWS][COLS], int x, int y);

int main()
{
    srand(time(NULL));  //seeding the randomness

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

    Minotaur(map, entrance, 1); //start on the entrance column and row 1.
    DisplayMap(map, "\u25A0", "*");
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
            std::cout << ( (map[i][j]) ? wall_char : blank_char) << " ";
        std::cout << "\n";
    }
}

void Minotaur(bool map[ROWS][COLS], int x, int y)
{

}