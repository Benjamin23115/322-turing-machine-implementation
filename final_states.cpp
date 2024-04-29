#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "final_states.h"

using namespace std;

void Final_States::load(ifstream &definition, bool &valid)
{
    valid = true;
    string token;
    while (definition >> token)
    {
        if (is_element(token))
        {
            valid = false;
            cout << "Error: Duplicate final state entry found: " << token << endl;
            return; // Exit immediately upon encountering an error
        }
        names.push_back(token);
    }
}

void Final_States::view() const
{
    cout << "F = { ";
    for (const string &name : names)
    {
        cout << name << " ";
    }
    cout << "}" << endl;
}

int Final_States::size() const
{
    return names.size();
}

string Final_States::element(int index) const
{
    return names.at(index);
}

bool Final_States::is_element(string value) const
{
    for (const string &name : names)
    {
        if (name == value)
        {
            return true;
        }
    }
    return false;
}
