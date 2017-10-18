#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include "ForwardEncodingPart.hpp"
#include "Plugboard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// class representing the Enigma Machine

class Enigma : public ForwardEncodingPart
{
    public:
        Enigma(int);
        // Returns the encoding of a character based on
        // the configuration of the components
        char encode(char);
        // Add a plugboard configuration for the machine
        void addPlugboard(Plugboard) noexcept;
        // Push a new rotor at the end of the vector
        void addRotor(Rotor) noexcept;
        // Start encoding characters from standard input
        void operate();
    private:
        Plugboard plugboard;
        vector<Rotor> rotors;
        int numberOfRotors;
        Reflector reflector;
};

#endif
