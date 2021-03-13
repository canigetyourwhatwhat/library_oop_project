// This objects creates obejct or indicate an error
// Made  by Daichi Ando
#include "BookFactory.h"
#include "Book.h"
#include "Youth.h"
#include "Periodicals.h"
#include "Fiction.h"

//---------------------------------------------------------------------------
// Constructor 
// As a default, set all the pointers to nullptr

BookFactory::BookFactory()
{
    // initially set as nullptr;
    for(int i=0; i<=26; i++)
    {
        BookType[i] = nullptr;
    }

    // Add the new Book types here as you need. Only three types are set now
    BookType[25] = new Youth();
    BookType[6] = new Fiction();
    BookType[16] = new Periodicals();
}

//---------------------------------------------------------------------------
// Destructor 
// As a default, delete all the pointing objects 

BookFactory::~BookFactory()
{
    for(int i=0; i<=26; i++)
    {
        delete BookType[i];
        BookType[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// errorFound() 
// It returns true if the book type is not in the array. 

bool BookFactory::errorFound(char bookType) const
{
    // Below if statement converts char to the int to access the array
    if(BookType[bookType-64] == nullptr)
    {
        return true;
    }
    return false;
    
}

//---------------------------------------------------------------------------
// createBook() 
// It returns an appropriate book object

Book* BookFactory::createBook(char bookType_)
{
    return BookType[bookType_-64]->create();
}
