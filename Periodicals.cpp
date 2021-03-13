// This object is a children of Book class. 
// Made  by Daichi Ando
#include "Periodicals.h"
#include <iomanip>

//---------------------------------------------------------------------------
// Constructor 
// As a default, everything is set to meaningless value.
Periodicals::Periodicals()
{
    month_ = 0;
}

//---------------------------------------------------------------------------
// Destructor 
Periodicals::~Periodicals(){}

//---------------------------------------------------------------------------
// create()
// It returns Periodicals object
Book* Periodicals::create() const
{
    return new Periodicals();
}

//---------------------------------------------------------------------------
// setInfo()
// Take book data file to read information.
void Periodicals::setInfo(ifstream& infile)
{   
   infile.get();                     // get (and ignore) blank before title
   getline(infile, title_, ',');      // input title
   infile >> month_;
   infile >> year_;

}

//---------------------------------------------------------------------------
// setCommandInfo()
// Take command data file to read information.
void Periodicals::setCommandInfo(ifstream& infile)
{   
    infile >> year_;
    infile >> month_;
   infile.get();                     // get (and ignore) blank before title
   getline(infile, title_, ',');      // input title
}

//---------------------------------------------------------------------------
// print()
// Print out all the information about this object
void Periodicals::print() const
{
    cout << " " << left << setw(2) << year_ << "  " << month_ << "      "
         << left << setw(42) << title_.substr(0, 40) << endl;
}

//---------------------------------------------------------------------------
// getBookType()
// Returns this book type.
char Periodicals::getBookType() const
{
    return 'P';
}

//---------------------------------------------------------------------------
// operator==
// It checks whether they are same Book object
bool Periodicals::operator==(const Book &obj) const
{
    // It convers the Book object to Youth object to compare
    const Periodicals& book = static_cast<const Periodicals&>(obj);
    if(year_ == book.year_ && month_ == book.month_ && title_ == book.title_)
    {
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// operator<
// It checks whether lefthand Book object is smaller
bool Periodicals::operator<(const Book &obj) const
{
    // It convers the Book object to Youth object to compare
    const Periodicals& book = static_cast<const Periodicals&>(obj);
    if(year_ < book.year_)
    {
        return true;
    }
    else if(year_ > book.year_)
    {
        return false;
    }
    else
    {
        if(month_ < book.month_)
        {
            return true;
        }
        else if(month_ > book.month_)
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
}

//---------------------------------------------------------------------------
// operator>
// It checks whether lefthand Book object is bigger
bool Periodicals::operator>(const Book &obj) const
{
    // It convers the Book object to Youth object to compare
    const Periodicals& book = static_cast<const Periodicals&>(obj);
    return !(*this < book);
}
