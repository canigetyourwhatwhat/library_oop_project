// This objects creates Command obejct or indicate an error
// Made  by Daichi Ando
#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H
class Book;

//---------------------------------------------------------------------------
//  Description:
//      This object creates book objects and returns them according to the
//      book type. If the book type is not in the hash table (BookType),
//      errorFound() detects it and reutrns true. 

//  Implementation and assumption:
//      Private variable of BookType points to an each object. As the number 
//      of alphabet is 26, there is 27 avalabilites to the array becasue
//      'A' will be index of 1. 

class BookFactory
{
    public:
        // Constructor 
        BookFactory();
        // Destructor 
        ~BookFactory();
        // Creates a book object
        Book* createBook(char bookType);
        // Returns true if error was found
        bool errorFound(char bookType) const;

    private:
        // Hashing table of book type
        Book* BookType [27];
};

#endif