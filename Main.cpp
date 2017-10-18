#include <stdexcept>
#include <iostream>
#include <fstream>

#include "Enigma.hpp"
#include "Rotor.hpp"
#include "Plugboard.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        Enigma* enigma_machine = new Enigma(argc - 2);
        for(int i = 1; i < argc - 1; i++)
        {
            ifstream in(argv[i]);
            vector<int> configuration;
            int letter_index;
            int position = 0;
            while(in >> letter_index)
            {
                configuration.push_back(letter_index);
            }
            Rotor r;
            r.setMapping(configuration);
            enigma_machine->addRotor(r);
        }
        Plugboard p;
        ifstream in(argv[argc - 1]);
        if(in.is_open())
        {
            int x, y; //elements of the next pair
            while(in >> x >> y)
            {
                p.addToMap('A' + x, 'A' + y);
            }
            enigma_machine->addPlugboard(p);
        }
        else
        {
            throw invalid_argument(argv[argc - 1]);
        }
        enigma_machine->operate();
        delete enigma_machine;
    }
    else
    {
        throw invalid_argument("No configuration files provided");
    }
    return 0;
}
