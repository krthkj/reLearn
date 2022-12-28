/******************************************************************
 * Section 13 Challenge
 * Movie.cpp
 *
 * Models a Movie with the following atttributes
 *
 * std::string name - the name of the movie
 * std::string rating - G, PG, PG-13, R
 * int watched - the number of times you've watched the movie
 ******************************************************************/

#include "movie.hpp"
#include <iostream>

namespace udemy1::s13c
{
// Constructor - expects all 3 movie attributes
Movie::Movie(std::string name_val, std::string rating_val, int watched_val)
    : name{name_val}
    , rating{rating_val}
    , watched{watched_val}
{
}
// Implementation of the destructor
Movie::~Movie()
{
}

// Copy constructor
Movie::Movie(const Movie& src)
    : Movie{src.name, src.rating, src.watched}
{
}

// Simply increment the watched attribute by 1
void Movie::increment_watched(void)
{
    ++this->watched;
}

// simply displays the movie information ex.) Big, PG-13, 2
void Movie::display(void) const
{
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}

} // namespace udemy1::s13c
