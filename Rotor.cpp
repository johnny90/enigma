#include "Rotor.hpp" 

Rotor::Rotor()
{
    offset = 0;
}

char Rotor::encode(char input)
{
    return to_char(mapping[(to_int(input) + offset) % ALPHA_SIZE]);
}

void Rotor::setMapping(vector<int> mapping) noexcept
{
    this->mapping = mapping;
}

char Rotor::encodeBack(char input)
{
    for(int i = 0; i < mapping.size(); i++)
    {
        if(to_char(mapping[(i + offset) % ALPHA_SIZE]) == input) 
        {
            return to_char(i);
        }
    }
}

int Rotor::getOffset() noexcept
{
    return offset;
}

void Rotor::rotate() noexcept
{
    offset = ++offset % ALPHA_SIZE;
}
