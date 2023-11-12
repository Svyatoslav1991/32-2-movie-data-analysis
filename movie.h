#pragma once
#include <string>
#include <vector>


struct Movie
{
    std::string title;
    std::string country;
    std::string releaseDate;
    std::string studio;
    std::string screenplayAuthor;
    std::string director;
    std::string producer;
    std::vector <std::pair<std::string, std::string>> vCharacters;
};
