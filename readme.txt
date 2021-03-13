A regional library wishes to automate the process of tracking books. This task is simplified by the fact that it 
has only three types of books — children's books, fiction, periodicals — each sorted differently as described below.

This library wishes to be able to allow patrons to check out books, return books, and to display the contents of 
the library (all three categories) and display a report of a patron's history at any time. All books are 
displayed by category, sorted within the category. Output must be formatted for easy reading with data 
in columns. An example will be provided later.

------------------Description-----------------

–--The library stores:
  Children's books sorted by title, then by author
  Fiction books sorted by author, then by title
  Periodicals sorted by date (year, then month), then by title
  
Assume each item is uniquely identified by its sorting criteria (other information not used when sorting 
or retrieving). This data is minimal. In real life, there would be much more data so do not problem solve 
based on this minimal amount of data per book. Typically, data would be larger and more varied.

A data file is used for the initialization. One line in the file contains information on one item. To 
facilitate processing, the first character of each line indicates this book type: children's books are 
marked with a 'Y' (for youth), 'F' for fiction, and ‘P’ for periodicals. After the type is author (comma 
terminated), then title (comma terminated), and date (year, int type). Periodicals do not have an author 
and that the date will include month and year (both ints). 

For example
        F Pirsig Robert, Zen & the Art of Motorcycle Maint, 1974 P Communications of the ACM, 3 2001
        P Communications of the ACM, 12 1998
        Z Blah blah of the ACM, 9999
        Y Seuss Dr., Yertle the Turtle, 1950
        Y Williams Jay, Danny Dunn & the Homework Machine, 1959

It assumes the format is correct, but codes may be invalid; e.g., the 'Z' code says the line of data is 
not valid. The library owns five copies of each item in the data file except periodicals where it only 
owns one copy. While the data for an item is minimal, do not assume (i.e., design and implement) that is 
the case. Design and implement as though there may be much more data for an item, e.g., 100 pieces of data 
on each book. Everything, including the output, could vary greatly if there was more data. 


---Library patron information will also be found in a second data file, one line per patron. Sample data 
includes a unique 4-digit unique ID number, last name, first name. A blank separates fields. It assumes 
correctly formatted data. The assumption about more information applies also to a patron.
For example:
        1234 Mouse Mickey



–---While normally program is expected to be interactive, to test this program, a third data file is used
to simulate the interaction. It contains an arbitrary sequence of commands, one per line. The first char 
of each line ('C' for check-out, 'R' for return, 'H' to display a patron’s history) indicates the action 
for a patron, or 'D' for library display of the three categories of books, sorted within the category. 
When it is a patron command, after the character key (‘C’, ‘R’, ‘H’), there will be a blank, then the 
patron ID, then the character book type (‘F’, ‘P’, ‘Y’), then the book format (currently only ‘H’ for hard 
copy ), and then the book data (based on the sorting criteria from above). Commas terminate in the same 
place as in the book data file.

For example:
        C 1234
        C 1234
        D
        H 1234
        R 1234
        X 5678
        R 5678
        R 9999 Y H Blah Blah Blah, Blah Blah,
        F H Walker Alice, The Color Purple,
        P H 1996 3 Communications of the ACM,
        F H Walker Alice, The Color Purple, Y Z Yertle the Turtle, Seuss Dr.,
        Z H Yertle the Turtle, Seuss Dr.,
        
The data is correctly formatted, but it handles an invalid action code, an incorrect patron ID (not found), 
invalid format code, and invalid book (not found). For example, the 'X' is an invalid action code; 9999 is 
not a valid patron ID (not a data item from the patron data file); ‘Z’ is an invalid format type; the 'Y' 
is an invalid book code; and there is no youth book with title "Blah Blah" . For bad data, get (read from 
the data file, getline()) and ignore the rest of the line of data.
