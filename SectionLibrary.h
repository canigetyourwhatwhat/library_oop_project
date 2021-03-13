// This object stores one type of book objects.
// Made  by Daichi Ando
#ifndef SECTIONLIBRARY_H
#define SECTIONLIBRARY_H
#include "Book.h"

//---------------------------------------------------------------------------
//  Description:
//      This objects holds mutiple books that are all same book type. It is 
//      mostly derieved from lab2.  

//  Implementation and assumption:
//      Nothing special from Lab2 except the NodeData was replaces to Book
//      object. 

class SectionLibrary
{
    public:
        // Constructor 
        SectionLibrary();
        // Destructor 
        ~SectionLibrary();
        // It inserts a book object to this object
        bool insertBook(Book*);
        // It checks whether the book exists and return with pointer referance
        bool retireveBook(Book*, Book*&) const;
        // It displays all the stored in this object
        void displayBooks() const;
    
    private:
        // Necessary component of a binary search tree
        struct Node
        {
            // left leef
            Node* left;
            // rightt leef
            Node* right;
            // the node's data
            Book* data;
        };
        // root
        Node* root;
        // Helper for destructor
        void destructorHelper(Node* current);
        // Helper for diplayBooks()
        void displayHelper(Node* current) const;
};

#endif