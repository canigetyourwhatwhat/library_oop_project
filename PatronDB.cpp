// This objects is a database for Patron objects.
// Made  by Daichi Ando
#include "PatronDB.h"
#include "Patron.h"

//---------------------------------------------------------------------------
// Constructor 
// As a default, set all the pointers to nullptr

PatronDB::PatronDB()
{
    for(int i=0; i<10000; i++)
    {
       Database[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// Destructor 
// As a default, delete all the pointing objects 

PatronDB::~PatronDB()
{
    for(int i=0; i<10000; i++)
    {
       delete Database[i];
       Database[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// insertPatron() 
// It simply takes information from the patron data file to store Patron 
//    in the array (Database) according to the patron id (ID).

void PatronDB::insertPatron(ifstream& input)
{
   int id;
   string lastName, firstName;
   input >> id;
   if(input.eof()) return;
   
   input >> lastName >> firstName;
   Patron* p = new Patron(id, firstName, lastName);
   // Store in the array
   Database[id] = p;
}

//---------------------------------------------------------------------------
// retrievePatron()
// It retrieves patron object by referencing Patron's id number.

Patron* PatronDB::retrievePatron(const int id) const
{
   // If there is no such a patron
   if(Database[id] == nullptr)
   {
      cout << "ERROR: There is no patron with ID " << id << endl;
      return Database[id];
   }
   // If the patron id number is out of scope
   else if(id < 1000 || id > 9999)
   {
      cout << "ERROR: " << id << " is not a valid patron ID " << id << endl;
      return Database[id];
   }
   // Patron was found 
   else
   {
      return Database[id];
   } 
}

//---------------------------------------------------------------------------
// showHistory()
// It displays the transaction of the patron object


void PatronDB::showHistory(int idNumber) const
{
   // If there is no such a patron
   if(Database[idNumber] == nullptr)
   {
      cout << "ERROR: There is no patron with ID " << idNumber << endl;
   }
   // If the patron id number is out of scope
   else if(idNumber < 1000 || idNumber > 9999)
   {
      cout << "ERROR: " << idNumber << " is not a valid patron ID " << idNumber << endl;
   }
   // Patron is found
   else
   {
      Database[idNumber]->displayHistory();
   }  
}