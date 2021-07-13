#ifndef MUSIC_COLLECTION_CLASS_H
#define MUSIC_COLLECTION_CLASS_H

#include <iostream>
#include <string>

class Tune
{
private:
    std::string title;  //IN - the title of a song/tune

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    Tune(void);
    Tune(const std::string &n);

    /**************
    ** ACCESSORS **
    **************/
    const std::string& get_title() const;
};

class Music_collection
{
private: 
    int number; // the number of tunes actually in the collection 
    int max;    // the number of tunes the collection will ever be able to hold 
    Tune *collection; // a dynamic array of Tunes: "Music_collection has-many Tunes"

public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    // default value of max is a conservative 100
    Music_collection(void);     

    // sets max to n
    Music_collection(int n); 

    // overloaded copy constructor
    Music_collection(const Music_collection& m);

    // Destructor
    ~Music_collection(void);

    /*************
    ** MUTATORS **
    *************/
    // returns true if add was successful, 
    // returns false if not enough room to add
    bool add_tune(const Tune& t);

    // sets the Tune at position index in collection to t, 
    // returns true if index < number    
    bool set_tune(int index, const Tune& t);

    // overloaded assignment operator
    Music_collection& operator=(const Music_collection& m);

    /**************
    ** ACCESSORS **
    **************/
    // overloaded stream insertion operator
    // outputs the title of each Tune in the collection on a separate line
    friend std::ostream& operator<<(std::ostream& out,
                                    const Music_collection& m);
};

#endif //MUSIC_COLLECTION_CLASS_H


/********************************************************************
 * Tune Class
 *      A std::string title of a song/tune wrapped in a class.
********************************************************************/

/*****************************
** CONSTRUCTOR & DESTRUCTOR **
*****************************/

/********************************************************************
 * Tune(void);
 * 
 *      Constructor; Initialize all class attributes
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * Tune(const std::string& n);
 * 
 *      Constructor; Initialize all class attributes
 * ------------------------------------------------------------------
 *      Paramters: const std::string& n //IN - new title
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/**************
** ACCESSORS **
**************/

/********************************************************************
 * const std::string& get_title() const;
 * 
 *      Accessor; returns a const reference to private attribute
 *                title.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    const std::string& (title)
********************************************************************/





/********************************************************************
 * Music_collection
 *      A music collection; stores an array of Tune objects.
********************************************************************/

/*****************************
** CONSTRUCTOR & DESTRUCTOR **
*****************************/

/********************************************************************
 * Music_collection(void);
 * 
 *      Constructor; Initialize all class attributes
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * Music_collection(int n);
 * 
 *      Constructor; Initialize all class attributes. Makes sure
 *                   that the new object can hold up to n Tune objects.
 * ------------------------------------------------------------------
 *      Paramters: int n //IN - new size for private attribute max.
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * Music_collection(const Music_collection& m);
 * 
 *      Copy Constructor; Does a deep copy of the passed in 
 *                        Music_collection object.
 * ------------------------------------------------------------------
 *      Paramters: const Music_collection& m //IN - object to make
 *                                           //a deep copy out of.
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/********************************************************************
 * ~Music_collection(void);
 * 
 *      Destructor; Frees all the heap allocated memory associated 
 *                  with the object.
 * ------------------------------------------------------------------
 *      Paramters: none
 * ------------------------------------------------------------------
 *      Return:    none
********************************************************************/

/*************
** MUTATORS **
*************/

/********************************************************************
 * bool add_tune(const Tune& t);
 * 
 *      Mutator; If allocated memory permits, will add a copy of the
 *               tune object to the calling object.
 * ------------------------------------------------------------------
 *      Paramters: const Tune& t    //IN - tune to be copied
 * ------------------------------------------------------------------
 *      Return:    boolean denoting success of adding a copy of 
 *                 Tune object
********************************************************************/

/********************************************************************
 * bool set_tune(int index, const Tune& t);
 * 
 *      Mutator; Changes an existing tune to a new tune object
 * ------------------------------------------------------------------
 *      Paramters: const Tune& t    //IN - tune to use as replacement
 * ------------------------------------------------------------------
 *      Return:    boolean denoting success of adding a copy of 
 *                 Tune object
********************************************************************/

/********************************************************************
 * Music_collection& operator=(const Music_collection& m);
 * 
 *      Mutator; Ensures a deep copy is made to the calling object,
 *               and all memory is freed if need be.
 * ------------------------------------------------------------------
 *      Paramters: const Music_collection& m //IN - object to be copied
 * ------------------------------------------------------------------
 *      Return:    A reference to the calling object.
********************************************************************/

/**************
** ACCESSORS **
**************/

/********************************************************************
 *  friend std::ostream& operator<<(std::ostream& out,
 *                                  const Music_collection& m);
 * 
 *      Mutator; Prints all the tunes associated with the object.
 * ------------------------------------------------------------------
 *      Paramters: std::ostream& out    //IN - output stream, where
 *                                      //is directed to.
 *                 const Music_collection& m    //IN - object to be
 *                                              //displayed.
 * ------------------------------------------------------------------
 *      Return:    A reference to the std::ostream.
********************************************************************/