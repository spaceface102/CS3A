#include "listEmpty.h"

/****************************************************************
 * 
 *  Method Constructor: Class ListEmpty
 *  //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 *  Set default exception message.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      It is now ok to use the .what() method in this class.
****************************************************************/
ListEmpty::ListEmpty(void) : message("Empty list!") {}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class ListEmpty
 *  //CONSTRUCTOR
 * --------------------------------------------------------------
 *  Sets a custom message that can be latter accessed with the
 *  .what method
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      It is now ok to use the .what() method in this class.
****************************************************************/
ListEmpty::ListEmpty(const std::string& message) : message(message) {}
//EOF

/****************************************************************
 * 
 *  Method what: Class ListEmpty
 *  //PUBLIC
 * --------------------------------------------------------------
 *  Returns a const reference to the private field std::string
 *  message, which specifies the ListEmpty exception message.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must use method on an object. Not a static method
 * 
 *  POST-CONDITIONS
 *      The private cannot be modified unintentionally. The
 *      returned message will never be an empty string.
****************************************************************/
const std::string& ListEmpty::what(void) const
    {return message;}
//EOF