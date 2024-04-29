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
            cout << "Error: False Final States Entry" << endl;
        }
        else
        {
            names.push_back(token);
        }
    }
}

void Final_States::view() const
{
    cout << "F = { ";
    for (int i = 0; i < size(); i++)
    {
        cout << names[i] << " ";
    }
    cout << "})" << endl;
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
    for (int i = 0; i < size(); i++)
    {
        if (element(i) == value)
        {
            return true;
        }
    }
    return false;
}
