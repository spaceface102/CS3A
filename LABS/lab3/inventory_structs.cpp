/*****************************************************************************
 * AUTHOR   : Osbaldo Gonzalez Jr.
 * LAB #3   : Inventory Struct
 * CLASS    : CS 3A
 * SECTION  : 71206
 * DUE DATE : 6/26/2021
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

//CONSTANTS
const int NUMBINS = 30; //warehouse only has space for 30 bins (used for array size)
//EOC

//STRUCTS
struct InventoryBin
{
    std::string partName;
    int numberOfParts;
};

struct Warehouse
{
    InventoryBin allBins[NUMBINS]; //array conting all the bins in the warehouse
    int binsOccupied;              //stores the last index of an occupied bin
};
//EOS

//FUNCTION DECLERATIONS/PROTOTYPES
void AddParts(Warehouse &w,                 //IN - warehouse struct ref
              const std::string &PpartName, //IN - string partName for related to InventoryBin struct
              int PhowMany                  //IN - defines how many more want to be added
              );
void RemoveParts(   Warehouse &w,                //IN - warehouse struct ref
                    const std::string &PpartName,//IN - string partName for related to InventoryBin struct
                    int PhowMany
                );
void AddItem(   Warehouse &w,                   //IN - warehouse struct ref
                const std::string &PpartName,   //IN - string partName for related to InventoryBin struct
                int PhowMany                    //IN - defines how many more want to be added
            );
void DisplayInventory(const Warehouse &w //IN - warehouse struct ref
                    );
void InitWarehouse( Warehouse &w,           //IN - warehouse struct ref
                    const std::string &fname//IN - The name of the inventory file for initializing
                    );
void InitWarehouse(Warehouse &w //IN - warehouse struct ref
                    );
int FindPartBin(const Warehouse &w,         //IN - warehouse struct ref
                const std::string &PpartName//IN - string partName for related to InventoryBin struct
                );
//EOFD/P

/* no RemoveItem function yet, would need to modify other funcs since
 * removing can be from anywhere in the structure, would be wise to maybe
 * use a linked list for that scenario */


/*****************************************************************************
 * 
 *   WAREHOUSE INVENTORY BIN, USING STRUCTS
 *______________________________________________________________________________
 * This program takes in input from a file to intiate inventory. From there on after
 * the user is prompted of a variety of choices such as add new item and update item 
 * it two ways, add or remove.
 *______________________________________________________________________________
 *  INPUT:
 *      std::string fname   - takes in the name of inventory file
 *      Warehouse warehouse - instance of the warehouse struct, store all pertinent info here
 *      std::string mainSelection  - used for main menu selection
 *      std:string nestedSelection - used for sub menu selection
 *      std::string whichBin       - used to determine which inventory is going to be modified
 *      std::string partDescription- used to name new inventory bin to be added
 *      int         numOfParts     - used to get the number of new parts by new inventory bin  
 *  OUTPUT:
 *      int counts[]:  Used to track the times of each roll, used by printHistogram()
*****************************************************************************/

//MAIN
int main(void)
{
    std::string fname;           //IN - get the file name of inventory file
    Warehouse warehouse;         //PROC && IN - stores all the bins, and current number of filled bins
    std::string mainSelection;   //IN - choose selection for either add item, select bin, or quit
    std::string nestedSelection; //IN - choose if want to remove parts or add parts, only used when select bin option is used
    std::string whichBin;        //IN - if selection == 's', then have to choose whichBin to do something to
    std::string partDescription; //IN - if selection == 'a', then have to describe part
    int numOfParts;              //IN - to specify the number of added parts if selection = 's' or the number of parts for new bin if selection = 'a'
    //INPUT
    std::cout << "Enter name of inventory file: ";
    std::cin >> fname;

    //PROC - init warehouse using fname file content
    InitWarehouse(warehouse, fname);

    //MAIN OUTPUT - Let user get or put data as needed
    do //MAIN LOOP
    {
        DisplayInventory(warehouse);
        do //loop used to redo menu input if selection is out of bounds
        {
            std::cout << "Menu:\n";
            std::cout << "Add a new item (a)\n";
            std::cout << "Select a bin (s)\n";
            std::cout << "Quit (q)\n";
            std::cout << "\n";

            std::cout << "Selection: ";
            std::cin >> mainSelection;

            if (mainSelection[0] == 'a')
            {
                std::cout << "\n"; //hypergrade formating, I have no idea why
                std::cout << "Enter Part Description: ";
                std::cin.ignore(1);                 //avoid trailing '\n'
                getline(std::cin, partDescription); //done just incase part description has space
                std::cout << "Number of Parts in the Bin: ";
                std::cin >> numOfParts;
                AddItem(warehouse, partDescription, numOfParts);
                std::cout << "\n"; //spacer
            }
            else if (mainSelection[0] == 's')
            {
                std::cout << "Bin Selection: ";
                std::cin >> whichBin;
                std::cout << "\n"; //spacer

                do //similar story here, since needs to repeat menu if selection is out of bounds
                {
                    std::cout << "Menu:\n";
                    std::cout << "Add parts (a)\n";
                    std::cout << "Remove parts (r)\n";
                    std::cout << "\n"; //spacer

                    std::cout << "Selection: ";
                    std::cin >> nestedSelection;
                    if (nestedSelection[0] == 'a')
                    {
                        std::cout << "Number of parts to add: ";
                        std::cin >> numOfParts;
                        AddParts(warehouse, whichBin, numOfParts);
                    }
                    else if (nestedSelection[0] == 'r')
                    {
                        std::cout << "Number of parts to remove: ";
                        std::cin >> numOfParts;
                        RemoveParts(warehouse, whichBin, numOfParts);
                    }
                    else
                        std::cout << "\n"; //spacer
                } while (nestedSelection[0] != 'a' && nestedSelection[0] != 'r');
            }
            else if (mainSelection[0] != 'q') //'q' is special since it makes the code quit
                std::cout << "\n";            //spacer
        } while (mainSelection[0] != 'a' && mainSelection[0] != 's' && mainSelection[0] != 'q');
    } while (mainSelection[0] != 'q');
    //I could be more clever and use a variadic function solution for the menu
    //and just have all the logic there, but we haven't learned that yet, so
    //I will keep it nice and simple
    std::cout << "Good Bye!!!\n";

    return 0;
}
//EOF

//FUNCTION DEFINITIONS

/*****************************************************************************
 * FUNCTION DisplayInventory
 *______________________________________________________________________________
 * Takes in a warehouse struct and prints all inventory bins in ordered fashion
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  There must exist a warehouse struct, since the function passes args by reference 
 * 
 * POST-CONDITIONS
 * The warehouse struct is assured to not be touched. Only printing is done
*****************************************************************************/
void DisplayInventory(const Warehouse &w)
{
    //it is just way easier to format output with printf...
    for (int i = 0; i < w.binsOccupied; i++)
        printf("%-20s%3d\n", w.allBins[i].partName.c_str(), w.allBins[i].numberOfParts);
    std::cout << "\n"; //spacer
}
//EOF

/*****************************************************************************
 * FUNCTION InitWarehouse
 *______________________________________________________________________________
 * Takes in a warehouse struct and the filename (fname) of an inventory file.
 * The warehouse struct is then filled with the data, such as productName and
 * productNumber
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  fname must be a file located in the same directory of the executable. 
 *  warehouse must be a declared variable, since need to pass by ref.
 *  The file must be ordered where each line contains new information,
 *  look at example file for more details.
 * 
 * POST-CONDITIONS
 * The warehouse struct only has a limited amount of space. If it gets
 * filled it will simply not continue getting information, and the 
 * function will return early.
*****************************************************************************/
void InitWarehouse(Warehouse &w, const std::string &fname)
{
    std::ifstream file;            //IN        - collect partname and partnumber data for warehouse struct
    std::string numberOfParts_str; //TEMP/PROC - gets string for file, then used to convert to int for numberOfParts

    file.open(fname); //open file with warehouse inventory

    w.binsOccupied = 0; //init to 0, will be used to fill in .allBins array
    for (int linenum = 0; file; linenum++)
    {
        if (w.binsOccupied == NUMBINS)
        {
            std::cout << "Can not fit more inventory!\n";
            return; //done
        }
        if (linenum % 2 == 0) //get part name from the file and store in current bin
            std::getline(file, w.allBins[w.binsOccupied].partName);
        else
        {
            std::getline(file, numberOfParts_str);
            w.allBins[w.binsOccupied].numberOfParts = std::stoi(numberOfParts_str);
            w.binsOccupied += 1; //get ready for the next bin
        }
    }
}
//EOF

/*****************************************************************************
 * FUNCTION InitWarehouse
 *______________________________________________________________________________
 * An overload of the previous InitWarehouse, done just incase programer
 * forgets/does not want to load a file, will just set .binsOccupied to 0.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 * warehouse must be a declared variable, since need to pass by ref.
 * POST-CONDITIONS
 *  The struct WILL NOT have any other information initalized.
 *  The InventoryBin struct array can/will have garbage values. 
*****************************************************************************/

void InitWarehouse(Warehouse &w)
{
    w.binsOccupied = 0;
    //since no file given, this is the exten of the initialization done.
}
//EOF

/*****************************************************************************
 * FUNCTION AddItem
 *______________________________________________________________________________
 * Adds a completely new item to the warehouse.
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 * There must be enough space in the warehouse struct to add an item.
 * 
 * POST-CONDITIONS
 * If enough space was available, the new partbin will now be ascesible and
 * ready to be print!
*****************************************************************************/

void AddItem(Warehouse &w, const std::string &PpartName, int PhowMany)
{
    if (w.binsOccupied == NUMBINS)
    {
        std::cout << "Sorry, ran out of space\n";
        std::cout << "Max Bins = " << NUMBINS << "\n";
        return; //end exectution early
    }
    //else, good to move forward

    w.allBins[w.binsOccupied].partName = PpartName;
    w.allBins[w.binsOccupied].numberOfParts = PhowMany;

    w.binsOccupied += 1; //get ready for the next bin
}
//EOF

/*****************************************************************************
 * FUNCTION AddParts
 *______________________________________________________________________________
 * Adds an item to an already preexisting inventory bin the the struct warehouse
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The bin must exist, aka, there must be the same partName for a bin in the
 *  struct, if not, nothing will be done.
 * 
 * POST-CONDITIONS
 * If inventory bin is found in the warehouse struct, then it will be
 * ready to print and display it's new value.
*****************************************************************************/

void AddParts(Warehouse &w, const std::string &PpartName, int PhowMany)
{
    int partIndex; //PROC - temp variable to determine if the partName was found

    partIndex = FindPartBin(w, PpartName); //will return -1 if nothing is found
    if (partIndex < 0)
        std::cout << PpartName << " was not found in the warehouse.\n";
    else
        w.allBins[partIndex].numberOfParts += PhowMany;
}
//EOF

/*****************************************************************************
 * FUNCTION RemoveParts
 *______________________________________________________________________________
 * Removes items from an already preexisting inventory bin the the struct warehouse
 * Will modify the .numberOfParts atribute
 * _____________________________________________________________________________
 * PRE-CONDITIONS
 *  The bin must exist, aka, there must be the same partName for a bin in the
 *  struct, if not, nothing will be done.
 * 
 * POST-CONDITIONS
 * If inventory bin is found in the warehouse struct, then it will be
 * ready to print and display it's new value.
*****************************************************************************/
void RemoveParts(Warehouse &w, const std::string &PpartName, int PhowMany)
{
    int partIndex; //PROC - temp variable to determine if the partName was found

    partIndex = FindPartBin(w, PpartName);
    if (partIndex < 0)
        std::cout << PpartName << " was not found in the warehouse.\n";
    else
        w.allBins[partIndex].numberOfParts -= PhowMany;
}
//EOF

int FindPartBin(const Warehouse &w, const std::string &PpartName)
{
    for (int i = 0; i < w.binsOccupied; i++)
    {
        if (PpartName == w.allBins[i].partName)
            return i;
    }
    return -1; //did not find a match, PpartName is not in the warehouse
}
//EOF