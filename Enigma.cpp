#include "Enigma.hpp" 

Enigma::Enigma(int numberOfRotors)
{
    this->numberOfRotors = numberOfRotors;
}

char Enigma::encode(char input)
{
    char result = input;
    result = plugboard.encode(result);
    if(numberOfRotors > 0) 
    {
        result = rotors[0].encode(result);
    }
    for(int i = 1; i < numberOfRotors; i++)
    {
        int index = to_int(result);
        index -= rotors[i - 1].getOffset();
        if(index < 0)
        {
            index = ALPHA_SIZE + index;
        }
        result = rotors[i].encode(to_char(index));
    }
    result = reflector.encode(result);
    for(int i = numberOfRotors - 1; i >= 1; i--)
    {
        result = rotors[i].encodeBack(result);
        result = to_char((to_int(result) + rotors[i - 1].getOffset()) % ALPHA_SIZE);
    }
    if(numberOfRotors > 0)
    {
        result = rotors[0].encodeBack(result);
    }
    bool rotate_next = true;
    for(int i = 0; i < numberOfRotors && rotate_next;)
    {
        rotors[i].rotate();
        if(rotors[i].getOffset() == 0)
        {
            i++;
        }
        else
        {
            rotate_next = false;
        }
    }
    result = plugboard.encode(result);
    return result;
}

void Enigma::addPlugboard(Plugboard p) noexcept
{
    plugboard = p;
}

void Enigma::addRotor(Rotor rotor) noexcept
{
    rotors.push_back(rotor);
}

void Enigma::operate()
{
    char nextCharacter;
    while(cin >> ws && cin >> nextCharacter)
    {
        if(isupper(nextCharacter))
        {
            cout << encode(nextCharacter);
        }
        else
        {
            throw range_error("Character is not an uppercase letter");
        }
    }
}
