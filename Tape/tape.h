#ifndef tape_h
#define tape_h

#include <string>
using namespace std;

class Tape
{
private:
    string Cells = "";
    int Current_Cell = 0;
    char Blank = " ";

public:
    void load(File definition, bool valid);
    void View();
    void initialize(string input_string);
    string left(int maximum_number_of_cells);
    string right(int maximum_number_of_cells);
    char Current_Character();
    bool Is_First_Cell();
};

#endif