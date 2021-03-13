// This object is a children of Command class. 
// Made  by Daichi Ando
#include "Display.h"
#include "MainLibrary.h"
#include "PatronDB.h"
#include <iostream>

//---------------------------------------------------------------------------
// Constructor 
// As a default, parent of Command.cpp already did needed things.
Display::Display(){}

//---------------------------------------------------------------------------
// Destructor 
// It doesn't delete object since those objects my be used later on
Display::~Display(){}

//---------------------------------------------------------------------------
// create()
// It returns Display object
Command* Display::create() const
{
    return new Display();
}

//---------------------------------------------------------------------------
// print()
// Print out the type of this object
void Display::print() const
{
    cout << "Display" << endl;
}

//---------------------------------------------------------------------------
// execute()
// It accesses the pointing object to display all the book objects
bool Display::execute()
{
    librarian_->displayLibraries();
    // It means this object will be deleted after the execution.
    return true;
}

//---------------------------------------------------------------------------
// setInfo()
// Take command data file and point to two objects to set data.
bool Display::setInfo(ifstream& input, MainLibrary* library, PatronDB* patron)
{
    // Points to the object which holds all the book objects
    librarian_ = library;
    commandType_ = 'D';
    return true;
}