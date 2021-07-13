/*****************************************************************************
 * AUTHOR       : Osbaldo Gonzalez Jr.
 * Assignment 1 : Student Records
 * CLASS        : CS 3A
 * SECTION      : 71206
 * DUE DATE     : 6/27/2021
*****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstring>

const int MAXNAME_LENGTH = 21; //Defined as 20 in document, but +1 for null terminating char since using char array
enum CourseNames {ENGLISH = 'E', HISTORY = 'H', MATH = 'M'}; //Since when reading what course a student is a part of its these chars

//STRUCTS
struct Student
{
    char lastname[MAXNAME_LENGTH];
    char firstname[MAXNAME_LENGTH];
    char course;            //'M' for math, 'H' for history, 'E' for English
    int test1;
    int test2;
    int finalExam;
    double testAverage;
};
//EOS

//FUNCTION DECLERATIONS/PROTOTYPES
void ProcessRecordFile(Student **s, int &numOfRecords, const std::string &readFname);
void WriteRecordToFile(Student s[], int numOfRecords, const std::string &writeFname);
void ReadFormatedRecordFile(const std::string &readFname);
void FormatCourseRecord_AndWriteToFile(const Student s[], size_t sizeOfArray, char courseName, std::ofstream &outFile);
void GetStudentRecord(Student &s, std::ifstream &inFile, char delim);
void SortStudentsAccordingTo(Student s[], int sizeOfArray, char courseName);
char GetGrade(double averageGrade //IN - A positive value, min val = 0, no real max value
             );
//EOD/P

//MAIN
int main(void)
{
    std::string readFname;   //IN   - get name of input file to read student records
    std::string writeFname;  //IN   - get name of output file to write grade summary
    std::ifstream checkvalid;//PROC - used to check if the readFname file is a valid file.
    Student *stuArray;       //PROC - a student pointer, heap allocated in ProcessRecordFile() func
    int numOfRecords;        //PROC/IN   - get the number of records from the file associated with readFname

    //INPUT - get input file with records and output file name to write
    do
    {  
        std::cout << "Please enter the name of the input file.\n";
        std::cout << "Filename: "; std::cin >> readFname;
        checkvalid.open(readFname);
    } while (!checkvalid);
    checkvalid.close(); //make sure to close the file

    std::cout << "\n"; //spacer
    do
    {
        std::cout << "Please enter the name of the output file.\n";
        std::cout << "Filename: "; std::cin >> writeFname;
    } while (readFname == writeFname); //file does not have to exist, but want to make sure it is not the same name as input file


    //PROCESSING - get records, process them, shove into structs
    stuArray = NULL; //init;
    ProcessRecordFile(&stuArray, numOfRecords, readFname);
    WriteRecordToFile(stuArray, numOfRecords, writeFname);
    delete [] stuArray; //done with the Student array, all processing is done

    //OUTPUT - display file contents associated with writeFname
    std::cout << "Processing Complete\n";
    std::cout << "\n";
    ReadFormatedRecordFile(writeFname);
}
//EOMAIN

//FUNCTION DEFINITIONS 
void ProcessRecordFile(Student **s, int &numOfRecords, const std::string &readFname)
{
    std::ifstream inFile;   //PROC - read file to get all the record info
    
    inFile.open(readFname);
    inFile >> numOfRecords;
    inFile.ignore(1); //avoid new line character

    *s = new Student[numOfRecords];
    if (*s != NULL)
    {
        for (int i = 0; inFile && i < numOfRecords; i++)
            GetStudentRecord((*s)[i], inFile, ',');
    }
    inFile.close();
}
//EOF

void WriteRecordToFile(Student s[], int numOfRecords, const std::string &writeFname)
{
    std::ofstream outFile; //PROC - used to write all the formated output to file

    outFile.open(writeFname);
    outFile << "Student Grade Summary\n";
    outFile << "---------------------\n";
    outFile << "\n\n"; //spacer

    //SortStudentsAccordingTo(s, numOfRecords, ENGLISH);
    FormatCourseRecord_AndWriteToFile(s, numOfRecords, ENGLISH, outFile);
    //SortStudentsAccordingTo(s, numOfRecords, HISTORY);
    FormatCourseRecord_AndWriteToFile(s, numOfRecords, HISTORY, outFile);
    //SortStudentsAccordingTo(s, numOfRecords, MATH);
    FormatCourseRecord_AndWriteToFile(s, numOfRecords, MATH, outFile);

    outFile.close();
}
//EOF

void SortStudentsAccordingTo(Student s[], int sizeOfArray, char courseName)
{
    Student allStudents[sizeOfArray];   //PROC - Keep track of the students in a specific course;
    Student temp;                       //PROC - Temp values used when switching over
    int     strcompareresult;           //PROC - used to decide what happens with swap
    int numOfStudents_inCourse;         //PROC - How many students there actually are
    int doneSorting;                    //PROC - counter to check if the sorting is done

    numOfStudents_inCourse = 0;
    for (int i = 0; i < sizeOfArray; i++)
    {
        if (s[i].course == courseName)
            allStudents[numOfStudents_inCourse++] = s[i];
    }

    doneSorting = 0;
    for (int i = 0; i < numOfStudents_inCourse - 1; i++)
    {
        strcompareresult = strcmp(allStudents[i].lastname, allStudents[i+1].lastname);
        if (strcompareresult > 0)
        {
            temp = allStudents[i];
            allStudents[i] = allStudents[i+1];
            allStudents[i+1] = temp;
        }
        else if (strcompareresult == 0)
        {
            strcompareresult = strcmp(allStudents[i].firstname, allStudents[i+1].firstname);
            if (strcompareresult > 0)
            {
                temp = allStudents[i];
                allStudents[i] = allStudents[i+1];
                allStudents[i+1] = temp;
            }
            /*Just if you want to add this go ahead... else if (strcompareresult == 0) 
                std::cout << "We have duplicate student names!";*/
            else
                doneSorting += 1;   //I am to lazy, but the idea is if doneSorting == numOfStudents_inCourse, then everything is done
                                    //Of course, I would have to run the loop again, and this is more or less trash ass bubble sort, but whatever.
                                    //I would probably have to make a function outa of this fr.
        }
        else
            doneSorting += 1;

    }

    for (int i = 0, j = 0; i < sizeOfArray && j < numOfStudents_inCourse; i++)
    {
        if (s[i].course == courseName)
            s[i] = allStudents[j++];
    }
}
//EOF

void ReadFormatedRecordFile(const std::string &readFname)
{
    std::ifstream inFile;   //PROC - open up file for reading with name readFname
    std::string line;   //PROC - temp var to hold the contents of one line

    inFile.open(readFname);
    if (!inFile)
    {
        std::cout << readFname << " failed to open!\n";
        return; //return early
    }

    while (inFile)
    {
        std::getline(inFile, line, '\n');
        if (inFile) //ensures I don't print the very last line, due to formating hypergrade, extra '\n'
            std::cout << line << "\n";
    }
}
//EOF

void GetStudentRecord(Student &s, std::ifstream &inFile, char delim)
{
    static const double TEST_WEIGHT = 0.30;
    static const double FINAL_WEIGHT = 0.40;

    std::string temp;   //PROC - to get input using getline
    
    //Get full name
    std::getline(inFile, temp, delim);
    std::strncpy(s.lastname, temp.c_str(), MAXNAME_LENGTH);
    std::getline(inFile, temp, delim);
    std::strncpy(s.firstname, temp.c_str(), MAXNAME_LENGTH);

    //Course Character, 'E', 'M', 'H'
    std::getline(inFile, temp, delim);
    s.course = temp[0];

    //Get Grades
    std::getline(inFile, temp, delim);
    s.test1 = std::stoi(temp); 
    std::getline(inFile, temp, delim);
    s.test2 = std::stoi(temp);
    std::getline(inFile, temp, '\n'); //since last field, don't look for delim char, just look for '\n'
    s.finalExam = std::stoi(temp);

    //Calculate test average
    s.testAverage = ( TEST_WEIGHT*(s.test1 + s.test2)
                    + FINAL_WEIGHT*s.finalExam );
}
//EOF

void FormatCourseRecord_AndWriteToFile(const Student s[], size_t sizeOfArray, char courseName, std::ofstream &outFile)
{
    char format[1025];  //PROC - used with snprintf, way more predictable formating
    int charsprinted;   //PROC - used to get s[i].lastname + ", " num of characters
    int numOfStudents;  //PROC - collect the number of students, calculate class average
    double classTotal;  //PROC - collect all the average grades for each student
    double classAverage;//PROC - classTotal/numOfStudents;
    
    outFile << std::fixed << std::setprecision(2); //set number of points after decimal

    switch (courseName)
    {
        case ENGLISH:
            outFile << "ENGLISH CLASS\n";
            break;
        case HISTORY:
            outFile << "HISTORY CLASS\n";
            break;
        case MATH:
            outFile << "MATH CLASS\n";
            break;
        default:
            outFile << "CLASS NOT FOUND!\n";
    }
    outFile << "\n"; //spacer

    //Header
    std::snprintf(format, 1024, "%-37s%-13s%s", "Student Name", "Test Avg", "Grade\n");
    
    outFile 
    << format
    << "----------------------------------------------------------------\n";

    //Student info print out
    numOfStudents = classTotal = classAverage = 0; //Get ready for execution
    for (size_t i = 0; i < sizeOfArray; i++)
    {
        if (s[i].course == courseName)
        {
            charsprinted = std::snprintf(format, 1024, "%s, %s", s[i].lastname, s[i].firstname);
            outFile << format;
            for (int numblank = 0; numblank < 40 - charsprinted; numblank++)
                outFile << ' ';
            std::snprintf(format, 1024, "%-8.2f%5c\n", s[i].testAverage, GetGrade(s[i].testAverage));
            outFile << format;

            classTotal += s[i].testAverage;
            numOfStudents++;
        }
    }

    //Final Procesing
    if (numOfStudents > 0)
        classAverage = classTotal/numOfStudents;
    else
        outFile << "Hmm, seems that there were no students in the class...\n";

    outFile << "\n"; //spacer
    std::snprintf(format, 1024, "%-40s%-8.2f%5c\n", "Class Average", classAverage, GetGrade(classAverage)); 

    outFile << format
    << "----------------------------------------------------------------\n";
}
//EOF

char GetGrade(double averageGrade)
{
    if (averageGrade >= 100.0) //Just in case student got extra credit
        return 'A';

    switch ((int)(averageGrade/10))
    {
        case 10: case 9:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        default:
            return 'F';
    }
}
//EOF