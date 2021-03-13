1. Describe the state of your program, exactly what works and what does not work.

-->Everything works fine and there is one assumption in my program. When the book object is returned, the book can be returned by any patrons. In other words, the book can be returned by a patron who didn't check out the book. Since it is common to ask his or her friend to return a book to a library, I made this program this way. 

----------------------------------------------------------------------------

2. List your hash table(s) that you wrote (not STL) - briefly what they are used for and file they are found in. (Include any factories that are essentially hash tables).

-->I used three hash tables: books, commands and patrons. 
1. For the book object, the initial of the book type is hashed to an integer, then passed to the BookFactory to create a book object. You can see more detail in BookFactory.cpp.
2. For the command object, the initial of the command type is hashed to an integer, then passed to the CommandFactory to create a command object. You can see more detail in CommandFactory.cpp. 
3. I also used hash table on PatronDB.cpp by referencing patron's id number. 

----------------------------------------------------------------------------

3. State which file and which function you read the book data, just high-level function calls, i.e., how/where it gets into your collections.

--> After creating a book object in Manager.cpp, I use setInfo(ifstream&) to retrieve information and set data in the book object. This function is virtual function of Book object, and each derived class of book object reads each input in the file. 

----------------------------------------------------------------------------

4. State which file and which function you read the command data, high-level function calls, how/where you perform the commands.

--> After creating a command object in Manager.cpp, I use setInfo() to retrieve information and set data in the command object. setInfo() takes three things: &ifstream of the command data file, the object which holds all book objects, and the object which holds all patron objects. This function is virtual function of Command object, and each derived class of command object executes setCommandInfo() which works virtually same as setInfo() but takes information from the data file differently. 

----------------------------------------------------------------------------

5. Describe any dirty little secrets (e.g., switch used, or if-else-if, etc.)  If you feel they do not violate the open-closed design principle, explain.

--> My program doesn't have deficits, and I believe it does well on the open-close principle. Since all the book and command types are hashed, it is easy to add new types such as comics. It is also easy to add a new system such as adding music object because all three process is separated (Book, Patron and Command). So it is easily implemented in Manager.cpp where the Manger object holds all the necessary information. 

----------------------------------------------------------------------------

6. Describe anything you are particularly proud of 

--> I finished implementation in 5 days! I wish there was an extra credit for turning it in early. I also didn't violated any rules like open-close principle. 
