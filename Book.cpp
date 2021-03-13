// This object is the parent of three types of books.
// Made  by Daichi Ando
#include "Book.h"

//---------------------------------------------------------------------------
// Constructor 
// As a default, everything is set to meaningless value except availability.

Book::Book()
{
    title_ = "??";
    year_ = 9999;
    book_type_ = 'a';
    availability_ = 5;
    
    // Sicne only hard copy is available now, this variable is fixed
    book_format_ = 'H';
}

//---------------------------------------------------------------------------
// Destructor 
// Virtual fuction, so it is empty

Book::~Book(){}

//---------------------------------------------------------------------------
// getAvailability() 
// Simpley gets the number of availability

int Book::getAvailability() const
{
    return availability_;
}

//---------------------------------------------------------------------------
// returnBook()
// Simpley adds the number of availability. If someone trys to return this
//      book more than original number of this book, then prints out error
//      message.
bool Book::returnBook()
{
    if(availability_==5)
    {
        cout << "ERROR: You cannot return more than original number of copies" << endl;
        return false;
    }
    availability_++;
    return true;
}

//---------------------------------------------------------------------------
// checkOutBook()
// Simpley substracts the number of availability. If there is not enough 
//      amount of book left, then prints out error message.

bool Book::checkOutBook()
{
    if(availability_>0)
    {
        availability_--;
        return true;
    }
    cout << "ERROR: This book doesn't have available copy." << endl;
    return false;    
}