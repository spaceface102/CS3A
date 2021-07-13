#include "bboard.h"
#include <iostream>

/*****************************************************************************
 * AUTHOR       : Osbaldo Gonzalez Jr.
 * Assignment 1 : Bulletin Board
 * CLASS        : CS 3A
 * SECTION      : 71206
 * DUE DATE     : 7/4/2021
*****************************************************************************/

/*****************************************************************************
 * 
 *   CONSOLE Bulletin Board
 *______________________________________________________________________________
 *      Bulletin Board Skeleton, single user, message board, with login
 *      credentials. Comand line file arg for user auth file.
 *______________________________________________________________________________
 *  INPUT:
 *      None
 *  OUTPUT:
 *      None
*****************************************************************************/

int main(int argc, char* argv[])
{
    BBoard bb("My Board hehe"); //PROC&&OUTPUT - Bultin Board

    if (argc <= 1)
    {
        std::cout << "Please pass in the Authorized Users"
        << " File as a command line arg!\n";
        return 1;
    }

    bb.setup(argv[1]);
    bb.login();
    bb.run();
    return 0;
}