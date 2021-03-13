// This object is a children of Command class. 
// Made  by Daichi Ando
#include "Return.h"
#include "MainLibrary.h"
#include "PatronDB.h"
#include "Book.h"
#include "Patron.h"
#include "BookFactory.h"

//---------------------------------------------------------------------------
// Constructor 
// Parent of Command.cpp already did needed things except patronID_
Return::Return()
{
    patronID_ = 0;
}

//---------------------------------------------------------------------------
// Destructor 
// It doesn't delete object since those objects my be used later on
Return::~Return(){}

//---------------------------------------------------------------------------
// create()
// It returns Display object
Command* Return::create() const
{
    return new Return();
}

//---------------------------------------------------------------------------
// print()
// Print out the type of this object
void Return::print() const
{
    cout << "Return   ";
    book_->print();
}

//---------------------------------------------------------------------------
// execute()
// It accesses the pointing object to increases the number of the book's 
//      availability and store this object in the patron's object
bool Return::execute()
{
    // empty pointer 
    Book* foundBook = nullptr;
    
    // store actual Book object in foundBook
    if(!librarian_->retrieveBook(book_, foundBook))
    {
        // Since this object is no valid, delets the pointed object
        delete book_;
        // It means this object will be deleted after the execution.
        return true;
    }

    // To point to the actual book object, deletes the temporary 
    //      created object
    delete book_;

    // Point to actual book obejct
    book_ = foundBook;

    // If someone trys to return this book more than original number of
    //       this book, then prints out error message.
    if(!book_->returnBook())
    {
        // It means this object wont'b be deleted after the execution.
        return true;
    }

    // We already checked this patron id is valid in setInfo()
    Patron* patron = patronDB_->retrievePatron(patronID_);

    // Record the transaction on this patron object
    patron->recordTransaction(this);

    // It means this object wont'b be deleted after the execution.
    return false;
}

bool Return::setInfo(ifstream& infile, MainLibrary* library, PatronDB* patron)
{
    commandType_ = 'R';
    // Points to the object which holds all the book objects
    librarian_ = library;
    // Points to the object which holds all the Patron objects
    patronDB_ = patron;
    // It is used for getLine()
    string str;

    infile.get();
    infile >> patronID_;
    // Checks this patron id is valid or not
    if(!patronDB_->retrievePatron(patronID_))
    {
        // Skip the rest of the words on this line
        getline(infile, str);
        return false;
    }

    BookFactory bookMaker;
    infile.get();
    char bookType;
    infile >> bookType;
    // Check whether the book type is valid or not
    if(bookMaker.errorFound(bookType))
    {
        cout << "ERROR: " << bookType << " is not a valid Book type." << endl; 
        // Skip the rest of the words on this line
        getline(infile, str);
        return false;
    }

    infile.get();
    char bookFormat;
    infile >> bookFormat;
    // Check whether the book format is valid or not
    if(bookFormat != 'H')
    {
        cout << "ERROR: " << bookFormat << " is not a valid Book format type." << endl; 
        // Skip the rest of the words on this line
        getline(infile, str);
        return false;
    }
    
    // Create a book object
    book_ = bookMaker.createBook(bookType);
    // Set information
    book_->setCommandInfo(infile);
    
    return true;
}