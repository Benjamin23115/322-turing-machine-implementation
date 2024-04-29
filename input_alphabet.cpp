#include <vector>
#include <fstream>
#include <iostream>
#include "input_alphabet.h"

using namespace std;

void Input_Alphabet::load(ifstream &definition, bool &valid)
{
    valid = false;
    string token;
    definition >> token;
    while (token != "TAPE_ALPHABET:")
    {
        if (token.size() != 1 || is_element(token[0]) || token[0] == '\\' || token[0] == '[' || token[0] == ']' || token[0] == '<' || token[0] == '>')
        {
            cout << "Error: Invalid Input Alphabet entry: " << token << endl;
            valid = false;
            return; // Exit the function immediately upon encountering an error
        }
        else
        {
            alphabet.push_back(token[0]);
        }
        definition >> token;
    }
    if (token == "TAPE_ALPHABET:")
    {
        valid = true;
    }
}
void Input_Alphabet::view() const
{
    cout << "Sigma = { ";
    for (int i = 0; i < size(); i++)
    {
        cout << element(i) << " ";
    }
    cout << "}" << endl;
}

int Input_Alphabet::size() const
{
    return alphabet.size();
}

char Input_Alphabet::element(int index) const
{
    return alphabet.at(index);
}

bool Input_Alphabet::is_element(char value) const
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
