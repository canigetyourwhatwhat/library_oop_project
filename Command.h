// This object is the parent of four types of commnad.
// Made  by Daichi Ando
#ifndef COMMAND_H
#define COMMAND_H
#include <fstream>
class MainLibrary;
class PatronDB;
class Book;
using namespace std;

//---------------------------------------------------------------------------
//  Description:
//      This is a parent class of four different command types: Display, 
//      History, Return, and CheckOut. Multiple methods are virtual since
//      many of them differes from each book type. 

//  Implementation and assumption:
//      It has three pointers to access all necessary information. 

class Command
{
    public:
        // Constructor 
        Command();
        // Destructor 
        virtual ~Command();

        // Simply creates children objects for factory design pattern
        virtual Command* create() const = 0;
        // Simply prints out 
        virtual void print() const = 0;
        // Do all the necessary information setting
        virtual bool setInfo(ifstream&, MainLibrary*, PatronDB*) = 0;
        // If the object is History or Display, nothing happens. If not either
        //    of them, it decreases the number of availability and recorded to
        //    the patron object's transaciton history.
        virtual bool execute() = 0;

    protected:
        // Stores the type of the command
        char commandType_;
        // Points to the object which holds all the book objects
        MainLibrary* librarian_;
        // points to the object it is returned or checked out
        Book* book_;
        // Points to the object which holds all the patron objects
        PatronDB* patronDB_;
};

#endif
