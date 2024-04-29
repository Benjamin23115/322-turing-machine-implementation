#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "states.h"

using namespace std;

void States::load(ifstream &definition, bool &valid)
{
    valid = false;
    string token;
    definition >> token;
    while (token != "INPUT_ALPHABET:")
    {
        if (is_element(token))
        {
            cout << "Error: Duplicate state name '" << token << "' found." << endl;
            valid = false;
            break;
        }
        else
        {
            names.push_back(token);
        }
        definition >> token;
    }
    valid = !names.empty();
}

void States::view() const
{
    cout << "Q = { ";
    for (const string &state : names)
    {
        cout << state << " ";
    }
    cout << "}" << endl;
}

bool States::is_element(string value) const
{
    for (const string &state : names)
    {
        if (state == value)
        {
            return true;
        }
    }
    return false;
}
