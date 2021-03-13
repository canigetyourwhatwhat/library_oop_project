// This object is a children of Book class. 
// Made  by Daichi Ando
#include "Youth.h"
#include <iomanip>

//---------------------------------------------------------------------------
// Constructor 
// As a default, everything is set to meaningless value.
Youth::Youth()
{
    author_ = "";
}

//---------------------------------------------------------------------------
// Destructor 
Youth::~Youth(){}

//---------------------------------------------------------------------------
// create()
// It returns Youth object
Book* Youth::create() const
{
    return new Youth();
}

//---------------------------------------------------------------------------
// setInfo()
// Take book data file to read information.
void Youth::setInfo(ifstream& infile)
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
void Youth::setCommandInfo(ifstream& infile)
{
    infile.get();                     // get (and ignore) blank before title
   getline(infile, title_, ',');     // input title, looks for comma terminator
   
   infile.get();                     // get (and ignore) blank before author
   getline(infile, author_, ',');      // input author
}

//---------------------------------------------------------------------------
// print()
// Print out all the information about this object 
void Youth::print() const
{
    cout << left << setw(42) << title_.substr(0, 40) << left << setw(32) << author_.substr(0, 30)
         << right << setw(6) << year_ << endl;
}

//---------------------------------------------------------------------------
// getBookType()
// Returns this book type.
char Youth::getBookType() const
{
    return 'Y';
}

//---------------------------------------------------------------------------
// operator==
// It checks whether they are same Book object
bool Youth::operator==(const Book &obj) const
{
    // It convers the Book object to Youth object to compare
    const Youth& book = static_cast<const Youth&>(obj);
    if(author_ == book.author_ && title_ == book.title_)
    {
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// operator<
// It checks whether lefthand Book object is smaller
bool Youth::operator<(const Book &obj) const
{
    // It convers the Book object to Youth object to compare
    const Youth& book = static_cast<const Youth&>(obj);
    if(title_ < book.title_)
    {
        return true;
    }
    else if(title_ > book.title_)
    {
        return false;
    }
    else
    {
        if(author_ < book.author_)
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
bool Youth::operator>(const Book &obj) const
{
    // It convers the Book object to Youth object to compare
    const Youth& book = static_cast<const Youth&>(obj);
    return !(*this < book);
}
