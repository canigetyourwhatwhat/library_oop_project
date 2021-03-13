// This objects deals with all the interaction.
// Made  by Daichi Ando
#include "Manager.h"
#include "Book.h"
#include "Command.h"
#include "Patron.h"
#include "PatronDB.h"
#include "MainLibrary.h"
using namespace std;


//---------------------------------------------------------------------------
// Constructor 
// As a default, creates two new objects to two pointers
Manager::Manager()
{
    bookDBMS = new MainLibrary;
    patronDBMS = new PatronDB;
}

//---------------------------------------------------------------------------
// Destructor 
// As a default, two those objects will be deleted
Manager::~Manager()
{
    delete bookDBMS;
    bookDBMS = nullptr;
    delete patronDBMS;
    patronDBMS = nullptr;
}

//---------------------------------------------------------------------------
// buildSystem()
// It reads data files and iternal three methods deal with each data file
void Manager::buildSystem(ifstream& patronsFile, 
                          ifstream& booksFile, ifstream& commandsFile)
{
    buildPatronSystem(patronsFile);
    buildBookSystem(booksFile);
    buildCommandSystem(commandsFile);
}

//---------------------------------------------------------------------------
// buildPatronSystem()
// It simply calls a function which reads information of 
//      patron from the data file and sotres in the patronDB. 
void Manager::buildPatronSystem(ifstream& patronsFile)
{
    for(;;)
    {
        patronDBMS->insertPatron(patronsFile);
        if (patronsFile.eof()) break;
    }
}

//---------------------------------------------------------------------------
// buildBookSystem()
// It reads data file to create book objects, then store them into the 
//      MainLibrary object called bookDBMS. 
void Manager::buildBookSystem(ifstream& booksFile)
{
    // Pointer to a book object
    Book* book = nullptr;

    // Holds the book type
    char bookType;

    // In case if we have to skip the whole line
    string str;

    for(;;)
    {
        // Reads the initial of the book type
        booksFile >> bookType;
        if (booksFile.eof()) return;

        if(bookMaker.errorFound(bookType))
        {
            // If the Book type is not registered in the BookFactory
            // object, it returns error message
            cout << "ERROR: " << bookType 
                              << " is not a valid Book type." << endl;
            // Skip the rest of the information
            getline(booksFile, str);
        }
        else
        {
            // Create a book object from a BookFactory
            book = bookMaker.createBook(bookType);

            // Set the inofrmation of the book from the data file
            book->setInfo(booksFile);

            // Insert the book object into the MainLibrary object.
            bookDBMS->insertBook(book);
        }

        // breaks for(;;) if it is the end of the line
        if (booksFile.eof()) break;
    }    
}

//---------------------------------------------------------------------------
// buildCommandSystem()
// It reads data file to create command objects, then execute according to the
//      each object's type. If it is History or Display, it will be deleted 
//      right after it is executed. If it is CheckOut or Return, it will be
//      will be stored in an appropriate patron object with execute(). 
void Manager::buildCommandSystem(ifstream& commandsFile)
{
    // It points to each command object
    Command* command = nullptr;
    for(;;)
    {
        // Holds the command type
        char commandType;

        // In case if we have to skip the whole line
        string str;

        // Reads the initial of the command type
        commandsFile >> commandType;
        if (commandsFile.eof()) return;

        if(commandMaker.errorFound(commandType))
        {
            // If the Command type is not registered in the CommandFactory
            // object, it returns error message
            cout << "ERROR: " << commandType 
                              << " is not a valid command type." << endl;
            // Skip the rest of the information
            getline(commandsFile, str);
        }
        else
        {
            // Create command objects
            command = commandMaker.createCommand(commandType);
            
            // if there is any error during the setInfo(), 
            // the object will be delteted.
            if(command->setInfo(commandsFile, bookDBMS, patronDBMS))
            {
                // If the object is History or Display, it will be deleted
                // becasue it won't be stored.
                if(command->execute())
                {
                    delete command;
                }
            }
            else
            {
                delete command;
            }
        }
        // breaks for(;;) if it is the end of the line
        if (commandsFile.eof()) break;
    }
}