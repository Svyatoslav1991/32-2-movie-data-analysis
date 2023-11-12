#include "functions.h"
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"

void createJsonFile(const std::vector<Movie>& movies, std::string fileName)
{
	nlohmann::json moviesJson;

    for (const auto& movie : movies)
    {
        moviesJson[movie.title] = {
            {"country", movie.country},
            {"releaseDate", movie.releaseDate},
            {"studio", movie.studio},
            {"screenplayAuthor", movie.screenplayAuthor},
            {"director", movie.director},
            {"producer", movie.producer},
            {"characters", movie.vCharacters} };
    }

    std::ofstream file(fileName);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Can't open file " + fileName);
    }

    file << std::setw(4) << moviesJson << std::endl;
    file.close();
}

//-----------------------------------------------------------------------------

void searchActor(std::string actor, std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Can't open file " + fileName);
    }

    nlohmann::json moviesJson;

    file >> moviesJson;
    file.close();

    bool isFind = false;

    for (const auto& movie : moviesJson.items())
    {
        std::vector<std::pair<std::string, std::string>> vCharacters = movie.value()["characters"];
        for (const auto& character : vCharacters)
        {
            if (character.second == actor)
            {
                std::cout << "Actor " << actor << " played " << character.first << " in movie " << movie.key() << "\n";
                isFind = true;
                break;
            }
        }

        if (isFind)
        {
            break;
        }
    }

    if (!isFind)
    {
        std::cout << "Actor " << actor << " not found\n";
    }
}
