// This object has an information about patron
// Made  by Daichi Ando
#include "Patron.h"
#include "Command.h"
using namespace std;

//---------------------------------------------------------------------------
// Constructor 
// As a default, passes three meaningless information

Patron::Patron()
{
    ID = 0;
    FirstName = "";
    LastName = "";
}

//---------------------------------------------------------------------------
// Destructor 
// It deletes all the Command objects stroed in the vector

Patron::~Patron()
{
    for (vector<Command*>::iterator it = transaction.begin(); 
                                    it != transaction.end(); ++it)
    {
        delete (*it);
        (*it) = nullptr;
    }
}

//---------------------------------------------------------------------------
// Patron(int, string, string) 
// It simply stores all the parameter's information to this obejct

Patron::Patron(int num, string firstName, string lastName)
{
    ID = num;
    FirstName = firstName;
    LastName = lastName;
}

//---------------------------------------------------------------------------
// Print()
// It simply prints out the information about the patron

void Patron::print() const
{
    cout << ID << " " << FirstName << " " << LastName << endl;
}

//---------------------------------------------------------------------------
// displayHistory()
// It displays the all transaction history of the Patron by 
//      using vector iterator. it also calls print().

void Patron::displayHistory()
{
    print();
    for (vector<Command*>::iterator it = transaction.begin();
                                    it != transaction.end(); ++it)
    {
        cout << "  ";
        (*it)->print();
    }
}

//---------------------------------------------------------------------------
// recordTransaction()
// It simply stores the Command object in the vector called transaction.

void Patron::recordTransaction(Command* command)
{
    transaction.push_back(command);
}