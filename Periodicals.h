// This object is a children of Book class. 
// Made  by Daichi Ando
#ifndef PERIODICALS_H
#define PERIODICALS_H
#include <fstream>
#include "Book.h"
using namespace std;


//---------------------------------------------------------------------------
//  Description:
//      This object has all the virtual functions created in Book class. It
//      also adds month_ as a private variable. 

//  Implementation and assumption:
//      It overrides all the abstruct functions.

class Periodicals : public Book
{
    public:
        // Constructor
        Periodicals();
        // Desstructor
        virtual ~Periodicals();
        // Take book data file to read information
        virtual void setInfo(ifstream&);
        // Take command data file to read information
        virtual void setCommandInfo(ifstream&);
        // Simply creates an object for factory design pattern
        virtual Book* create() const;
        // Simply prints out 
        virtual void print() const;
        // Takes this object's book type
        char getBookType() const;

        // It checks whether they are same Book object
        virtual bool operator==(const Book &obj) const;
        // It checks whether lefthand Book object is smaller
        virtual bool operator<(const Book &obj) const;
        // It checks whether lefthand Book object is bigger
        virtual bool operator>(const Book &obj) const;

    private:
        // Particular attribute to this class
        int month_;
};

#endif