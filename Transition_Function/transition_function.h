#ifndef transition_function_h
#define transition_function_h
#include "../direction.h"
#include <string>

using namespace std;

class Transition_Function
{
private:
public:
    void Load(File Definition, bool Valid);
    void Validate(bool Valid);
    void View();
    void Find_Transition(string Source_State, char Read_Character, string Destination_String, char Write_Character, Direction Move_Direction, bool Found);
};

#endif