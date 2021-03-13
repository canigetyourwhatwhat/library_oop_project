// This objects deals with all the interaction.
// Made  by Daichi Ando
#ifndef MANAGER_H
#define MANAGER_H
#include <fstream>
#include "BookFactory.h"
#include "CommandFactory.h"
class PatronDB;
class MainLibrary;
using namespace std;

//---------------------------------------------------------------------------
//  Description:
//      This object has the method which does all the work for this program.
//      It creates the database of Book and Patron, then also deals with the
//      Command's interaction. 

//  Implementation and assumption:
//      If there is any extention needed, this file is the place to modify.
//      When the Main.cpp called buildSystem(), that funciton calls three 
//      different private methods to deal with three parts. 

class Manager
{
    public:
        // Constructor
        Manager();
        // Destructor
        ~Manager();
        // It takes three data files and execute below three private methods
        void buildSystem(ifstream&, ifstream&, ifstream&);

    private:
        // Garbage object to only create a book object
        BookFactory bookMaker;
        // Garbage object to only create a command object
        CommandFactory commandMaker;
        // This is where all the Book obejcts are sotred
        MainLibrary* bookDBMS;
        // This is where all the Patron obejcts are sotred
        PatronDB* patronDBMS;

        // It reads the patron data file, and stores all objects in patronDBMS
        void buildPatronSystem(ifstream&);
        // It reads the book data file, and stores all objects in bookDBMS
        void buildBookSystem(ifstream&);
        // It reads the command data file, and deals with those objects
        void buildCommandSystem(ifstream&);
};


#endif