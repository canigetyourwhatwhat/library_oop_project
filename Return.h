// This object is a children of Command class. 
// Made  by Daichi Ando
#ifndef RETURN_H
#define RETURN_H
#include "Command.h"
#include <fstream>
class PatronDB;
class MainLibrary;
using namespace std;

//---------------------------------------------------------------------------
//  Description:
//      This object has all the virtual functions created in Command class. 
//      Verb has been converted to noun as an object. This object will be
//      deleted right after calling execute(). 

//  Implementation and assumption:
//      It overrides all the abstruct functions.

class Return : public Command
{
    public:
        // Constructor 
        Return();
        // Destructor 
        virtual ~Return();

        // Simply creates an object for factory design pattern
        virtual Command* create() const;
        // Simply prints out 
        virtual void print() const;
        // Prints out all the books 
        virtual bool execute();
        // Take command data file and point to two objects to set data.
        virtual bool setInfo(ifstream&, MainLibrary*, PatronDB*);

    private:
        // It records who returned the book
        int patronID_;
};

#endif
