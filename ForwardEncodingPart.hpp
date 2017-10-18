#ifndef ENIGMA_FORWARDENCODINGPART_HPP
#define ENIGMA_FORWARDENCODINGPART_HPP

// abstract class representing a component

class ForwardEncodingPart
{
    public:
        // Returns the character encoded using the rule
        // implemented in the subclass
        virtual char encode(char) = 0;
        // Returns the uppercase character in the alphabet
        // corresponding to the given index
        char to_char(int) noexcept;
        // Returns the index in the uppercase alphabet
        // for the given uppercase character
        int to_int(char) noexcept;
};

// Global constant for the number of letters in the alphabet
extern const int ALPHA_SIZE;

#endif
