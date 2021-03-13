// This object stores multiple SectionLibrary objects = hold all book objects
// Made  by Daichi Ando
#include "SectionLibrary.h"
#include "MainLibrary.h"
#include "Youth.h"
#include "Fiction.h"
#include "Periodicals.h"

//---------------------------------------------------------------------------
// Constructor 
// As a default, set all the pointers to nullptr

MainLibrary::MainLibrary()
{
    for(int i=0; i<27; i++)
    {
        Database[i] = nullptr;
    }

    // Add the new Book types here as you need. Only three types are set now
    Database[25] = new SectionLibrary(); // Youth
    Database[6] = new SectionLibrary();  // Fiction
    Database[16] = new SectionLibrary(); // Periodicals
}

//---------------------------------------------------------------------------
// Destructor 
// As a default, delete all the pointing objects 

MainLibrary::~MainLibrary()
{
    for(int i=0; i<27; i++)
    {
        delete Database[i];
        Database[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// insertBook() 
// It inserts a book object to an appropriate SectionLibrary object
//      It simply calls insertBook() in SectionLibrary object

bool MainLibrary::insertBook(Book* book)
{
    // Below if statement converts char to the int to access the array
    return Database[book->getBookType()-64]->insertBook(book);
}

//---------------------------------------------------------------------------
// retireveBook() 
// It checks whether the book exists and return with pointer referance
//      It simply calls retireveBook() in SectionLibrary object

bool MainLibrary::retrieveBook(Book* book, Book*& foundObj) const
{   
    // Below if statement converts char to the int to access the array
    return Database[book->getBookType()-64]->retireveBook(book, foundObj);
}

//---------------------------------------------------------------------------
// displayLibraries() 
// It displays all the books from each registered SectionLibrary object. It is
//      is called when Display object called execute().

void MainLibrary::displayLibraries() const
{
    cout << endl;
    // Add additional libraries if needed

    cout << "FICTION BOOKS" << endl;
    cout << "AVAIL AUTHOR                          TITLE";
    cout << "                                       YEAR" << endl;
    Database[6]->displayBooks();
    cout << endl;

    cout << "PERIODICALS" << endl;
    cout << "AVAIL  YEAR  MONTH  TITLE" << endl;
    Database[16]->displayBooks();
    cout << endl;

    cout << "YOUTH BOOKS" << endl;
    cout << "AVAIL TITLE                                     AUTHOR";
    cout << "                            YEAR" << endl;
    Database[25]->displayBooks();
    cout << endl;

}