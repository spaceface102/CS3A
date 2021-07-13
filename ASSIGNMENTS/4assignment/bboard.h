#ifndef BBOARD_CLASS_H
#define BBOARD_CLASS_H

#include "user.h"
#include "message.h"
#include <vector>
#include <string>


class BBoard
{
private:
    std::string title;                //IN/OUT - bulletin board title
    std::vector<User> user_list;      //IN/OUT - all users (names, passwords)
    User current_user;                //IN/OUT - the user initially logged in
    std::vector<Message> message_list;//IN/OUT - all messages any user

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    BBoard(void);
    BBoard(const std::string& ttl);

    /*************
    ** MUTATORS **
    *************/
    void setup(const std::string& input_file);
    void login(void);
    void run(void);

private:
    /*************
    ** MUTATORS **
    *************/
    void add_user(std::istream& in);
    void add_user(const std::string& name, const std::string& pass);
    void add_message(std::istream& in, std::ostream& out);

    /**************
    ** ACCESSORS **
    **************/
    void display(std::ostream& out) const;

    /*********************
    ** HELPER FUNCTIONS **
    *********************/
    void GetText(std::istream& in, std::string& str) const;
};
#endif //BBOARD_CLASS_H


/********************************************************************
 * BBoard Class
 *  This class reprsents a bulletin board object. It manages 4
 *  attributes, tite (std::string), user_list (std::vector<User>)
 *  current_user (User), message_list (std::vector<Message>)
********************************************************************/


/*****************************
** CONSTRUCTOR & DESTRUCTOR **
*****************************/

/********************************************************************
 * BBoard(void);
 * 
 *      Constructor; Initialize all class attributes
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * BBoard(const std::string& ttl);
 * 
 *      Constructor; Initialize all class attributes
 * ------------------------------------------------------------------
 *      Paramters: ttl (string) //IN - the title for BBoard object
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/


/*************
** MUTATORS **
*************/

/********************************************************************
 * void setup(const std::string& input_file);
 * 
 *      Mutator; Setup for builtin board, get user names and
 *      passwords; fill user_list.
 * ------------------------------------------------------------------
 *      Paramters: input_file (string) //IN - allowed users file
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * void login(void);
 * 
 *      Mutator; Asks user to login, sets new curren_user
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * void run(void);
 * 
 *      Mutator; Runs the builtin board; allows logged in user
 *      to view to display messages, add a new message, or quit
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * void add_user(std::istream& in);     //OVERLOAD 1
 * 
 *      Mutator; pushes a user to the private user_list attribute
 * ------------------------------------------------------------------
 *      Paramters: in (istream) //IN - defines a file to add user from
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * void add_user(const std::string& name, const std::string& pass);     
 * //OVERLOAD 2
 * 
 *      Mutator; pushes a user to the private user_list attribute
 * ------------------------------------------------------------------
 *      Paramters: name (string)    //IN - name for the new user
 *                 pass (string)    //IN - password for the new user
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * void add_message(std::istream& in, std::ostream& out);
 * 
 *      Mutator; pushes a message to the private message_list attribute
 * ------------------------------------------------------------------
 *      Paramters: in  (istream)    //IN - input stream to get message
 *                 out (ostream)    //IN - output stream to output
 *                                  //     related instructions
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/



/**************
** ACCESSORS **
**************/

/********************************************************************
 * void display(std::ostream& out) const;
 * 
 *      Accessor; displays all messages to output stream
 * ------------------------------------------------------------------
 *      Paramters: out (ostream)    //IN - where all output is
 *                                  //forwared to
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/


/*********************
** HELPER FUNCTIONS **
*********************/

/********************************************************************
 * void GetText(std::istream& in, std::string& str) const;
 * 
 *      Helper; gets one single line of text, without any side affects
 * ------------------------------------------------------------------
 *      Paramters: in (istream) //IN - where input is supposed to
 *                              //be extracted from
 *                 str (string) //IN - string to store input for
 *                              //any general use
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/