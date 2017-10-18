#include "Plugboard.hpp" 

void Plugboard::addToMap(char x, char y) noexcept
{
    connections[x] = y;
    connections[y] = x;
}

char Plugboard::encode(char input)
{
    if(connections.count(input) != 0) {
        return connections[input];
    }
    return input;
}
