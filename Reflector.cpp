#include "Reflector.hpp"

char Reflector::encode(char input)
{
    int index = to_int(input);
    index = (index + (ALPHA_SIZE / 2)) % ALPHA_SIZE;
    return to_char(index);
}
