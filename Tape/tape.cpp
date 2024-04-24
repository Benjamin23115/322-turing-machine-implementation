#include "tape.h"
#include "input_alphabet.h"
#include "tape_alphabet.h"
#include "direction.h"
#include "crash.h"
#include "abstract.h"

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Tape::Tape() : Cells(" ")
{
}

void Tape::load(ifstream &definition, bool &valid)
{
    string value;
    if ((definition >> value) && (value.length() == 1) && (value[0] != '\\') && (value[0] != '[') && (value[0] != ']') && (value[0] != '<') && (value[0] != '>') && (value[0] >= '!') && (value[0] <= '~'))
        Blank_Character = value[0];

    else
    {
        throw Crash("Illegal Blank_Character");
        valid = false;
    }
    if ((!(definition >> value)) || (upperCase(value) != "Final_States:"))
    {
        cout << "Missing keyword after blank character" << endl;
        valid = false;
    }
}

void Tape::validate(const Input_Alphabet &Input_Alphabet, const Tape_Alphabet &Tape_Alphabet, bool &valid) const
{
    if (Input_Alphabet.Is_Element(Blank_Character))
    {
        cout << "Blank Character " << Blank_Character << " is in input alphabet" << endl;
        valid = false;
    }
    {
        if (!Tape_Alphabet.Is_Element(Blank_Character))
        {
            cout << "Blank character " << Blank_Character << " is not in tape alphabet" << endl;
            valid = false;
        }
    }
}

void Tape::view() const
{
    cout << "B = " << Blank_Character << endl
         << endl;
}

void Tape::initialize(string input_string)
{
    Cells = input_string + Blank_Character;
    Current_Cell = 0;
}

void Tape::update(char write_character, Direction move_direction)
{
    move_direction = upperCase(move_direction);
    if ((move_direction == 'L') && (Current_Cell == 0))
        throw Crash("Left move from first cell");
    if ((move_direction == 'R') && (Current_Cell == Cells.length() - 1))
        Cells += Blank_Character;
    Cells[Current_Cell] = write_character;
    if (move_direction == 'L')
        --Current_Cell;
    else
        ++Current_Cell;
}

string Tape::left(int maximum_number_of_cells) const
{
    int first_cell = max(0, Current_Cell - maximum_number_of_cells);
    string value = Cells.substr(first_cell, Current_Cell - first_cell);
    if (value.length() < Current_Cell)
        value.insert(0, "<");
    return value;
}

string Tape::right(int maximum_number_of_cells) const
{
    int end_cell = Cells.length() - 1;
    while ((end_cell >= Current_Cell) && (Cells[end_cell] == Blank_Character))
        --end_cell;
    int last_cell = min(end_cell, (Current_Cell + maximum_number_of_cells));
    string value = Cells.substr(Current_Cell, last_cell - Current_Cell + 1);
    if (value.length() < end_cell - Current_Cell + 1)
        value.append(">");
    return value;
}

char Tape::Current_Character() const
{
    return Cells[Current_Cell];
}

bool Tape::Is_First_Cell() const
{
    return (Current_Cell == 0)
}