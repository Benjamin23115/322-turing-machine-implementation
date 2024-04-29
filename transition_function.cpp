#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "transition_function.h"
#include "transition.h"
#include "tape_alphabet.h"
#include "states.h"
#include "final_states.h"
#include "direction.h"

using namespace std;

void Transition_Function::load(ifstream &definition, bool &valid)
{
    valid = true; 

    string source_state;
    char read_character;
    string destination_state;
    char write_character;
    char move_direction;

    string token;
    while (definition >> source_state >> read_character >> destination_state >> write_character >> move_direction)
    {
        Transition transition(source_state, read_character, destination_state, write_character, move_direction);
        transitions.push_back(transition);
    }
}

void Transition_Function::validate(const Tape_Alphabet &tape_alphabet, const States &states, const Final_States &final_states, bool &valid) const
{
    valid = true; 

    for (const auto &transition : transitions)
    {
        if (final_states.is_element(transition.source_state()))
        {
            cout << "Error: Source state " << transition.source_state() << " is in the set of final states." << endl;
            valid = false;
        }
    }
}

void Transition_Function::view() const
{
    cout << "Delta = { ";
    for (const auto &transition : transitions)
    {
        cout << transition.source_state() << " " << transition.read_character() << " " << transition.destination_state() << " " << transition.write_character() << " " << transition.move_direction() << endl;
    }
    cout << " }" << endl;
}

void Transition_Function::find_transition(string source_state, char read_character, string &destination_state, char &write_character, direction &move_direction, bool &valid) const
{
    for (const auto &transition : transitions)
    {
        if (transition.source_state() == source_state && transition.read_character() == read_character)
        {
            destination_state = transition.destination_state();
            write_character = transition.write_character();
            move_direction = transition.move_direction();
            valid = true;
            return;
        }
    }
    valid = false;
}
