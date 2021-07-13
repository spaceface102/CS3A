#include "user.h"

/****************************************************************
 * 
 *  Method Constructor: Class User       //DEFAULT CONSTRUCTOR
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
User::User()
{
    username = "";
    password = "";
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class User       //CONSTRUCTOR
 * --------------------------------------------------------------
 * This is a constructor method. The new object will use this 
 * constructor if two std::string arg is passed. The passed in
 * args are used to set username and password pair for a user
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with two
 *      std::string args.
 * 
 *  POST-CONDITIONS
 *      The object is now ready use all the public interface
 *      methods.
****************************************************************/
User::User(const std::string& uname, const std::string& pass)
{
    username = uname;
    password = pass;
}
//EOF

/****************************************************************
 * 
 *  Method get_username: Class User      //PUBLIC INTERFACE
 * --------------------------------------------------------------
 * Returns a new std::string object with a copy of the private
 * atributes username data.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call from an object. Not a static method
 * 
 *  POST-CONDITIONS
 *      Can modify the returned object, and will have no effect
 *      on the calling object's private username. Its a copy!
****************************************************************/
std::string User::get_username() const
{
    return username;
}
//EOF

/****************************************************************
 * 
 *  Method check: Class User      //PUBLIC INTERFACE
 * --------------------------------------------------------------
 * Compares the private object's string attributes with two passed
 * in std::string args. If both the usernames and passwords are
 * equal will return true, else false
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call from an object. Not a static method
 * 
 *  POST-CONDITIONS
 *      Object's state is not modified. Just returns a boolean
****************************************************************/
bool User::check(const std::string &uname, const std::string &pass) const
{
    return (username == uname) && (password == pass);
}
//EOF

/****************************************************************
 * 
 *  Method set_password: Class User      //PUBLIC INTERFACE
 * --------------------------------------------------------------
 * Sets a new password to the User object.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must call from an object. Not a static method
 * 
 *  POST-CONDITIONS
 *      Object's state is not modified. Just returns a boolean
****************************************************************/
void User::set_password(const std::string &newpass)
{
    password = newpass;
}
//EOF