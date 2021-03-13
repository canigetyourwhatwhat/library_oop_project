// This objects creates Command obejct or indicate an error
// Made  by Daichi Ando
#include "CommandFactory.h"
#include "Command.h"
#include "CheckOut.h"
#include "Return.h"
#include "Display.h"
#include "History.h"

//---------------------------------------------------------------------------
// Constructor 
// As a default, set all the pointers to nullptr

CommandFactory::CommandFactory()
{
    // initially set as nullptr;
    for(int i=0; i<=26; i++)
    {
        CommandType[i] = nullptr;
    }

    // Add the new Book types here as you need. Only three types are set now
    CommandType[3] = new CheckOut();
    CommandType[4] = new Display();
    CommandType[8] = new History();
    CommandType[18] = new Return();

}

//---------------------------------------------------------------------------
// Destructor 
// As a default, delete all the pointing objects 

CommandFactory::~CommandFactory()
{
    for(int i=0; i<=26; i++)
    {
        delete CommandType[i];
        CommandType[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// errorFound() 
// It returns true if the book type is not in the array. 

bool CommandFactory::errorFound(char commandType_) const
{
    // Below if statement converts char to the int to access the array
    if(CommandType[commandType_-64] == nullptr)
    {
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// createBook() 
// It returns an appropriate book object

Command* CommandFactory::createCommand(char commandType_)
{
    return CommandType[commandType_-64]->create();
}