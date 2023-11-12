#include <iostream>
#include "movie.h"
#include "functions.h"



int main()
{
	std::cout << "\t\tTASK 32.2 MOVIE DATA ANALYSIS\n\n";

    
    try
    {
        std::vector<Movie> movies = {
        {"Harry Potter and the Philosopher's Stone", "UK", "2001-11-10", "Warner Bros.", "J.K. Rowling", "Chris Columbus", "David Heyman",
         {{"Harry Potter", "Daniel Radcliffe"}, {"Hermione Granger", "Emma Watson"}, {"Ron Weasley", "Rupert Grint"}}},
        {"Star Wars", "USA", "1977-05-25", "Lucasfilm", "George Lucas", "George Lucas", "Gary Kurtz",
         {{"Luke Skywalker", "Mark Hamill"}, {"Princess Leia", "Carrie Fisher"}, {"Han Solo", "Harrison Ford"}}},
        {"Lord of the Rings", "USA", "2001-12-19", "New Line Cinema", "J.R.R. Tolkien", "Peter Jackson", "Peter Jackson",
         {{"Frodo Baggins", "Elijah Wood"}, {"Aragorn", "Viggo Mortensen"}, {"Gandalf", "Ian McKellen"}}},
        {"Matrix", "USA", "1999-03-31", "Warner Bros.", "Lana and Lilly Wachowski", "Lana and Lilly Wachowski", "Joel Silver",
         {{"Neo", "Keanu Reeves"}, {"Trinity", "Carrie-Anne Moss"}, {"Morpheus", "Laurence Fishburne"}}},
        {"Pirates of the Caribbean", "USA", "2003-07-09", "Walt Disney Pictures", "Ted Elliott and Terry Rossio", "Gore Verbinski", "Jerry Bruckheimer",
         {{"Jack Sparrow", "Johnny Depp"}, {"Elizabeth Swann", "Keira Knightley"}, {"Will Turner", "Orlando Bloom"}}}
        };

        std::string filename = "movies.json";

        createJsonFile(movies, filename);

        searchActor("Emma Watson", filename);
        searchActor("Johnny Depp", filename);
        searchActor("Ivan Ivanov", filename);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Something went wrong\n";
        return 1;
    }

	return 0;
}
