#ifndef transition_h
#define transition_h

#include "abstract.h"
#include <string>

using namespace std;

class Transition
{
private:
    string source;
    char read;
    string destination;
    char write;
    Direction move;

public:
    Transition(string Source_State, char Read_Character, string Destination_State, char Write_Character, Direction Move_Direction);
    string Source_State();
    char Read_Character();
    string Destination_State();
    char Write_Character();
    Direction Move_Direction();
};

#endif