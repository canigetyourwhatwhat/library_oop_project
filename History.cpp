// This object is a children of Command class. 
// Made  by Daichi Ando
#include "History.h"
#include "MainLibrary.h"
#include "PatronDB.h"
#include <iostream>

//---------------------------------------------------------------------------
// Constructor 
// As a default, parent of Command.cpp already did needed things except ID.
History::History()
{
    ID = 0;
}

//---------------------------------------------------------------------------
// Destructor 
// It doesn't delete object since those objects my be used later on
History::~History(){}

//---------------------------------------------------------------------------
// create()
// It returns History object
Command* History::create() const
{
    return new History();
}

//---------------------------------------------------------------------------
// print()
// Print out the type of this object
void History::print() const
{
    cout << "History" << endl;
}


//---------------------------------------------------------------------------
// execute()
// It accesses the pointing object to display all the stored Command objects
//      (Return or CheckOut) in the specific patron object. 
bool History::execute()
{
    patronDB_->showHistory(ID);
    // It means this object will be deleted after the execution.
    return true;
}

//---------------------------------------------------------------------------
// setInfo()
// Take command data file and point to two objects to set data.
bool History::setInfo(ifstream& input, MainLibrary* library, PatronDB* patron)
{
    commandType_ = 'H';
    // Points to the object which holds all the patron objects
    patronDB_ = patron;
    input.get();
    input >> ID;
    // Make sure the patron id is valid
    if(!patronDB_->retrievePatron(ID))
    {
        return false;
    }
    return true;
}
