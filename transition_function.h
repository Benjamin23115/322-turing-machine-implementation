#ifndef transition_function_h
#define transition_function_h

#include "transition.h"
#include "tape_alphabet.h"
#include "states.h"
#include "final_states.h"
#include "direction.h"

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Transition_Function
{
private:
    vector<Transition> transitions;

public:
    void load(ifstream &definition, bool &valid);
    void validate(const Tape_Alphabet &tape_alphabet, const States &states, const Final_States &final_states, bool &valid) const;
    void view() const;
    void find_transition(string source_state, char read_character, string &destination_state, char &write_character, direction &move_direction, bool &found) const;
};

#endif