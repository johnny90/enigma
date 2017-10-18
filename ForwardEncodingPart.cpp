#include "ForwardEncodingPart.hpp" 

const int ALPHA_SIZE = 26;

int ForwardEncodingPart::to_int(char input) noexcept
{
    return input - 'A';
}

char ForwardEncodingPart::to_char(int input) noexcept
{
    return 'A' + input;
}
