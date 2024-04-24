#ifndef tape_h
#define tape_h

#include "input_alphabet.h"
#include "Tape_Alphabet.h"
#include "abstract.h"
#include <string>
#include <fstream>
using namespace std;

class Tape
{
private:
    string Cells;
    int Current_Cell;
    char Blank_Character;

public:
    Tape();
    void load(ifstream &definition, bool &valid);
    void validate(const Input_Alphabet &input_alphabet, const Tape_Alphabet &tape_alphabet, bool &valid) const;
    void view() const;
    void initialize(string input_string);
    void update(char write_character, Direction move_direction);
    string left(int maximum_number_of_cells) const;
    string right(int maximum_number_of_cells) const;
    char Current_Character() const;
    bool Is_First_Cell() const;
};

#endif