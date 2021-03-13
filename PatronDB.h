// This objects is a database for Patron objects.
// Made  by Daichi Ando
#ifndef PatronDB_H
#define PatronDB_H
#include <fstream>
class Patron;
using namespace std;

//---------------------------------------------------------------------------
//  Description:
//      It simply inserts, retireves and displays Patron objects.

//  Implementation and assumption:
//      It is using simple hashing table by referencing Patron't id number.
//      This object can hold total of 10000 objects but able to actually 
//      insert between 1000 to 9999.

class PatronDB
{
    public:
        // Constructor
        PatronDB();
        // Destructor
        ~PatronDB();
        // It inserts the patron from the patron data file
        void insertPatron(ifstream&);
        // It retrieves patron object by referencing Patron's id number
        Patron* retrievePatron(const int id) const;
        // It displays the transaction of the patron object
        void showHistory(int) const;

    private:
        // It hashing table of Patron objects
        Patron* Database [10000];
};

#endif