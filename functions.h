#pragma once
#include <vector>
#include "movie.h"

void createJsonFile(const std::vector<Movie>& movies, std::string fileName);

void searchActor(std::string actor, std::string fileName);

