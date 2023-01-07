/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s19c.cpp
 * Desc : Section 18: I/O and Stream
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-06
 *
 */

/*******************************************************************************
 * Streams, files and I/O
 * ======================
 *
 * Header files used
 *  <iostream> - Provides definition for formatted input and output from/to streams
 *  <fstream>  - Provides definition for formatted input and output from/to file streams
 *  <iomanip>  - Provides definition for manipulators used for formatting stream I/O
 *
 *
 * Commong stream classes:
 * - ios: Provided basic support for formatted and unformatted i/o operataion. Base class for most other classes
 * - ifstream: Provides high-level input operations on the file based streams
 * - ofstream: Provides high-level output operations on the file based streams
 * - fstream: Provides high-level I/O operations on the file based streams. Derived from 'ofstream' and 'ifstream'
 * - stringstream: Provides high-level I/O operations on memory based strings. Derived from 'istringstream' and
 *                 'ostringstream'
 *
 * Global Stream objects: (initialized before main executes)
 * - cin: Standard input stream - by default connected to standard input device (keyboard) instance of 'istream'
 * - cout: Standard output stream - by default connected to standard output device (console) instance of 'ostream'
 * - cerr: Standard error stream - by default connected to standard output device (console) instance of 'ostream
 *         (unbuffered)'. Best for error messages
 * - clog: Standard log stream - by default connected to standard output device (console) instance of 'ostream
 *         (unbuffered)'. Best for log messages
 *
 *******************************************************************************
 * Steam Manipulators
 * ------------------
 * - useful for formatting
 * - can be used on input and output stream
 * - time of the effect varies on stream
 * - can be used as member function or manipulators
 *
 *+==============+========================+============================================================================+
 *|  Types       |  Manipulators          |Stream                                                                      |
 *+==============+========================+============================================================================+
 *|Boolean       |boolalpha, noboolalpha  |iostream                                                                    |
 *|              |                        |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *|Integer       |dec                     |iostream     Persistant                                                     |
 *|              |hex                     |iostream                                                                    |
 *|              |oct                     |iostream                                                                    |
 *|              |showbase, noshowbase    |                                                                            |
 *|              |setbase                 |                                                                            |
 *|              |                        |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *|Floating      |fixed                   |             Persistant                                                     |
 *|  point       |scientific              |                                                                            |
 *|              |hexfloat                |                                                                            |
 *|              |defaultfloat            |                                                                            |
 *|              |setprecision            |                                                                            |
 *|              |showpoint, noshowpoint  |                                                                            |
 *|              |                        |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *|Field Width   |setw                    |             Not-persistant                                                 |
 *|Justification |setfill                 |                                                                            |
 *|and fill      |internal                |                                                                            |
 *|              |left                    |                                                                            |
 *|              |right                   |                                                                            |
 *|              |                        |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *|Other         |showpos, noshowpos      |                                                                            |
 *|              |uppercase, nouppoercase |                                                                            |
 *|              |                        |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *|whitespace    |ws                      |                                                                            |
 *|              |ends                    |                                                                            |
 *|              |skipws, noskipws        |                                                                            |
 *|              |                        |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *|Output        |endl                    |                                                                            |
 *| flushing     |flush                   |                                                                            |
 *|              |unitbuf, nounitbug      |                                                                            |
 *|              |flush_emit (C++20)      |                                                                            |
 *|              |emit_on_flush (C++20)   |                                                                            |
 *|              |noemit_on_flush (C++20) |                                                                            |
 *|              |                        |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *|Status        |resetiodflags           |                                                                            |
 *|  flags       |setiosflags             |                                                                            |
 *|              |                        |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *|Time and      |get_money, put_money    |                                                                            |
 *|Money (C++11) |get_time, put_time      |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *|Quoted        |quoted                  |                                                                            |
 *|(C++14)       |                        |                                                                            |
 *+--------------+------------------------+----------------------------------------------------------------------------+
 *******************************************************************************
 * File stream
 * ============
 *
 * Reading from file
 * -----------------
 * fstream and ifstream are commonly used for input files
 * 1. #include <fstream>
 * 2. declare fstream or ifstream object
 * 3. connect it to a file on your file system (open for reading)
 * 4. Read data from file via the stream
 * 5. clost the stream
 *
 * Syntax:
 *   std::fstream in_file {"../myfile.txt", std::iso::in }; // open in read mode
 *   std::fstream in_file {"../myfile.txt", std::iso::in | std::iso::binary }; // open file in read and binary mode
 *
 *   std::ifstream in_file {"../myfile.txt"}; // 'std::iso::in' is set by default
 *   std::ifstream in_file {"../myfile.txt", std::iso::in }; // explicitly mentioning read more
 *   std::ifstream in_file {"../myfile.txt", std::iso::binary }; // open file in read and binary mode
 *
 *   std::ifstream in_file;
 *   std::string file_name;
 *   std::cin >> file_name;
 *   in_file.open(file_name);
 *   in_file.open(file_name, std::ios::binary);
 *
 * Check if file open is success:
 *
 *   if(in_file.is_open()) { .. }
 *   else { ... }
 *
 *   if(in_file) { .. }
 *   else { ... }
 *
 * Closing the file : in_file.close();
 *******************************************************************************
 * Writing to file
 * ---------------
 * fstream and ofstream are commonly used for input files
 * 1. #include <fstream>
 * 2. declare fstream or ofstream object
 * 3. connect it to a file on your file system (open for writing)
 * 4. Write data from file via the stream
 * 5. close the stream
 *
 * Notes:
 * - output files will be created if they dont exist
 * - output files will be overwitten (truncated) by default
 * - can be opened with append mode
 * - can open text and binay mode
 *
 * Syntax:
 *   std::fstream out_file {"../myfile.txt", std::ios::out}; // open in write more, default in text mode
 *   std::fstream out_file {"../myfile.txt", std::ios::out | std::ios::binary};  // writing in binary mode
 *
 *   std::ofstream out_file {"../myfile.txt", std::ios::out};
 *   std::ofstream out_file {"../myfile.txt"}; // std::ios::out is optional, because it default
 *   std::ofstream out_file {"../myfile.txt", std::ios::binary};  // writing in binary mode
 *
 *   std::ofstream out_file {"../myfile.txt", std::ios::trunc};// Truncate contents when opening
 *   std::ofstream out_file {"../myfile.txt", std::ios::app};  // append on each write
 *   std::ofstream out_file {"../myfile.txt", std::ios::ate};  // seek to end of stream when openning
 *
 *******************************************************************************
 * String stream  (stringstream, istringstream and ostringstream)
 * =============
 * fstream and ofstream are commonly used for input files
 * 1. #include <sstream>
 * 2. declare stringstream, istringstream or ostringstream object
 * 3. connect it to std::string
 * 4. Read/Write data from/to string stream usinf formattied I/O
 *
 * Syntax:
 *   std::istringstream iss{};
 *   std::ostringstream oss{};
 */

//#include "s19c_class.hpp"
#include "udemy1.hpp"

#include <fstream> // used for file I/O
#include <iomanip> // for I/O manipulators
#include <iostream>
#include <limits>  // for using limit values
#include <sstream> // for String stream

namespace udemy1::e19::iomanip
{

/**
 * @brief Boolean io-manipulator examples
 */
void run_boolean_test(void)
{

    std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    // set to True/False
    std::cout << std::boolalpha;
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    // Toggle to 0/1
    std::cout << std::noboolalpha;
    std::cout << "noboolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha (10 == 20): " << (10 == 20) << std::endl;

    // set to True/False using setf method
    std::cout.setf(std::ios::boolalpha);
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;

    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "Default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "Default (10 == 20): " << (10 == 20) << std::endl;
}

/**
 * @brief Integer io-manipulator examples
 */
void run_integer_test(void)
{
    int num{255};

    std::cout << "Showing num with in base" << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "\nShowing num with in base along with base value" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "\nShowing num in HEX with uppercase" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;

    // reset
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::uppercase);

    int num1{255};
    int num2{-255};

    std::cout << "\nShowing num without signs" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << "\nShowing num with signs" << std::endl;
    std::cout << std::showpos;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    // reset
    std::cout << std::resetiosflags(std::ios::showpos);

    std::cout << "\nShowing num in custom base" << std::endl;
    std::cout << "Enter a number " << std::endl;
    std::cin >> num;
    std::cout << "number in base 8: " << std::setbase(8) << num << std::endl;
    std::cout << "number in base 10: " << std::setbase(10) << num << std::endl;
    std::cout << "number in base 16: " << std::setbase(16) << num << std::endl;
    std::cout << "number in base 0: " << std::setbase(0) << num << std::endl;
}

/**
 * @brief Floating io-manipulator examples
 */
void run_float_test(void)
{
    double num1{123456789.987654321};
    double num2{1234.5678};
    double num3{1234.0};

    std::cout << "### Default #####################" << std::endl;
    std::cout << num1 << std::endl; // 1.23457e+08 - unable to display with 6 significant digits, it will use scientific
    std::cout << num2 << std::endl; // 1234.57 - will display using 6 significant digits and roundup at the end
    std::cout << num3 << std::endl; // 1234

    std::cout << "\n### Precision(2) ################" << std::endl;
    std::cout << std::setprecision(2); // precision on the left side of the decimal point
    std::cout << num1 << std::endl;    // 1.2e+08
    std::cout << num2 << std::endl;    // 1.2e+03
    std::cout << num3 << std::endl;    // 1.2e+03

    std::cout << "\n### Precision(5) ################" << std::endl;
    std::cout << std::setprecision(5);
    std::cout << num1 << std::endl; // 1.2346e+08
    std::cout << num2 << std::endl; // 1234.6
    std::cout << num3 << std::endl; // 1234

    std::cout << "\n### Precision(9) ################" << std::endl;
    std::cout << std::setprecision(9);
    std::cout << num1 << std::endl; // 123456790
    std::cout << num2 << std::endl; // 1234.5678
    std::cout << num3 << std::endl; // 1234

    std::cout << "\n### Precision(3) and fixed ######" << std::endl;
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << num1 << std::endl; // 123456789.988
    std::cout << num2 << std::endl; // 1234.568
    std::cout << num3 << std::endl; // 1234.000

    std::cout << "\n### Precision(3) and scientific ###" << std::endl;
    std::cout << std::setprecision(3) << std::scientific;
    std::cout << num1 << std::endl; // 1.235e+08
    std::cout << num2 << std::endl; // 1.235e+03
    std::cout << num3 << std::endl; // 1.234e+03

    std::cout << "\n### Precision(3) and scientific and uppoercase ###" << std::endl;
    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << num1 << std::endl; // 1.235E+08
    std::cout << num2 << std::endl; // 1.235E+03
    std::cout << num3 << std::endl; // 1.234E+03

    std::cout << "\n### Precision(3) and fixed and shopos ###" << std::endl;
    std::cout << std::setprecision(3) << std::fixed << std::showpos;
    std::cout << num1 << std::endl; // +123456789.988
    std::cout << num2 << std::endl; // +1234.568
    std::cout << num3 << std::endl; // +1234.000

    // reset back to default
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos);

    std::cout << "\n### Precision(10) and showpoint ######" << std::endl;
    std::cout << std::setprecision(10) << std::showpoint;
    std::cout << num1 << std::endl; // 123456790.0
    std::cout << num2 << std::endl; // 1234.567800
    std::cout << num3 << std::endl; // 1234.000000

    // reset back to default
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::setprecision(6);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::showpoint);

    std::cout << "\n### Default #####################" << std::endl;
    std::cout << num1 << std::endl; // 1.23457e+08
    std::cout << num2 << std::endl; // 1234.57
    std::cout << num3 << std::endl; // 1234
}

void ruler(void)
{
    std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
}

/**
 * @brief text related io-manipulator examples
 */
void run_field_test(void)
{
    int num1{1234};
    double num2{1234.5678};
    std::string hello{"Hello"};

    std::cout << "-Default-----------------------------------------------------------------" << std::endl;
    ruler();
    std::cout << num1 << num2 << hello << std::endl;

    std::cout << "\n-default one per line ---------------------------------------------------" << std::endl;
    ruler();
    std::cout << num1 << std::endl
              << num2 << std::endl
              << hello << std::endl;

    std::cout << "\n-width 10 for num1 ------------------------------------------------------" << std::endl;
    ruler();
    std::cout << std::setw(10) << num1
              << num2
              << hello << std::endl;

    std::cout << "\n-width 10 for num1 and num2 ---------------------------------------------" << std::endl;
    ruler();
    std::cout << std::setw(10) << num1
              << std::setw(10) << num2
              << hello << std::endl;

    std::cout << "\n-width 10 for num1, numb2 and hello -------------------------------------" << std::endl;
    ruler();
    std::cout << std::setw(10) << num1
              << std::setw(10) << num2
              << std::setw(10) << hello << std::endl;

    std::cout << "\n-width 10 for num1, numb2 and hello. and all are left justified ---------" << std::endl;
    ruler();
    std::cout << std::setw(10) << std::left << num1
              << std::setw(10) << std::left << num2
              << std::setw(10) << std::left << hello << std::endl;

    std::cout << "\n-width 10 for num1, numb2 and hello. Left for all and setfill to dash ---" << std::endl;
    ruler();
    std::cout << std::setfill('-');
    std::cout << std::setw(10) << std::left << num1
              << std::setw(10) << std::left << num2
              << std::setw(10) << std::left << hello << std::endl;

    std::cout << "\n-width 10 for num1, numb2 and hello. Left for all and setfill varies ----" << std::endl;
    ruler();
    std::cout << std::setw(10) << std::left << std::setfill('*') << num1
              << std::setw(10) << std::left << std::setfill('#') << num2
              << std::setw(10) << std::left << std::setfill('-') << hello << std::endl;
}

} // namespace udemy1::e19::iomanip

/**
 * @brief File I/O using fstream
 */
namespace udemy1::e19::fstream
{

void run_read_from_file_1(std::string file_name)
{
    std::cout << file_name << std::endl;
    std::ifstream in_file{file_name};
    if(!in_file) { // check if file is open
        std::cerr << "File open error" << std::endl;
        return; // exit the program
    }

    std::string line{};
    while(!in_file.eof()) {             // while not at the end
                                        // using eof() may not work as expected across OS
        std::getline(in_file, line);    // read the line
        std::cout << line << std::endl; // display the line
    }
    in_file.close(); // close the file
}

void run_read_from_file_2(std::string file_name)
{
    std::ifstream in_file{file_name};
    if(!in_file) { // check if file is open
        std::cerr << "File open error" << std::endl;
        return; // exit the program
    }

    std::string line{};
    while(std::getline(in_file, line))  // read line
        std::cout << line << std::endl; // display the line

    in_file.close(); // close the file
}

// reading in unformatted manner ( one characte at a time )
void run_read_from_file_3(std::string file_name)
{
    std::ifstream in_file{file_name};
    if(!in_file) { // check if file is open
        std::cerr << "File open error" << std::endl;
        return; // exit the program
    }

    char c{};
    while(in_file.get(c)) // read a character
        std::cout << c;   // display the character

    in_file.close(); // close the file
}

void run_read_from_file_4(std::string file_name)
{

    std::ifstream in_file;
    in_file.open(file_name);
    if(!in_file) { // check if file is open
        std::cerr << "File open error" << std::endl;
        return; // exit the program
    }

    std::string word;
    int num;
    double total;

    in_file >> word >> num >> total;
    std::cout << word << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    in_file.close(); // close the file
}

void run_read_from_file_5(std::string file_name)
{
    std::ifstream in_file;
    in_file.open(file_name);
    if(!in_file) { // check if file is open
        std::cerr << "File open error" << std::endl;
        return; // exit the program
    }

    std::string name;
    int num;
    double total;
    while(!in_file.eof()) { // checking for end of file
                            // using eof() may not work as expected across OS
        in_file >> name >> num >> total;
        std::cout << std::setw(10) << std::left << name;
        std::cout << std::setw(10) << num;
        std::cout << std::setw(10) << total << std::endl;
    }
    in_file.close(); // close the file
}

void run_read_from_file_6(std::string file_name)
{
    std::ifstream in_file;
    in_file.open(file_name);
    if(!in_file) { // check if file is open
        std::cerr << "File open error" << std::endl;
        return; // exit the program
    }

    std::string name;
    int num;
    double total;
    while(in_file >> name >> num >> total) { // this is the best practice
        std::cout << std::setw(10) << std::left << name;
        std::cout << std::setw(10) << num;
        std::cout << std::setw(10) << total << std::endl;
    }
    in_file.close(); // close the file
}

// Formatted input..
// will handle new line, eof and etc...
void run_read_poem_1(std::string file_name)
{
    std::fstream in_file;
    in_file.open(file_name);
    if(!in_file) { // check if file is open
        std::cerr << "Prolem opening file" << std::endl;
        return; // exit the program
    }

    std::string line{};
    while(std::getline(in_file, line))
        std::cout << line << std::endl;
    std::cout << std::endl;
    in_file.close(); // close the file
}

// unformatted input..
// no need to worry about eof, new line and other things
// will read exactly as its in the file
void run_read_poem_2(std::string file_name)
{
    std::fstream in_file;
    in_file.open(file_name);
    if(!in_file) { // check if file is open
        std::cerr << "Prolem opening file" << std::endl;
        return; // exit the program
    }

    char c{};
    while(in_file.get(c))
        std::cout << c;
    std::cout << std::endl;
    in_file.close(); // close the file
}

void run_write_to_file_1(std::string file_name)
{
    std::ofstream ofs{file_name}; // overwite to a file
    if(!ofs)
        std::cerr << " Error creating file" << std::endl;
    else {
        std::string line{};
        std::cout << "Enter someing to write to file: ";
        std::getline(std::cin, line);
        ofs << line << std::endl;
        ofs.close();
    }
}

void run_write_to_file_2(std::string file_name)
{
    std::ofstream ofs{file_name, std::ios::app}; // append to file
    if(!ofs)
        std::cerr << " Error creating file" << std::endl;
    else {
        std::string line{};
        std::cout << "Enter someing to write to file: ";
        std::getline(std::cin, line);
        ofs << line << std::endl;
        ofs.close();
    }
}

// formatted file copy
void run_copy_files_1(std::string file_name, std::string target_file_name)
{
    std::ifstream ifs{file_name};
    std::ofstream ofs{target_file_name};

    if(!ifs) {
        std::cerr << " Error opening file" << std::endl;
        return;
    }
    if(!ofs) {
        std::cerr << " Error creating file" << std::endl;
        ifs.close();
        return;
    }

    std::string line{};
    while(std::getline(ifs, line))
        ofs << line << std::endl;
    ifs.close();
    ofs.close();
    std::cout << "File copied." << std::endl;
}

// unformatted file copy
void run_copy_files_2(std::string file_name, std::string target_file_name)
{
    std::ifstream ifs{file_name};
    std::ofstream ofs{target_file_name};

    if(!ifs) {
        std::cerr << " Error opening file" << std::endl;
        return;
    }
    if(!ofs) {
        std::cerr << " Error creating file" << std::endl;
        ifs.close();
        return;
    }

    char c{};
    while(ifs.get(c))
        ofs.put(c);
    ifs.close();
    ofs.close();
    std::cout << "File copied." << std::endl;
}

} // namespace udemy1::e19::fstream

/**
 * @brief String Stream manipulation
 */
namespace udemy1::e19::sstream
{
void run_input_sstream_1(void)
{
    int num{};
    double total{};
    std::string name{};

    std::string info{"Moe 100 1234.56"};
    std::istringstream iss{info};
    iss >> name >> num >> total;

    std::cout << std::setw(10) << std::left << name;
    std::cout << std::setw(5) << num;
    std::cout << std::setw(10) << total << std::endl;
}

void run_ouput_sstream_2(void)
{
    int num{100};
    double total{1234.56};
    std::string name{"Moe"};

    std::ostringstream oss{};
    oss << std::setw(10) << std::left << name;
    oss << std::setw(5) << num;
    oss << std::setw(10) << total << std::endl;

    std::cout << oss.str() << std::endl;
}

void run_data_validation_1(void)
{
    int value{};
    std::string entry{};
    bool done{false};
    do {
        std::cout << "Please enter a integer: ";
        std::cin >> entry;
        std::istringstream iss_validator{entry};
        if(iss_validator >> value)
            done = true;
        else
            std::cout << "Sorry, thats not an integer" << std::endl;
        // discard the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(!done);

    std::cout << "You entered the integer: " << value << std::endl;
}

} // namespace udemy1::e19::sstream

void udemy1::e19_run(void)
{
    // e19::iomanip::run_boolean_test();
    // e19::iomanip::run_integer_test();
    // e19::iomanip::run_float_test();
    // e19::iomanip::run_field_test();

    // e19::fstream::run_read_from_file_1("../../data/sample.txt");
    //  e19::fstream::run_read_from_file_2("../../data/sample.txt");
    //  e19::fstream::run_read_from_file_3("../../data/sample.txt");

    // e19::fstream::run_read_from_file_4("../../data/sample1.txt");
    // e19::fstream::run_read_from_file_4("../../data/sample2.txt");

    // e19::fstream::run_read_from_file_5("../../data/sample3_unix.txt");
    // e19::fstream::run_read_from_file_5("../../data/sample3_dos.txt");
    // e19::fstream::run_read_from_file_5("../../data/sample3_mac.txt");
    // e19::fstream::run_read_from_file_6("../../data/sample3_unix.txt");

    // e19::fstream::run_read_poem_1("../../data/poem.txt");
    // e19::fstream::run_read_poem_2("../../data/poem.txt");

    // e19::fstream::run_write_to_file_1("../../data/sample_write_1.txt");
    // e19::fstream::run_write_to_file_2("../../data/sample_write_2.txt");

    // e19::fstream::run_copy_files_1("../../data/poem.txt", "../../data/poem(copy_1).txt");
    // e19::fstream::run_copy_files_2("../../data/poem.txt", "../../data/poem(copy_2).txt");

    // e19::sstream::run_input_sstream_1();
    // e19::sstream::run_ouput_sstream_2();
    e19::sstream::run_data_validation_1();
}
