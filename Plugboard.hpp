#ifndef ENIGMA_PLUGBOARD_HPP
#define ENIGMA_PLUGBOARD_HPP

#include "ForwardEncodingPart.hpp"

#include <iostream>
#include <map>
using namespace std;

// class for the Plugboard component

class Plugboard : public ForwardEncodingPart
{
    public:
        // Returns the encoded character after passing the plugboard
        // If there is a connection in the map for the given parameter,
        // the method returns the correspondent, otherwise it returns
        // the input
        char encode(char);
        // Define a connection between two letters by adding them into
        // the map. The letters will then be swapped when encoded.
        void addToMap(char, char) noexcept;
    private:
        map<char, char> connections;
};

#endif
