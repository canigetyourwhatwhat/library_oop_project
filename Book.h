// This object is the parent of three types of books.
// Made  by Daichi Ando
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------
//  Description:
//      This is a parent class of three different book types: Fiction, Youth,
//      and Periodicals. It has several operators to be properly stored in
//      a binary search tree. Multiple methods are virtual since many of 
//      them differes from each book type. 

//  Implementation and assumption:
//      It stores minimum private variable, but the number of availability
//      is calculated with this Book object but not other children objects.

class Book
{
    public:
        // Constructor
        Book();
        // Destructor 
        virtual ~Book();    

        // to checks whether they are same Book object
        virtual bool operator==(const Book &obj) const = 0;
        // to checks whether lefthand Book object is smaller
        virtual bool operator<(const Book &obj) const = 0;
        // to checks whether lefthand Book object is bigger
        virtual bool operator>(const Book &obj) const = 0;

        // Take book data file to read information
        virtual void setInfo(ifstream&) = 0;
        // Take command data file to read information
        virtual void setCommandInfo(ifstream&) = 0;
        // Simply prints out 
        virtual void print() const = 0;
        // Simply creates children objects for factory design pattern
        virtual Book* create() const = 0;
        // Get the type of book
        virtual char getBookType() const = 0;

        // get the number of avaialbility
        int getAvailability() const;
        // Decrease the number of availability
        bool checkOutBook();
        // Increase the number of availability
        bool returnBook();

    protected:
        // The title of the book
        string title_;
        // The year of the book
        int year_;
        // The type of the book
        char book_type_;
        // The format of the book
        char book_format_;
        // The availability of the book
        int availability_;
};

#endif