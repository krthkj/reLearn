/******************************************************************
 * Section 13 Challenge
 * Movies.hpp
 *
 * Models a collection of Movie as a std::vector
 * implement these methods in Movies.cpp
 *
 ******************************************************************/

#ifndef MOVIES_HPP
#define MOVIES_HPP

#include "movie.hpp"

#include <string>
#include <vector>

namespace udemy1::s13c
{
class Movies
{
  private:
    std::vector<Movie> movieObject;
    // std::vector<Movie*> movieObject;

    // Movie* find_movie(std::string name);

  public:
    bool add_movie(std::string name, std::string rating, int watched); // add a new movie to the list
    bool increment_watched(std::string name);                          // increment watch count for a movie
    void display(void) const;                                          // display the movieObject

    Movies();  // default constructor
    ~Movies(); // destructor
};
} // namespace udemy1::s13c
#endif // MOVIES_HPP
