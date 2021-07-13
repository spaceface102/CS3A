#include "bboard.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>

/****************************************************************
 * 
 *  Method Constructor: Class BBoard       //DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------
 * This is a constructor method. The new object will use this 
 * constructor if no arguments are used. private member title
 * will be set to "Default Title" and current_user will be set
 * to the default User() constructor.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with no
 *      arguments.
 * 
 *  POST-CONDITIONS
 *      The object still needs to go through the setup and login
 *      methods before the run method is used, in that order.
****************************************************************/
BBoard::BBoard(void)
{
    title = "Default Title";
    current_user = User();
}
//EOF

/****************************************************************
 * 
 *  Method Constructor: Class BBoard       //CONSTRUCTOR
 * --------------------------------------------------------------
 * This is a constructor method. The new object will use this 
 * constructor if one std::string arg is passed. The passed in
 * arg is used to set the BBoard class title. current_user
 * is again set to the default User() constructor.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make an object, or call the constructor with one
 *      argument.
 * 
 *  POST-CONDITIONS
 *      The object still needs to go through the setup and login
 *      methods before the run method is used, in that order.
****************************************************************/
BBoard::BBoard(const std::string& ttl)
{
    title = ttl;
    current_user = User();
}
//EOF

/****************************************************************
 * 
 *  Method setup: Class BBoard       //PUBLIC
 * --------------------------------------------------------------
 * This method does all the necessary setup for the console
 * based Builtin Board. Must pass in a std::string input_file
 * as arg; it is used to open a file with that name, where user
 * names and passwords will be read. 
 * --------------------------------------------------------------
 *  PRE-CONDITIONS.
 *      The passed in argument string should contain the name of
 *      file that exists in the same directory as the executable.
 * 
 *  POST-CONDITIONS
 *      If the file was valid, the private member user_list
 *      will be filled with all the usernames and passwords 
 *      defined by the file. Note, no one has logged in yet,
 *      and the program has simply collected all the necessary
 *      information getting ready to login.
****************************************************************/
void BBoard::setup(const std::string& input_file)
{
    std::ifstream file; //PROC - make new file based on input_file
    
    //import all authorized users from input_file
    file.open(input_file);
    while (file)
        add_user(file);
    file.close();
}
//EOF

/****************************************************************
 * 
 *  Method login: Class BBoard       //PUBLIC
 * --------------------------------------------------------------
 * This method asks a user to provide their username and password
 * in order to continue using the program. If their username and
 * password pair is not found, the method will ask the question
 * again, unless user inputs 'q' or 'Q' as the name parameter.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS.
 *      Programmer should have run the setup() method before
 *      running the login method.
 * 
 *  POST-CONDITIONS
 *      The private current_user attribute will be set to
 *      the user with the correct username password pair.
 *      If the user inputs 'q' or 'Q', the whole program
 *      will end early using the function exit();
****************************************************************/
void BBoard::login(void)
{
    std::string name;   //PROC - name from user
    std::string pass;   //PROC - password from user
    bool foundUser;     //PROC - 

    foundUser = false;  //default value
    std::cout << "Welcome!\n";
    do
    {
        std::cout << "Enter your username (\"Q\" or \"q\" to quit): \n";
        std::cin >> name;
        if (name != "Q" && name != "q")
        {
            std::cout << "Enter your password: \n";
            std::cin >> pass;
            for (unsigned long i = 0; i < user_list.size(); i++)
            {
                if (user_list.at(i).check(name, pass))
                {
                    current_user = user_list.at(i);
                    foundUser = true;
                }
            }
        }
        else
        {
            std::cout << "Bye!\n";
            exit(0);
        }
    } while (!foundUser);

    std::cout << "Welcome back " << name << "!\n\n";
}
//EOF

/****************************************************************
 * 
 *  Method run: Class BBoard       //PUBLIC
 * --------------------------------------------------------------
 * This method runs the builtin board. Menu of options will
 * print until the user quits the board.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS.
 *      Programmer should have run the setup() and login()
 *      methods before had. If current_user is still the
 *      "default user" (defined by the default User()
 *      constructor), the run() method will just simply end early.
 * 
 *  POST-CONDITIONS
 *      The program will end when this method is done. Most
 *      clean up procedures (if any) will be done in this method.
****************************************************************/
void BBoard::run(void)
{
    std::string option; //PROC - choose what to do on the board

    //ensure someone has logged in, not default user
    if (current_user.check("", ""))
        return; //no one has logged in yet
    
    while (true)
    {
        std::cout << "Menu\n";
        std::cout << "  - Display Messages ('D' or 'd')\n";
        std::cout << "  - Add New Message ('N' or 'n')\n";
        std::cout << "  - Quit ('Q' or 'q')\n";
        std::cout << "Choose an action: ";
        std::cin >> option;
        std::cout << "\n";  //spacer

        switch (option[0])
        {
            case 'd': case 'D': //Display Message
                display(std::cout);
                break;
            case 'n': case 'N': //New Message
                add_message(std::cin, std::cout);
                break;
            case 'q': case 'Q': //Quit
                std::cout << "Bye!\n";
                exit(0);
        }
    }
}
//EOF

/****************************************************************
 * 
 *  Method add_user: Class BBoard       //PRIVATE    //OVERLOAD 1
 * --------------------------------------------------------------
 * This method takes in a std::istream reference, used to read
 * all the usernames and passwords in the istream. If either
 * EOF or the word "end" is found in the name section of the
 * file, method will return.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS.
 *      The std::istream passed in must already be opened with
 *      whatever specific file name.
 * 
 *  POST-CONDITIONS
 *      user_list vector will now contain all the usernames and
 *      passwords of each user; we are now ready to use the
 *      login() method
****************************************************************/
void BBoard::add_user(std::istream& in)
{
    std::string name;   //PROC - user name from in file
    std::string pass;   //PROC - user password from file associated with name
    char currentChar;   //PROC - get input character by character

    //get username
    currentChar = in.get();
    while (in && isprint(currentChar) && !isspace(currentChar))
    {
        name += currentChar;
        currentChar = in.get();
    }

    //Check for the end of the file
    if (name == "end")
        return; //if so, just end early and don't add new user
    
    //Gap between user name and password
    while (in && isspace(currentChar))
        currentChar = in.get();
    
    //Get user password
    while (in && isprint(currentChar))
    {
        pass += currentChar;
        currentChar = in.get();
    }

    //ensure go to the next line for next user
    while (in && currentChar != '\n')
        in.get();

    //in case file does not have "end", don't add_user if EOF
    if (in)
        add_user(name, pass);
}
//EOF


/****************************************************************
 * 
 *  Method add_user: Class BBoard       //PRIVATE    //OVERLOAD 2
 * --------------------------------------------------------------
 * This method takes in a name and pass (word) std::string used
 * to make a new User(name, pass) object, ready to pushed into
 * the private user_list vector.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS.
 *      This method can be run standalone; it is not dependent
 *      on any other method.
 *  POST-CONDITIONS
 *      A new user will be pushed into the user_list vector.
 *      The User object's life time is the exact same life
 *      time of the calling BBoard() object.
****************************************************************/
void BBoard::add_user(const std::string& name, const std::string& pass)
{
    user_list.push_back(User(name, pass));
}
//EOF

/****************************************************************
 * 
 *  Method display: Class BBoard       //PRIVATE
 * --------------------------------------------------------------
 * This method displays all the messages in the private
 * message_list in a standard format(according to assignment
 * documentation). The output goes into the passed in 
 * std::ostream reference.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS.
 *      If there are no messages in the message_list vector,
 *      the function will print to console "Nothing to display\n"
 *      and return early, else will print every message.
 *  POST-CONDITIONS
 *      The message_list vector remains intact, no changes are
 *      made to the state of the calling BBoard object.
****************************************************************/
void BBoard::display(std::ostream& out) const
{
    if (message_list.size() == 0)
    {
        out << "Nothing to display\n";
        return; //end early
    }
    for (unsigned long i = 0; i < message_list.size(); i++)
    {
        out << "-----------------------------------------------\n";
        out << "Message #" << i+1 << " : ";
        message_list.at(i).display();
    }
    out << "-----------------------------------------------\n\n";
}
//EOF


/****************************************************************
 * 
 *  Method add_message: Class BBoard       //PRIVATE
 * --------------------------------------------------------------
 * This method takes in two args, a std::istream and std::ostream
 * reference. The ostream is used to write user output to a
 * programer defined stream, and same idea with the istream.
 * The add_message method will ask for the subject and body of
 * the message. The message will then be pushed to the private
 * attribute, message_list, where the author name of the message
 * is that of the current_user attribute.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS.
 *      Input and output will be received and forwarded to the
 *      passed in streams; if the method doesn't seem to work,
 *      it is most likely a problem with the streams.
 *  POST-CONDITIONS
 *      After the message has been added successfully, it is now
 *      ready to be displayed with the BBoard::display() method.
 *      An update: "Message Recorded!" will be forwarded to
 *      ostream right before leaving add_message() method.
****************************************************************/
void BBoard::add_message(std::istream& in, std::ostream& out)
{
    std::string subject;    //PROC - subject of message
    std::string body;       //PROC - body of message

    out << "Enter Subject: ";
    GetText(in, subject);
    out << "Enter Body: ";
    GetText(in, body);
    message_list.push_back(
        Message(current_user.get_username(),
            subject,
            body)
    );
    out << "Message Recorded!\n\n";
}
//EOF

/****************************************************************
 * 
 *  Method add_message: Class BBoard       //PRIVATE
 * --------------------------------------------------------------
 * This method takes in two args, a std::istream and std::string
 * reference. The istream is used to get characters, and string
 * is used to store the characters. Method ensures that one solid
 * line of input, with all characters will be shoved into the
 * passed in string. Stops getting characters when meets up with
 * '\n'
 * --------------------------------------------------------------
 *  PRE-CONDITIONS.
 *      string agr must have a variable attached to it, accesiable
 *      from the calling function
 * 
 *  POST-CONDITIONS
 *      The passed in string will ONLY have one line of input,
 *      no more, no less. All the way down to '\n'
****************************************************************/
void BBoard::GetText(std::istream& in, std::string& str) const
{
    char currChar;  //PROC - current character from istream var, in

    //deal with prev '\n' in the input buffer
    do
        currChar = in.get();
    while (in && currChar == '\n');

    //get actual input
    while (in && currChar != '\n')
    {
        str += currChar;
        currChar = in.get();
    }
}
//EOF