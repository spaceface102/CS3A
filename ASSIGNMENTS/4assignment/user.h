#ifndef USER_CLASS_H
#define USER_CLASS_H

#include <string>
class User
{
private:
    std::string username;
    std::string password;

public:
    //creates a user with empty name and password.
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    User();

    // creates a user with given username and password.
    User(const std::string& uname, const std::string& pass);

    //returns the username
    /**************
    ** ACCESSORS **
    **************/
    std::string get_username() const;

    // returns true if the stored username/password matches with the
    // parameters. Otherwise returns false.
    // Note that, even though a User with empty name and password is 
    // actually a valid User object (it is the default User), this 
    // function must still return false if given a empty uname string.
    bool check(const std::string &uname, const std::string &pass) const;

    // sets a new password. This function will not be used in the 
    // current assignment.
    /*************
    ** MUTATORS **
    *************/    
    void set_password(const std::string &newpass);
};

#endif //USER_CLASS_H

/********************************************************************
 * User Class
 *  This class represents a user; used by the bulletin board class.
 *  It manages two std::string username and password
********************************************************************/


/*****************************
** CONSTRUCTOR & DESTRUCTOR **
*****************************/

/********************************************************************
 * User(void);
 * 
 *      Constructor; Initialize all class attributes, default user
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * User(const std::string& uname, const std::string& pass);
 * 
 *      Constructor; Initialize all class attributes, default user
 * ------------------------------------------------------------------
 *      Paramters: two const std::string&
 *                  uname   //IN - sets the username attribute
 *                  pass    //IN - set the password attribute
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/**************
** ACCESSORS **
**************/

/********************************************************************
 * std::string get_username() const;
 * 
 *      Accessor; gets the private username attribute
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    std::string (copy of private username attribute)
********************************************************************/

/********************************************************************
 * bool check(const std::string &uname, const std::string &pass) const;
 * 
 *      Accessor; checks if the passed in values are exactly
 *                  the same as the private attributes
 * ------------------------------------------------------------------
 *      Paramters: two const std::string&
 *                  uname   //IN - used to compare with private username
 *                  pass    //IN - used to compare with private password
 * ------------------------------------------------------------------
 *      Return:    bool //true if everything is the same, else false
********************************************************************/

/*************
** MUTATORS **
*************/

/********************************************************************
 * void set_password(const std::string &newpass);
 * 
 *      Mutator; changes the private attribute password to newpass
 * ------------------------------------------------------------------
 *      Paramters: const std::string&
 *                 newpass //IN - the new password to be set
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/