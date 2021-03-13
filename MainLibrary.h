// This object stores multiple SectionLibrary objects = hold all book objects
// Made  by Daichi Ando
#ifndef MAINLIBRARY_H
#define MAINLIBRARY_H
#include "Book.h"
class SectionLibrary;

//---------------------------------------------------------------------------
//  Description:
//      This objects hold multiple SectionLibrary objects that each of them
//      of them holds one type book objects. Therefore, this objects 
//      essentially holds all the books. 

//  Implementation and assumption:
//      Private variable of Database points to an each object. As the number 
//      of alphabet is 26, there is 27 avalabilites to the array becasue
//      'A' will be index of 1. 

class MainLibrary
{
    public:
        // Constructor 
        MainLibrary();
        // Destructor 
        ~MainLibrary();
        // It inserts a book object to an appropriate SectionLibrary object
        bool insertBook(Book*);
        // It checks whether the book exists and return with pointer referance
        bool retrieveBook(Book*, Book*&) const;
        // It displays all the books
        void displayLibraries() const;

    private:
        // Pointer to each type of stored book's objects
        SectionLibrary* Database[27];
};

#endif