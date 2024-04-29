#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "tape_alphabet.h"

using namespace std;

void Tape_Alphabet::load(ifstream &definition, bool &valid)
{
    valid = false;
    string token;
    definition >> token;
    while (token != "TRANSITION_FUNCTION:")
    {
        if (token.size() != 1)
        {
            cout << "Error: Invalid tape alphabet character: '" << token << "',";
            cout << "Tape alphabet characters must be a single character." << endl;
            break;
        }
        else
        {
            alphabet.push_back(token.at(0));
        }
        definition >> token;
    }
    if (token == "TRANSITION_FUNCTION:")
    {
        valid = true;
    }
}

void Tape_Alphabet::view() const
{
    cout << "Gamma = { ";
    for (unsigned int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i] << " ";
    }
    cout << "}" << endl;
}

bool Tape_Alphabet::is_element(char value) const
{
    for (unsigned int i = 0; i < alphabet.size(); i++)
    {
        if (alphabet[i] == value)
        {
            return true;
        }
    }
    return false;
}
