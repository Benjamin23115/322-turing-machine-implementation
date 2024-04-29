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
