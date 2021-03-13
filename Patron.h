// This object has an information about patron
// Made  by Daichi Ando
#ifndef Patron_H
#define Patron_H
#include <iostream>
#include <vector>
class Command;
using namespace std;

//---------------------------------------------------------------------------
//  Description:
//      This object holds the all necessary information about patron. It also
//      records the transaction and displays all transaction the patron made. 

//  Implementation and assumption:
//      When it is necessary to get specific patron't information, it can be
//      retuireved with its patron id (called ID). This class also uses
//      vector to store all the transaction history.

class Patron
{
    public: 
        // Constructor 
        Patron();
        // Constructor with setting all information
        Patron(int num, string firstName, string lastName);
        // Destructor 
        ~Patron();
        
        // Print the information about patron
        void print() const;
        // Display all the information of transaction history
        void displayHistory();
        // Record the Command objects (CheckOut or Return)
        void recordTransaction(Command*);

    private:
        // Patron's last name
        string LastName;
        // Patron's first name
        string FirstName;
        // Patron's id number
        int ID;
        // Patron't transaction history
        vector <Command*> transaction;
};

#endif