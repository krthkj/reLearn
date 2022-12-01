/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s10c.cpp
 * Desc : Section 10 Challenge from Udemy course "Beginning C++ Programming
 *        - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-01
 *
 */

#include "udemy1.hpp"
#include <iostream>
#include <string>

namespace udemy1
{

/**
 * @brief generic cipher function
 */
std::string chipher_encode_string(std::string& src, std::string& letters, std::string& key)
{
    std::string dest{};
    for(char c : src) {
        size_t pos = letters.find(c);
        if(pos == std::string::npos)
            dest += c;
        else
            dest += key.at(pos);
    }
    return dest;
}

/**
 * @brief Section 10 Challenge
 * Substitution Cipher
 *
 * A simple and very old method of sending secret messages is the substitution cipher.
 * You might have used this cipher with your friends when you were a kid.
 * Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
 * For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.
 *
 * Write a program thats ask a user to enter a secret message.
 *
 * Encrypt this message using the substitution cipher and display the encrypted message.
 * Then decryped the encrypted message back to the original message.
 *
 * You may use the 2 strings below for  your subsitition.
 * For example, to encrypt you can replace the character at position n in alphabet
 * with the character at position n in key.
 *
 * To decrypt you can replace the character at position n in key
 * with the character at position n in alphabet.
 *
 * Have fun! And make the cipher stronger if you wish!
 * Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
 * forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
 * This could also be improved.
 *
 * Remember, the less code you write the less code you have to test!
 * Reuse existing functionality in libraries and in the std::string class!
 *
 */
void s10c_run(void)
{
    //    std::string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    //    std::string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    std::string alphabet{
        "`1234567890-=~!@#$%^&*()_+qwertyuiop[]QWERTYUIOP{}|asdf ghjkl;'ASDFGHJKL:zxcvbnm,./ZXCVBNM<>?"};
    std::string key{"(1:S,C)%0<BdlAz'2eYou*Z}r>-p!nmw;b~th+/xc]NU4qy396FELK5j?$PV7iJ`f&#=8gv{.kW^@IXOTR[Qa|GHM_Ds "};

    std::string plain_msg{};
    std::cout << "Enter a secret message: ";
    getline(std::cin, plain_msg);

    std::cout << "Encrypting message ..." << std::endl;
    std::string cipher_msg = chipher_encode_string(plain_msg, alphabet, key);
    std::cout << "Encrypted message: " << cipher_msg << std::endl;

    std::cout << "Decrypting message ..." << std::endl;
    plain_msg = chipher_encode_string(cipher_msg, key, alphabet);
    std::cout << "Decrypted message: " << plain_msg << std::endl;

}
} // namespace udemy1
