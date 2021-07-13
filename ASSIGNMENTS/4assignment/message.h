#ifndef MESSAGE_CLASS_H
#define MESSAGE_CLASS_H

#include <string>
class Message
{
private:
    std::string author;     //IN/OUT - author of the message
    std::string subject;    //IN/OUT - the subject of the message
    std::string body;       //IN/OUT - the body/main meat of the message

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    //default constructor
    Message(void);

    //Constructor with parameters
    Message(const std::string &athr, 
            const std::string &sbjct, 
            const std::string &Pbody);

    /**************
    ** ACCESSORS **
    **************/
    //displays the message in the given format. See output specs.
    void display() const;
};
#endif //MESSAGE_CLASS_H

/********************************************************************
 * Message
 *  This class represents a message in a bulletin board. It manages
 *  three std::string author, subject, and body.
********************************************************************/

/*****************************
** CONSTRUCTOR & DESTRUCTOR **
*****************************/

/********************************************************************
 * Message(void);
 * 
 *      Constructor; Initialize all class attributes
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * Message(const std::string &athr, 
 *         const std::string &sbjct,
 *         const std::string &Pbody);
 * 
 *      Constructor; Initialize all class attributes
 * ------------------------------------------------------------------
 *      Paramters: three const std::string&
 *                  athr    //IN - set author name
 *                  sbjct   //IN - set the subject
 *                  Pbody   //IN - set the body string
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/**************
** ACCESSORS **
**************/

/********************************************************************
 * void display() const;
 * 
 *      Accessor; displays all messages to std::cout
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/