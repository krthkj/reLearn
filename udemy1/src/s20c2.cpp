/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s20c2.cpp
 * Desc : Section 20: STL challenge 2
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-17
 *
 */

/**
 * @brief Challenge 20.2
 * Challenge 2 - Music play-list
 * Using std::list
 *
 * In this challenge you will create a menu driven application that
 * will simulate a user playing songs from a playlist of songs.
 *
 * We will use a list to simulate the user selecting the the first song in the playlist and
 * then selecting next and previous to play forward of backwards through the
 * playlist.
 *
 * Please refer to the video demo run.
 *
 * We will also allow users to add new song to the playlist and they
 * will be added prior to the currently playing song.
 * The menu looks as follows:
 *
 * F - Play First Song
 * N - Play Next song
 * P - Play Previous song
 * A - Add and play a new Song at current location
 * L - List the current playlist
 * ========================
 * Enter a selection (Q to quit):
 *
 * And the available playlist is modeled as a std::list<Song>
 * I will provide the Song class. Following are the songs in the playlist.
 * I grabbed these from the pop charts, you can use them or change
 * them to any songs you wish.
 *
 * God's Plan         Drake                      5
 * Never Be The Same  Camila Cabello             5
 * Pray For Me        The Weekend and K. Lamar   4
 * The Middle         Zedd, Maren Morris & Grey  5
 * Wait               Maroone 5                  4
 * Whatever It Takes  Imagine Dragons            3
 *
 * I have provided the starting project.
 * Have fun!
 *
 * Note:
 * If you have trouble reading input, you can clear std::cin and
 * ignore everything in the buffer with:
 *
 * std::cin.clear();
 * std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
 *
 * Make sure you #include <limits> to use it.
 *
 */

#include "udemy1.hpp"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <string>

namespace udemy1::s20c2
{
enum class Player_Menu : int { First, Next, Previous, Add, List, Quit, Invalid };

class Song
{
    friend std::ostream& operator<<(std::ostream& os, const Song& s);
    std::string name;
    std::string artist;
    int rating;

  public:
    Song() = default;
    ~Song() = default;
    Song(std::string name, std::string artist, int rating);
    std::string get_name() const;
    std::string get_artist() const;
    int get_rating() const;
    bool operator<(const Song& rhs) const;
    bool operator==(const Song& rhs) const;
};

Song::Song(std::string name, std::string artist, int rating)
    : name{name}
    , artist{artist}
    , rating{rating}
{
}

std::string Song::get_name() const
{
    return name;
}

std::string Song::get_artist() const
{
    return artist;
}

int Song::get_rating() const
{
    return rating;
}

bool Song::operator<(const Song& rhs) const
{
    return this->name < rhs.name;
}

bool Song::operator==(const Song& rhs) const
{
    return this->name == rhs.name;
}

std::ostream& operator<<(std::ostream& os, const Song& s)
{
    os << std::setw(20) << std::left << s.name;
    os << std::setw(30) << std::left << s.artist;
    os << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

Player_Menu get_selection(void)
{
    char value{};
    std::string entry{};
    bool done{false};
    Player_Menu retVal{Player_Menu::Invalid};
    do {
        std::cin >> entry;
        std::istringstream iss_validator{entry};
        if (iss_validator >> value)
            done = true;
        // discard the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (!done);
    switch (value) {
    case 'F':
    case 'f': retVal = Player_Menu::First; break;
    case 'N':
    case 'n': retVal = Player_Menu::Next; break;
    case 'P':
    case 'p': retVal = Player_Menu::Previous; break;
    case 'A':
    case 'a': retVal = Player_Menu::Add; break;
    case 'Q':
    case 'q': retVal = Player_Menu::Quit; break;
    case 'L':
    case 'l': retVal = Player_Menu::List; break;
    default: retVal = Player_Menu::Invalid; break;
    }
    return retVal;
}

void play_current_song(const Song& song)
{
    std::cout << "Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song)
{
    for (const auto& s : playlist)
        std::cout << s << std::endl;
    std::cout << "Current song: " << std::endl;
    std::cout << current_song << std::endl;
}

int get_song_rating()
{
    int rating{0};
    std::string entry{};
    bool done{false};
    do {
        std::cout << "Enter your rating (1-5): ";
        std::cin >> entry;
        std::istringstream iss_validator{entry};
        if (iss_validator >> rating) {
            if (rating > 0 && rating < 6)
                done = true;
        }
        // discard the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);
    return rating;
}

void handle_menu(std::list<Song>& p, std::list<Song>::iterator& c, Player_Menu sel)
{
    // check for iterator validity
    if (c != p.end())
        c = p.begin();

    switch (sel) {
    case Player_Menu::Add: {
        std::string s_name{};
        std::string s_artist{};
        std::cout << "Enter Song name: ";
        std::getline(std::cin, s_name);
        std::cout << "Enter Song Artist: ";
        std::getline(std::cin, s_artist);
        p.emplace_back(s_name, s_artist, get_song_rating());
    } break;
    case Player_Menu::List: display_playlist(p, *c); break;
    case Player_Menu::First: {
        std::cout << "Playing first song" << std::endl;
        c = p.begin();
        play_current_song(*c);
    } break;
    case Player_Menu::Next: {
        if (++c == p.end()) {
            std::cout << "Wrapping to start of playlist" << std::endl;
            c = p.begin();
        }
        play_current_song(*c);
    } break;
    case Player_Menu::Previous: {
        if (c == p.begin()) {
            std::cout << "Wrapping to end of playlist" << std::endl;
            c = p.end();
        }
        --c;
        play_current_song(*c);
    } break;
    case Player_Menu::Invalid: std::cout << "Invalid selection" << std::endl; break;
    case Player_Menu::Quit: std::cout << "Thanks for listening!" << std::endl; break;
    }
}

void run_music_player(void)
{
    std::list<Song> playlist{{"God's Plan", "Drake", 5},
                             {"Never Be The Same", "Camila Cabello", 5},
                             {"Pray For Me", "The Weekend and K. Lamar", 4},
                             {"The Middle", "Zedd, Maren Morris & Grey", 5},
                             {"Wait", "Maroone 5", 4},
                             {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator current_song = playlist.begin();
    if (current_song != playlist.end())
        display_playlist(playlist, *current_song);
    Player_Menu selection{Player_Menu::List};

    // handle_menu(playlist, current_song, selection);

    do {
        display_menu();
        selection = get_selection();
        std::cout << std::endl;
        handle_menu(playlist, current_song, selection);
    } while (selection != Player_Menu::Quit);
}
} // namespace udemy1::s20c2
