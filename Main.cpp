// This is where the program reads file, and build the whole system
// Made by Daichi Ando
#include "Manager.h"
#include <fstream>

using namespace std;

int main()
{
    // create an garbage object
    Manager manager;

    // reads three data files
    ifstream booksFile("data4books.txt");
    ifstream patronsFile("data4patrons.txt");
    ifstream commandsFile("data4commands.txt");

    // Build a system
    manager.buildSystem(patronsFile, booksFile, commandsFile);
    return 0;
}