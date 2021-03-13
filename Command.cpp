// This object is the parent of four types of commnad.
// Made  by Daichi Ando
#include "Command.h"
#include "MainLibrary.h"
#include "Book.h"

//---------------------------------------------------------------------------
// Constructor 
// As a default, everything is set to meaningless value.
Command::Command()
{
    commandType_ = 'a';
    librarian_ = nullptr;
    patronDB_ = nullptr;
    book_ = nullptr;
}

//---------------------------------------------------------------------------
// Destructor 
// Virtual fuction, so it is empty

Command::~Command(){};