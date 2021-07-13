class Distance
{
  private:
    unsigned feet;
    double inches;
  public:
    /*****************************
    ** CONSTRUCTOR & DESTRUCTOR **
    *****************************/
    Distance();
    Distance(unsigned, double);
    Distance(double);

    /**************
    ** ACCESSORS **
    **************/
    double convertToInches() const;
    /*************
    ** CREATORS **
    *************/
    const Distance operator+(const Distance &) const;
    const Distance operator-(const Distance &) const;
    /**************
    ** ACCESSORS **
    **************/
    void display() const;
  private:
    void init();
};
/****************************************************************
 * Distance Class
 *  This class represents a distance number. It        
 *  manages two attributes, feet, and inches.
****************************************************************/

/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
******************************/
/****************************************************************
 *  Distance();
 *  Default constructor; Initialize class attributes, *  feet = 0;
 *  inches = 0;
 *  
 * --------------------------------------------------------------
 *  Parameters: none 
 * --------------------------------------------------------------
 *  Return: none
****************************************************************/
/****************************************************************
 *  Distance(unsigned, double);
 *  Constructor; This constructor takes in two args; first arg 
 *  is set to the private attribute feet, the second arg is set
 *  to the private attribute inches
 * --------------------------------------------------------------
 *  Paramter: unsigned f    //IN - feet values
 *            double inche  //IN - inch values
 * --------------------------------------------------------------
 *  Return: none
****************************************************************/
/****************************************************************
 *  Distance(double);
 *  Constructor; This method takes in one arg, double inch,
 *  and accordingly sets the feet and inches values.
 * --------------------------------------------------------------
 *  Paramter: double inch //IN - inch values
 * --------------------------------------------------------------
 *  Return: none
****************************************************************/

/***************
 ** CREATORS **
 ***************/
/****************************************************************
 *  const Distance operator+(const Distance &) const;
 *  Creator; This method takes two objects and returns the
 *  summartion of the lengths as a new object.
 * --------------------------------------------------------------
 *  Paramter: const Distance &  //IN - Distance object,*  holds all
 *                              //pertinent information
 * --------------------------------------------------------------
 *  Return: A new Distance object with summed length values
****************************************************************/
/****************************************************************
 *  const Distance operator-(const Distance &) const;
 *  Creator; This method takes two objects and returns *  
 *  the summation of the lenghts of the new object
 * --------------------------------------------------------------
 *  Paramter: const Distance &  //IN - Distance object,*  holds all
 *                              //pertinent information
 *
 *
 --------------------------------------------------------------
 *  Return: A new Distance object with summed length  *  values
****************************************************************/

/***************
 ** ACCESSORS **
 ***************/
/****************************************************************
 * void display() const; 
 *  Accessor; This method will print out the formated length
 * --------------------------------------------------------------
 *  Paramter: none
 * --------------------------------------------------------------
 *  Return: none (fromated output to std::cout)
****************************************************************/
/****************************************************************
 *  double convertToInches() const;
 *  Accessor; This method will multiply feet by 12.00   *  
 *  and add inches, which will return a new object
 * --------------------------------------------------------------
 *  Paramter:
 *  None 
 --------------------------------------------------------------
 *  Return: A double return value, holding lenght in inches
****************************************************************/