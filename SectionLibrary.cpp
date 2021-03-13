// This object stores one type of book objects.
// Made  by Daichi Ando
#include "SectionLibrary.h"

//---------------------------------------------------------------------------
// Constructor 
// As a default, set the pointer to nullptr

SectionLibrary::SectionLibrary()
{
    root = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
// It calles destructorHelper() and passing root in there.

SectionLibrary::~SectionLibrary()
{
    destructorHelper(root);
}

//---------------------------------------------------------------------------
// destructorHelper()
// It deletes all the nodes in this SectionLibrary object

void SectionLibrary::destructorHelper(Node* current)
{
    if(current == nullptr)
    {
        return; 
    }
    destructorHelper(current->left);
    destructorHelper(current->right);
    delete current->data;
    current->data = nullptr;
    delete current;
    current = nullptr;
}

//---------------------------------------------------------------------------
// insertBook()
// It inserts a book object to this object, not recursively. This code is
//    given by professor Zander.

bool SectionLibrary::insertBook(Book* book)
{
    Node *ptr = new Node;
    ptr->data = book;
    book = nullptr;
    ptr->left = nullptr;
    ptr->right = nullptr;

    if(root == nullptr)
    {
      root = ptr;
      return true;
   }
   else
   {
      Node *current = root;
      bool done = false;
      while(!done)
      {
         // If the there is an identical Node in the tree, returns false
         if(*ptr->data == *current->data)
         {
            cout << "Same book cannot be inserted" << endl;
            delete ptr;
            ptr = nullptr;
            return false;
         }
         if(*ptr->data < *current->data)
         {
            if(current->left == nullptr)
            {
               current->left = ptr;
               return true;
            }
            else
            {
               current = current->left;
            }            
         }
         else
         {
            if(current->right == nullptr)
            {
               current->right = ptr;
               return true;
            }
            else
            {
               current = current->right;
            }
         }
      }
   }
   return true;
}

//---------------------------------------------------------------------------
// retireveBook() 
// It checks whether the book exists and return with pointer referance
//      It is taken from lab2 work. 

bool SectionLibrary::retireveBook(Book* target, Book*& foundObj) const
{
   Node* current = root;
   bool found = false;
   while(!found)
   {
     if(current == nullptr)
      {
         // returns error message if it wasn't found
         cout << "This book doesn't exist in our library" << endl;
         return false;
      }
      else if(*target == *current->data)
      {
         foundObj = current->data;
         return true;         
      }
      else if(*target > *current->data)
      {
         current = current->right;
      }
      else
      {
         current = current->left;
      }
   }
   return false;
}

//---------------------------------------------------------------------------
// displayBooks() 
// It displays all the books in this SectionLibrary object.
//      It is called when Display object called execute().
//      It is inorder.

void SectionLibrary::displayBooks() const
{
   displayHelper(root);
}

//---------------------------------------------------------------------------
// displayHelper() 
// It is a helper of displayBooks()

void SectionLibrary::displayHelper(Node* current) const
{
   if(current == nullptr)
    {
        return; 
    }
    displayHelper(current->left);
    cout << current->data->getAvailability() << "     ";
    current->data->print();
    displayHelper(current->right);
       
}