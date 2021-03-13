// This object creates Command obejct or indicate an error
// Made  by Daichi Ando
#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
class Command;

//---------------------------------------------------------------------------
//  Description:
//      This object creates Command objects and returns them according to
//      the Command type. If the Command type is not in the hash table
//      (CommandType), errorFound() detects it and reutrns true. 

//  Implementation and assumption:
//      As the number of alphabet is 26, there is 27 avalabilites to the 
//      array becasue 'A' will be index of 1. 

class CommandFactory
{
    public:
        // Constructor
        CommandFactory();
        // Destructor 
        ~CommandFactory();
        // Creates a Command object
        Command* createCommand(char commandType);
        // Returns true if error was found
        bool errorFound(char commandType) const;

    private:
        // Hashing table of Command type
        Command* CommandType[27];
};

#endif