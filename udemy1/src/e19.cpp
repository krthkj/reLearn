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
 */

//#include "s19c_class.hpp"
#include "udemy1.hpp"

#include <iomanip> // for I/O manipulators
#include <iostream>
//#include <memory>

namespace udemy1::e19::iomanip
{

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
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << hello << std::endl;

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

void udemy1::e19_run(void)
{
    // e19::iomanip::run_boolean_test();
    // e19::iomanip::run_integer_test();
    // e19::iomanip::run_float_test();
    e19::iomanip::run_field_test();
}
