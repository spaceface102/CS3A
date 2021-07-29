#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

/****************************************************************
 * 
 *  Method MainWindow: Class MainWindow
 *  //CONSTRUCTOR
 * --------------------------------------------------------------
 *  Sets up the main window (by default).
 *  Int radio button is set as checked.
 *  The LCD next to the choose copy button is set to 1.
 *  private "current" (CurrentLinkedList_Handler*) is set to the
 *  address of the private "intList" (LinkedList_Wrapper)
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must make a MainWindow object.
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //My Init
    ui->int_RadioButton->setChecked(true); //set default radio button
    ui->currentCopyNum_LCDNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->currentCopyNum_LCDNumber->display(1); //minium value to display

    currentList = &intList;
}

/****************************************************************
 * 
 *  Method MainWindow: Class MainWindow
 *  //Destructor
 * --------------------------------------------------------------
 *  Frees recources tied with MainWindow
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must exit window. Or not catch an exception (causing
 *      program to exit)
 *  POST-CONDITIONS
 *      none.
****************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

//All the radio buttons do is change what
//currentList is pointing to: uses polymorphism
//to do specific task
/****************************************************************
 * 
 *  Method on_int_RadioButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  When user hits the int radio button, currentList is set
 *  to the private intList, the LCD next to the choose copy
 *  button is set to the activeListNumber() of currentList and
 *  the currentList is displayed fully.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the int radio button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_int_RadioButton_clicked()
{
    currentList = &intList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_double_RadioButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  When user hits the double radio button, currentList is set
 *  to the private doubleList, the LCD next to the choose copy
 *  button is set to the activeListNumber() of currentList and
 *  the currentList is displayed fully.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the double radio button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_double_RadioButton_clicked()
{
    currentList = &doubleList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_string_RadioButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  When user hits the  string radio button, currentList is set
 *  to the private  stringList, the LCD next to the choose copy
 *  button is set to the activeListNumber() of currentList and
 *  the currentList is displayed fully.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the string radio button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_string_RadioButton_clicked()
{
    currentList = &stringList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_rational_RadioButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  When user hits the  rational radio button, currentList is set
 *  to the private  rationalList, the LCD next to the choose copy
 *  button is set to the activeListNumber() of currentList and
 *  the currentList is displayed fully.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the rational radio button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_rational_RadioButton_clicked()
{
    currentList = &rationalList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_date_RadioButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  When user hits the  date radio button, currentList is set
 *  to the private  datelList, the LCD next to the choose copy
 *  button is set to the activeListNumber() of currentList and
 *  the currentList is displayed fully.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the date radio button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_date_RadioButton_clicked()
{
    currentList = &dateList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_complex_RadioButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  When user hits the complex radio button, currentList is set
 *  to the private  complexList, the LCD next to the choose copy
 *  button is set to the activeListNumber() of currentList and
 *  the currentList is displayed fully.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the complex radio button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_complex_RadioButton_clicked()
{
    currentList = &complexList;
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_sort_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  currentList is sorted from lowest to highest and then
 *  displayed
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the sort push button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_sort_PushButton_clicked()
{
    currentList->sort();
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_removeDuplicates_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  currentList removes all it's duplicates and displays full
 *  list
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the Remove Duplicates push button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_removeDuplicates_PushButton_clicked()
{
    currentList->removeDuplicates();
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_popFront_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  currentList's head is popped and then linked list is
 *  displayed.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the pop front push button
 *  POST-CONDITIONS
 *      If linkedList has no nodes, error will be sent to
 *      defined std::ostream& of popFront(), by default, 
 *      std::cerr
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_popFront_PushButton_clicked()
{
    std::ostringstream out_error;

    currentList->popFront(out_error);

    //catched an error in popFront function
    if (out_error.str().length())
        ui->listOutput_TextEdit->setText(out_error.str().c_str());
    else //no error
        updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_pushBack_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  currentList gets a new node tacked on to it's end. If input
 *  value from pushBackInput_LineEdit is not valid, will
 *  usually default to a default value depending on the type
 *  of the currentList.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the push back push button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_pushBack_PushButton_clicked()
{
    currentList->pushBack(
        ui->pushBackInput_LineEdit->text().toStdString().c_str()
    );
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_pushFront_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  currentList gets a new node tacked on to it's front. If input
 *  value from pushFrontInput_LineEdit is not valid, will
 *  usually default to a default value depending on the type
 *  of the currentList.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the push back push button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_pushFront_PushButton_clicked()
{
    currentList->pushFront(
        ui->pushFrontInput_LineEdit->text().toStdString().c_str()
    );
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_insertSorted_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  currentList gets a new node sorted accordingly to the
 *  current state of the linked list. If input
 *  value from insertSortedInput_LineEdit is not valid, will
 *  usually default to a default value depending on the type
 *  of the currentList.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Expects list to already be sorted! (hit the sort button)
 *      Must click the insert sorted push button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_insertSorted_PushButton_clicked()
{
    currentList->insertSorted(
        ui->insertSortedInput_LineEdit->text().toStdString().c_str()
    );
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_insert_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  currentList gets a new node inserted wherever the user
 *  wants in the current linked list. If input
 *  value from insertValueInput_LineEdit is not valid, will
 *  usually default to a default value depending on the type
 *  of the currentList.
 *  If input node number = 0, will changed the head of the 
 *  currentList
 *  If input node number >= number of nodes in currentList,
 *  will change the tail of the currentList
 *  Else, will just be inserted any where else in the list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Expects list to already be sorted! (hit the sort button)
 *      Must click the push back push button
 *      The value expressed by insertNodeInput_LineEdit can
 *      be any positive or negative integer, method insert
 *      will take care of that.
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_insert_PushButton_clicked()
{
    currentList->insert(
        ui->insertNodeInput_LineEdit->text().toStdString().c_str(),
        ui->insertValueInput_LineEdit->text().toStdString().c_str()
    );
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_displayPortion_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  Will only display from start to end node number (inclusive).
 *  Note that head node is treated as node number one, and therfore
 *  to display the full list, range is 1 to number of nodes in list.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the display portion push button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_displayPortion_PushButton_clicked()
{
    std::ostringstream out;

    currentList->display(
        out,
        ui->startInputPortionList_LineEdit->text().toStdString().c_str(),
        ui->endInputPortionList_LineEdit->text().toStdString().c_str()
        );

    ui->listOutput_TextEdit->setText(out.str().c_str());
}

/****************************************************************
 * 
 *  Method on_makeCopy_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  Will use makeCopyOfActiveList() implemenation to push back
 *  a copy of the linked list to a new index in the private
 *  vector field of currenList.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the make copy push button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_makeCopy_PushButton_clicked()
{
    currentList->makeCopyOfActiveList();
}

/****************************************************************
 * 
 *  Method on_makeCopy_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  Will change the current active list (from the list of 
 *  avaliable lists defined by currentList). NOTE: will not
 *  change the type of list (no int -> double, thats what the
 *  radio buttons are for) but just change the "current active
 *  linked list".
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the choose copy push button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_chooseCopy_PushButton_clicked()
{

    currentList->setNextListAsActive();
    //+1 since getActiveListNumber returns "index" which
    //starts counting at 0.
    ui->currentCopyNum_LCDNumber->display(
        static_cast<int>(currentList->getActiveListNumber() + 1));

    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method on_displayList_PushButton_clicked: Class MainWindow
 *  //PRIVATE SLOT
 *  //EVENT
 * --------------------------------------------------------------
 *  Will display the current linked list in the gui box.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Must click the display list push button
 *  POST-CONDITIONS
 *      Ready for user to use any of the GUI interface presented
****************************************************************/
void MainWindow::on_displayList_PushButton_clicked()
{
    updateListOutputFull();
}

/****************************************************************
 * 
 *  Method updateListOutFull: Class MainWindow
 *  //HELPER
 * --------------------------------------------------------------
 *  Helper function used to just display the current list
 *  fully into the gui text box.
 * --------------------------------------------------------------
 *  PRE-CONDITIONS
 *      Is not directly called with an event, rather, an event
 *      usually calls this method.
 *  POST-CONDITIONS
 *      Will always display the full "active linked list" defined
 *      by private field currentList.
****************************************************************/
void MainWindow::updateListOutputFull(void)
{
    std::ostringstream out;
    currentList->display(out);
    ui->listOutput_TextEdit->setText(out.str().c_str());
}
