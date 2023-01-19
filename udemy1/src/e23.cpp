/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s22c.cpp
 * Desc : Section 23: Enumeration
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-08
 *
 */

/*******************************************************************************
 * Enumerations (Unscoped, scoped)
 * ===============================
 *
 * - User defined datatypes that model a set of constant integral value
 * - To improve readibility and algorithm correctness
 * - to replace "magic number"
 *
 *
 * Note
 * - switch statements are best used for enumerations.
 * - for 5+ case generally, switch statements are implementes as jump tables which provice equal access time.
 *
 * Examples:
 *  - the days of weel (Mon, Tue, ... Sat)
 *  - Cards on the deck (Heart, Spade, Clubs, Diamonds)
 *  - direction on compass (North, East, West, South)
 *
 * Syntax:
 *   enum-key enum-name : enumerator-type {};
 *
 * enum-key : keyword is 'enum'
 * enum-name:  optional name for enumeraton
 * enumerator-type : optional type, can be omited and compiler will try to deduce it.
 * { }  : enumberator list
 *
 * Example:
 * enum {Red, Green, Blue};               // implicit initialization  ; underlying type: int
 * enum {Red = 1, Green = 2, Blue = 3 };  // Explicit initialization  ; underlying type: int
 * enum {Red = 1, Green, Blue };          // Explicit/Implicit initialization  ; underlying type: int
 * enum {Red, Green, Blue = -32789 };     // Underlying type: long
 * enum : uint8_t {Red, Green, Blue};     // Underlying type: unsigned 8 bit int
 * enum : long long {Red, Green, Blue};   // Underlying type: long long
 *
 * Enumeration name, without name is considered as anonymouns, its doesnt provide type safe.
 *
 * ### Example of anonymouns enum, not type-safe
 * enum {Red, Green, Blue}
 * int my_color;
 * my_color = Green; // valid
 * my_color = 5;     // also valid
 *
 * ### Example of named enum, is type-safe
 * enum Color {Red, Green, Blue}
 * Color my_color;
 * my_color = Green; // valid
 * my_color = 5;     // Not valid
 *
 *******************************************************************************
 * unscoped enumeration
 *******************************************************************************
 * using cin and cout with unscoped enum:
 * --------------------------------------
 *
 * enum State { Engine_Failure = 0, Increment_Weather = 1, Nominal = 2 };  // underlying type: int
 *
 * // Method 1: Reading user inout values to enumerations
 * std::underlying_type_t<State> user_input;                               // type: int
 * std::cin >> user_input;                                                 // useInput = 3
 * State state = State (user_input);         // Problem                    // state = 3
 *
 * // Solution
 * State state;
 * switch(user_input){
 *   case Engine_Failure:    state=State(user_input); break;
 *   case Increment_Weather: state=State(user_input); break;
 *   case Nominal:           state=State(user_input); break;
 *   default:                std::cout << "User input not valid.";
 * }
 *
 * // Method 2: Reading user inout values to enumerations
 * State state;
 * std::cin >> state;  // valid with overloaded extractor operator, see below function
 *
 * std::istream& operator>> (std::istream& is , State& state) {
 *   std::underlying_type_t<State> user_input;                         // type: int
 *   std::cin >> user_input;                                           // useInput = 3
 *   switch(user_input){
 *     case Engine_Failure:    state=State(user_input); break;
 *     case Increment_Weather: state=State(user_input); break;
 *     case Nominal:           state=State(user_input); break;
 *     default:                std::cout << "User input not valid.";
 *   }
 *   return is;
 * }
 *
 * ----------------------------------------------------------------------------
 *
 * // Method 1: Display enumerations variables
 * enum State { Engine_Failure = 0, Increment_Weather = 1, Nominal = 2 };  // underlying type: int
 *
 * // Method 1 - values display and not the names
 * State state = Engine_Failure;
 * std::cout << state;            // Display 0
 *
 * // Method 2 - Display the names of enumerators
 * std::ostream& operator<<(std::ostream& os , State& state) {
 *   switch(state){
 *     case Engine_Failure:    os << "Engine Failure" ; break;
 *     case Increment_Weather: os << "Increment Weather" ; break;
 *     case Nominal:           os << "Nominal" ; break;
 *     default:                os << "Unknown" ;
 *   }
 *   return os;
 * }
 * State state = Engine_Failure;
 * std::cout << state;            // Display names
 *
 *******************************************************************************
 * unscoped enumeration
 * --------------------
 * - Prevents enumerator name clash
 * - not implicitly convertable, need to explicitly cast
 *
 * syntax:
 *  enum class  enum-name : enumerator-type {};
 *  enum struct enum-name : enumerator-type {};
 *
 *******************************************************************************
 */

#include "udemy1.hpp"

#include <iostream>
#include <memory>
#include <vector>

namespace udemy1::e23::ex1
{
enum Directon { North, South, East, West };

// enum Street {Main, North, Elm};  // error cannot be use North again

} // namespace udemy1::e23::ex1

namespace udemy1::e23::ex2
{
// Unscoped enumeration representing Directions
enum Directon { North, South, East, West };

// This function expects a Direction paramater
// and returns its string representation
std::string direction_to_string(Directon direction)
{
    std::string result;
    switch (direction) {
    case North: result = "North"; break;
    case West: result = "West"; break;
    case South: result = "South"; break;
    case East: result = "East"; break;
    default: result = "Unknown Direction";
    }
    return result;
}

void run_compass_direction_test(void)
{
    std::cout << "-- Test 1 ---------------------------------------------------------" << std::endl;
    Directon direction{North};
    std::cout << "Direction " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    std::cout << "\n-- Test 2 ---------------------------------------------------------" << std::endl;
    direction = West;
    std::cout << "Direction " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    // direction = 5 ;  // COmpiler ERROR

    std::cout << "\n-- Test 3 ---------------------------------------------------------" << std::endl;
    direction = Directon(100);
    std::cout << "Direction " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    std::cout << "\n-- Test 4 ---------------------------------------------------------" << std::endl;
    direction = static_cast<Directon>(100);
    std::cout << "Direction " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;
}

} // namespace udemy1::e23::ex2

namespace udemy1::e23::ex3
{
// Unscoped enumeration representing items for a grocery shopping list
enum Grocery_Item { Milk, Bread, Apple, Orange };

// Overloading the stream insertion operator to insert
// the string representation of the provided Grovery_Item
// parameter into the output stream
std::ostream& operator<<(std::ostream& os, Grocery_Item item)
{
    switch (item) {
    case Milk: os << "Milk"; break;
    case Bread: os << "Bread"; break;
    case Apple: os << "Apple"; break;
    case Orange: os << "Orange"; break;
    default: os << "Invalid Item";
    }
    return os;
}

// Returns a boolean depending on whether the Grocery_Item
// paramter is a valid enumerator or not.
bool is_valid_grocery_item(Grocery_Item item)
{
    switch (item) {
    case Milk:
    case Bread:
    case Apple:
    case Orange: return true;
    default: return false;
    }
}

// Given a vector of Grocery_Items, this function displays
// the string representation of each item using the overloaded
// operator<< function.
// This function also keeps track of how many valid and invalid items
// are in the provided vector by using the is_valid_grocery_item function
// written above.
void display_grocery_list(const std::vector<Grocery_Item>& list)
{
    std::cout << "Gropery List" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    int invalid_item_count{0};
    int valid_item_count{0};
    for (Grocery_Item item : list) {
        std::cout << item << std::endl;
        if (is_valid_grocery_item(item))
            ++valid_item_count;
        else
            ++invalid_item_count;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Valid Items: " << valid_item_count << std::endl;
    std::cout << "Invalid Items: " << invalid_item_count << std::endl;
    std::cout << "Total Items : " << valid_item_count + invalid_item_count << std::endl;
}

void run_enum_unscoped_grocery(void)
{
    std::cout << "\n-- Test 5 ---------------------------------------------------------" << std::endl;

    auto shoppingList = std::make_unique<std::vector<Grocery_Item>>();
    (*shoppingList).push_back(Apple);
    (*shoppingList).push_back(Apple);
    (*shoppingList).push_back(Milk);
    (*shoppingList).push_back(Orange);
    (*shoppingList).push_back(Bread);
    // (*shoppingList).push_back(Grapes); // Compiler error

    int Helicopter{10000};                               // casting
    (*shoppingList).push_back(Grocery_Item(Helicopter)); // invalid
    (*shoppingList).push_back(Grocery_Item(0));          // will add Milk
    (*shoppingList).push_back(Grocery_Item(216));        // invalid

    display_grocery_list(*shoppingList);
}

} // namespace udemy1::e23::ex3

namespace udemy1::e23::ex4
{
enum State { Engine_Failure, Inclement_Weather, Nominal, Unknown };

enum Sequence { Abort, Hold, Launch };

// Overloading the stream extraction operator to allow a user
// to enter the state of State enumeration.
// Note the use of underlying_type_t.
std::istream& operator>>(std::istream& is, State& state)
{
    // int user_input;   // Will also work
    std::underlying_type_t<State> user_input;
    is >> user_input;

    switch (user_input) {
    case Engine_Failure:
    case Inclement_Weather:
    case Nominal:
    case Unknown: state = State(user_input); break;
    default: std::cout << "User input is not a valid launch state." << std::endl; state = Unknown;
    }

    return is;
}

// Overloading the stream insertion operator to insert
// the string representation of the provided Sequence
// parameter into the output stream
std::ostream& operator<<(std::ostream& os, const Sequence& sequence)
{
    switch (sequence) {
    case Abort: os << "Abort"; break;
    case Hold: os << "Hold"; break;
    case Launch: os << "Launch"; break;
    default: os << "Invalid";
    }

    return os;
}

// Displays an information message given the sequence parameter.
void initiate(Sequence sequence)
{
    std::cout << "Initiate " << sequence << " sequence!" << std::endl; // Uses overloaded operator<<
}

// Using unscoped enums to control a rocket launch
// Reads input from the user for the State of the rocket launch,
// and then determines wich Sequence to execute.
void run_rocket_launch_test(void)
{

    std::cout << "\n-- Test 6 ---------------------------------------------------------" << std::endl;

    State state;
    std::cout << "Launch state: ";
    std::cin >> state; // users the overloaded operator>>

    switch (state) {
    case Engine_Failure: // Abort if Engine Failure
    case Unknown:        // or Unknown!
        initiate(Abort);
        break;
    case Inclement_Weather: initiate(Hold); break;
    case Nominal: initiate(Launch); break;
    }
}
} // namespace udemy1::e23::ex4

namespace udemy1::e23::ex5
{

// scoped enumeration representing items for a grocery shopping list
enum class Grocery_Item { Milk = 350, Bread = 250, Apple = 132, Orange = 100 };

// Overloading the stream insertion operator to insert
// the string representation of the provided Grovery_Item
// parameter into the output stream
std::ostream& operator<<(std::ostream& os, Grocery_Item item)
{
    switch (item) {
    case Grocery_Item::Milk: os << "Milk"; break;
    case Grocery_Item::Bread: os << "Bread"; break;
    case Grocery_Item::Apple: os << "Apple"; break;
    case Grocery_Item::Orange: os << "Orange"; break;
    default: os << "Invalid Item";
    }
    auto value = std::underlying_type_t<Grocery_Item>(item);
    os << " : " << value;
    return os;
}

// Returns a boolean depending on whether the Grocery_Item
// paramter is a valid enumerator or not.
bool is_valid_grocery_item(Grocery_Item item)
{
    switch (item) {
    case Grocery_Item::Milk:
    case Grocery_Item::Bread:
    case Grocery_Item::Apple:
    case Grocery_Item::Orange: return true;
    default: return false;
    }
}

// Given a vector of Grocery_Items, this function displays
// the string representation of each item using the overloaded
// operator<< function.
// This function also keeps track of how many valid and invalid items
// are in the provided vector by using the is_valid_grocery_item function
// written above.
void display_grocery_list(const std::vector<Grocery_Item>& list)
{
    std::cout << "Gropery List" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    int invalid_item_count{0};
    int valid_item_count{0};
    for (Grocery_Item item : list) {
        std::cout << item << std::endl;
        if (is_valid_grocery_item(item))
            ++valid_item_count;
        else
            ++invalid_item_count;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Valid Items: " << valid_item_count << std::endl;
    std::cout << "Invalid Items: " << invalid_item_count << std::endl;
    std::cout << "Total Items : " << valid_item_count + invalid_item_count << std::endl;
}

void run_enum_scoped_grocery(void)
{
    std::cout << "\n-- Test 5 ---------------------------------------------------------" << std::endl;

    auto shoppingList = std::make_unique<std::vector<Grocery_Item>>();
    (*shoppingList).push_back(Grocery_Item::Apple);
    (*shoppingList).push_back(Grocery_Item::Milk);
    (*shoppingList).push_back(Grocery_Item::Apple);
    (*shoppingList).push_back(Grocery_Item::Orange);
    (*shoppingList).push_back(Grocery_Item::Bread);
    // (*shoppingList).push_back(Grapes); // Compiler error

    int Helicopter{10000};                               // casting
    (*shoppingList).push_back(Grocery_Item(Helicopter)); // invalid
    (*shoppingList).push_back(Grocery_Item(100));        // will add Orange
    (*shoppingList).push_back(Grocery_Item(256));        // invalid

    display_grocery_list(*shoppingList);
}

} // namespace udemy1::e23::ex5

namespace udemy1::e23::ex6
{

class Player
{
    friend std::ostream& operator<<(std::ostream& os, const Player& p);

  public:
    enum class Mode { Attack, Defense, Idle };
    enum class Direction { North, South, East, West };

  private:
    std::string name;
    Mode mode;
    Direction direction;

  public:
    Player(std::string n, Mode m = Mode::Idle, Direction d = Direction::North)
        : name{n}
        , mode{m}
        , direction{d}
    {
    }

    ~Player() = default;

    void set_name(const std::string n)
    {
        name = n;
    }

    std::string get_name() const
    {
        return name;
    }

    Mode get_mode() const
    {
        return mode;
    }

    Direction get_direction() const
    {
        return direction;
    }
};

// A simple function that returns the string representation
// of the Player::Mode paramter passed into it.
std::string get_player_mode(Player::Mode mode)
{
    std::string result;
    switch (mode) {
    case Player::Mode::Defense: result = "Defense"; break;
    case Player::Mode::Attack: result = "Attack"; break;
    case Player::Mode::Idle: result = "Idle"; break;
    }
    return result;
}

// A simple function that returns the string representation
// of the Player::Direction paramter passed into it.
std::string get_player_direction(Player::Direction direction)
{
    std::string result;
    switch (direction) {
    case Player::Direction::East: result = "East"; break;
    case Player::Direction::West: result = "West"; break;
    case Player::Direction::North: result = "North"; break;
    case Player::Direction::South: result = "South"; break;
    }
    return result;
}

// Overloading the output stream insertion operator
// so we can easily put Player objects on the output stream.
std::ostream& operator<<(std::ostream& os, const Player& p)
{
    os << "Player name:      " << p.get_name() << "\nPlayer mode:      " << get_player_mode(p.mode)
       << "\nPlayer direction: " << get_player_direction(p.direction) << std::endl;
    return os;
}

void run_enum_scoped_gameplay(void)
{
    std::cout << "\n-- Test 5 ---------------------------------------------------------" << std::endl;
    Player p1{"Cloud Strife", Player::Mode::Attack, Player::Direction::North};
    Player p2{"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};
    Player p3{"Sephiroth", Player::Mode::Idle, Player::Direction::East};

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
}

} // namespace udemy1::e23::ex6

void udemy1::e23_run(void)
{
    // e23::ex2::run_compass_direction_test();
    // e23::ex3::run_enum_unscoped_grocery();
    // e23::ex4::run_rocket_launch_test();
    // e23::ex5::run_enum_scoped_grocery();
    e23::ex6::run_enum_scoped_gameplay();
}
