/******************************************************************
 * Section 13 Challenge
 * Movie.hpp
 *
 * Models a Movie with the following atttributes
 *
 * std::string name - the name of the movie
 * std::string rating - G, PG, PG-13, R
 * int watched - the number of times you've watched the movie
 ******************************************************************/

#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
class Movie
{
  private:
    std::string name;   // the name of the movie
    std::string rating; // the movie rating G,PG, PG-13, R
    int watched;        // the number of times you've watched the movie

  public:
    Movie(std::string name_val, std::string rating_val, int watched_val = 0); // constructor
    ~Movie();                                                                 // destructor
    Movie(const Movie& source);                                               // copy constructor

    void increment_watched(void); // Simply increment the watched attribute by 1
    void display(void) const;     // simply displays the movie information ex.) Big, PG-13, 2

    // Basic getters and setters for private attributes
    // implement these inline and watch your const-correctness
    void setName(const std::string& name)
    {
        this->name = name;
    }
    void setRating(const std::string& rating)
    {
        this->rating = rating;
    }
    void setWatched(const int watched)
    {
        this->watched = watched;
    }
    const std::string& getName() const
    {
        return name;
    }
    const std::string& getRating() const
    {
        return rating;
    }
    int getWatched() const
    {
        return watched;
    }
};

#endif // MOVIE_HPP
