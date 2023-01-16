/******************************************************************
 * Section 13 Challenge
 * Movie.cpp
 *
 * Models a collection of Movie as a std::vector
 *
 ******************************************************************/
#include "movies.hpp"

#include <iostream>

namespace udemy1::s13c
{

/**
 * @brief add_movie expects the name of the move, rating and watched count
 *
 * It will search the movies vector to see if a movie object already exists
 * with the same name.
 *
 * If it does then return false since the movie already exists
 * Otherwise, create a movie object from the provided information
 * and add that movie object to the movies vector and return true
 */
bool Movies::add_movie(std::string name, std::string rating, int watched)
{

    for (const Movie& movie : movieObject)

        if (movie.getName() == name)
            return false;

    Movie tmp{name, rating, watched};
    movieObject.push_back(tmp);

    // for(auto const i : movieObject)
    //     if(i->getName() == name)
    //         return false;
    // movieObject.push_back(new Movie{name, rating, watched});
    return true;
}

/**
 * @brief increment_watched expects the name of the move to increment the
 * watched count
 *
 * It will search the movies vector to see if a movie object already exists
 * with the same name.
 * If it does then increment that objects watched by 1 and return true.
 *
 * Otherwise, return false since then no movies object with the movie name
 * provided exists to increment
 */
bool Movies::increment_watched(std::string name)
{
    for (Movie& movie : movieObject)
        if (movie.getName() == name) {
            movie.increment_watched();
            return true;
        }

    // for(auto i : movieObject)
    //     if(i->getName() == name) {
    //         i->increment_watched();
    //         return true;
    //     }
    return false;
}

/**
 * @brief display
 *
 * display all the movie objects in the movies vector.
 * for each movie call the movie.display method so the movie
 * object displays itself
 */
void Movies::display(void) const
{
    if (movieObject.empty())
        std::cout << "Sorry, no movies to display" << std::endl << std::endl;
    else {
        std::cout << std::endl << "===================================" << std::endl;
        for (const Movie& i : movieObject)
            i.display();

        // for(auto i : movieObject)
        //     i->display();
        std::cout << "===================================" << std::endl << std::endl;
    }
}

// constructor
Movies::Movies() {}

// destructor
Movies::~Movies()
{
    // for(auto i : movieObject)
    //     if(i != nullptr)
    //         delete i;
}
} // namespace udemy1::s13c
