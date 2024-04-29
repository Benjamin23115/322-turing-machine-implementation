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
            cout << "Error: Invalid tape alphabet character: '" << token << "'.";
            cout << " Tape alphabet characters must be a single character." << endl;
            break;
        }
        else
        {
            alphabet.push_back(token[0]);
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
    for (char character : alphabet)
    {
        cout << character << " ";
    }
    cout << "}" << endl;
}

bool Tape_Alphabet::is_element(char value) const
{
    for (char character : alphabet)
    {
        if (character == value)
        {
            return true;
        }
    }
    return false;
}
