// This object is a children of Book class. 
// Made  by Daichi Ando
#include "Fiction.h"
#include <iomanip>

//---------------------------------------------------------------------------
// Constructor 
// As a default, everything is set to meaningless value.
Fiction::Fiction()
{
    author_ = "";
}

//---------------------------------------------------------------------------
// Destructor 
Fiction::~Fiction(){}

//---------------------------------------------------------------------------
// create()
// It returns Fiction object
Book* Fiction::create() const
{
    return new Fiction();
}

//---------------------------------------------------------------------------
// setInfo()
// Take book data file to read information.
void Fiction::setInfo(ifstream& infile)
{
   infile.get();                     // get (and ignore) blank before author
   getline(infile, author_, ',');     // input author, looks for comma terminator
   
   infile.get();                     // get (and ignore) blank before title
   getline(infile, title_, ',');      // input title
   
   infile >> year_;
}


//---------------------------------------------------------------------------
// setCommandInfo()
// Take command data file to read information.
void Fiction::setCommandInfo(ifstream& infile)
{
    infile.get();                     // get (and ignore) blank before author
   getline(infile, author_, ',');     // input author, looks for comma terminator
   
   infile.get();                     // get (and ignore) blank before title
   getline(infile, title_, ',');      // input title
}

//---------------------------------------------------------------------------
// print()
// Print out all the information about this object 
void Fiction::print() const
{
    cout << left << setw(32) << author_.substr(0, 30) << left << setw(42) << title_.substr(0, 40)
         << right << setw(6) << year_ << endl;
}

//---------------------------------------------------------------------------
// getBookType()
// Returns this book type.
char Fiction::getBookType() const
{
    return 'F';
}

//---------------------------------------------------------------------------
// operator==
// It checks whether they are same Book object
bool Fiction::operator==(const Book &obj) const
{
    // It convers the Book object to Youth object to compare
    const Fiction& book = static_cast<const Fiction&>(obj);
    if(author_ == book.author_ && title_ == book.title_)
    {
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// operator<
// It checks whether lefthand Book object is smaller
bool Fiction::operator<(const Book &obj) const
{
    // It convers the Book object to Youth object to compare
    const Fiction& book = static_cast<const Fiction&>(obj);
    if(author_ < book.author_)
    {
        return true;
    }
    else if(author_ > book.author_)
    {
        return false;
    }
    else
    {
        if(title_ < book.title_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

//---------------------------------------------------------------------------
// operator>
// It checks whether lefthand Book object is bigger
bool Fiction::operator>(const Book &obj) const
{
    // It convers the Book object to Youth object to compare
    const Fiction& book = static_cast<const Fiction&>(obj);
    return !(*this < book);
}
