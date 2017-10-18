#ifndef ENIGMA_REFLECTOR_HPP
#define ENIGMA_REFLECTOR_HPP

#include "ForwardEncodingPart.hpp"

// class for Reflector component

class Reflector : public ForwardEncodingPart
{
    public:
        // Returns the character encoded by the reflector. The output is
        // 13 positions after the given input in the uppercase alphabet.
        char encode(char input);
};

#endif
