#include "message.h"
#include <iostream>

/****************************************************************
 * 
 *  Method Constructor: Class Message       //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 * This method sets the message object to all default values.
 * Aka, since all private numbers are std::strings, set to 
 * empty ("") strings.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      The object is now ready use all the public interface
 *      methods. Note though, will be only empty strings.
****************************************************************/
Message::Message(void)
{
    author = "";
    subject = "";
    body = "";
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class Message      //CONSTRUCTOR
 * --------------------------------------------------------------
 * This method takes three std::string args, athr (author), 
 * sbjct (subject), and Pbody (body/main message). It then
 * sets all the private atributes to those values.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with 
 *      three std::string arguments.
 * 
 *  POST-CONDITIONS
 *      The object is now ready use all the public interface
 *      methods. Note though, will be only empty strings.
****************************************************************/
Message::Message(const std::string &athr, 
        const std::string &sbjct, 
        const std::string &Pbody)
{
    author = athr;
    subject = sbjct;
    body = Pbody;
}
//EOF

/****************************************************************
 * 
 *  Method display: Class Message      //PUBLIC INTERFACE
 * --------------------------------------------------------------
 * This method displays the message object's private attributes
 * in a formated fashion. This includes subject, author and body.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must operate on an object. Not a static method!
 * 
 *  POST-CONDITIONS
 *      The object state will NOT change. The output will always
 *      go to std::cout.
****************************************************************/
void Message::display() const
{
    std::cout << subject << "\n";
    std::cout << "from " << author << ": " << body << "\n";
}
//EOF