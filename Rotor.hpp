#ifndef ENIGMA_ROTOR_HPP
#define ENIGMA_ROTOR_HPP

#include "ForwardEncodingPart.hpp"
#include "BackwardsEncodingPart.hpp"

#include <iostream>
#include <vector>
using namespace std;

// class for the Rotor component

class Rotor : public ForwardEncodingPart, public BackwardsEncodingPart
{
    public:
        Rotor();
        char encode(char);
        // Returns the encoding of a character using the inverse
        // function defined in the mapping
        char encodeBack(char);
        // Sets the mapping function for the current rotor
        void setMapping(vector<int>) noexcept;
        // Returns the current position of the rotor
        int getOffset() noexcept;
        // Rotates the mapping for the rotor by 1 place to left
        void rotate() noexcept;
    private:
        vector<int> mapping;
        int offset;
};

#endif
