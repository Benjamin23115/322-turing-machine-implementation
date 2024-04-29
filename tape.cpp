#include "tape.h"
#include "input_alphabet.h"
#include "tape_alphabet.h"
#include "direction.h"
#include "uppercase.h"

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Tape::Tape()
{
    cells = " ";
    current_cell = 0;
    blank_character = ' ';
}

void Tape::load(ifstream &definition, bool &valid)
{
    string value;
    if ((definition >> value) && (value.length() == 1) && (value[0] != '\\') && (value[0] != '[') && (value[0] != ']') && (value[0] != '<') && (value[0] != '>') && (value[0] >= '!') && (value[0] <= '~'))
    {
        blank_character = value.at(0);
    }
    else
    {
        cout << "Error: Illegal blank_character." << endl;
        valid = false;
    }
    if ((!(definition >> value)) || value != "FINAL_STATES:")
    {
        cout << "Error: Missing Keyword after blank character." << endl;
        valid = false;
    }
}

void Tape::validate(const Input_Alphabet &input_alphabet, const Tape_Alphabet &tape_alphabet, bool &valid) const
{
    if (input_alphabet.is_element(blank_character))
    {
        cout << "Error: blank character " << blank_character << " is in the input alphabet." << endl;
        valid = false;
    }
    if (!tape_alphabet.is_element(blank_character))
    {
        cout << "Error: blank character " << blank_character << " is not in the tape alphabet." << endl;
        valid = false;
    }
}

void Tape::view() const
{
    cout << "B = " << blank_character << endl
         << endl;
}

void Tape::initialize(string input_string)
{
    cells = input_string + blank_character;
    current_cell = 0;
}

void Tape::update(char write_character, direction move_direction)
{
    move_direction = uppercase(move_direction);

    if (move_direction == 'L' && current_cell == 0)
    {
        return;
    }
    if (move_direction == 'R' && current_cell == cells.length() - 1)
    {
        cells += blank_character;
    }

    cells[current_cell] = write_character;
    current_cell += (move_direction == 'L' ? -1 : 1);
}

string Tape::left(int maximum_number_of_cells) const
{
    int first_cell = max(0, current_cell - maximum_number_of_cells);
    string value = cells.substr(first_cell, current_cell - first_cell);
    if (value.length() < current_cell)
    {
        value.insert(0, "<");
    }
    return value;
}

string Tape::right(int maximum_number_of_cells) const
{
    int end_cell = cells.length() - 1;
    while (end_cell >= current_cell && cells[end_cell] == blank_character)
    {
        --end_cell;
    }
    int last_cell = min(end_cell, current_cell + maximum_number_of_cells - 1);
    string value = cells.substr(current_cell, last_cell - current_cell + 1);
    if (value.length() < (end_cell - current_cell + 1))
    {
        value.append(">");
    }
    return value;
}

char Tape::current_character() const
{
    return cells[current_cell];
}

bool Tape::is_first_cell() const
{
    return (current_cell == 0);
}
