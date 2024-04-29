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
    valid = false;
    string source_state;
    char read_character;
    string destination_state;
    char write_character;
    char move_direction;

    string token;
    while (token != "INITIAL_STATE:")
    {

        if (definition >> token && token != "INITIAL_STATE:")
        {
            source_state = token;
        }
        else if (token == "INITIAL_STATE:")
        {
            break;
        }
        if (definition >> token && token != "INITIAL_STATE:")
        {
            read_character = token.at(0);
        }
        else
        {
            break;
        }
        if (definition >> token && token != "INITIAL_STATE:")
        {
            destination_state = token;
        }
        else
        {
            break;
        }
        if (definition >> token && token != "INITIAL_STATE:")
        {
            write_character = token.at(0);
        }
        else
        {
            break;
        }
        if (definition >> token && token != "INITIAL_STATE:")
        {
            move_direction = token.at(0);
        }
        else
        {
            break;
        }

        Transition transition(source_state, read_character, destination_state, write_character, move_direction);
        transitions.push_back(transition);
    }
    if (token == "INITIAL_STATE:")
    {
        valid = true;
    }
}

void Transition_Function::validate(const Tape_Alphabet &tape_alphabet, const States &states, const Final_States &final_states, bool &valid) const
{

    for (unsigned int i = 0; i < transitions.size(); ++i)
    {
        if (final_states.is_element(transitions.at(i).source_state()))
        {
            cout << "Error: source state " << transitions.at(i).source_state() << " is in the set of final states." << endl;
            valid = false;
        }
        if (!states.is_element(transitions.at(i).destination_state()))
        {
            cout << "Error: destination state " << transitions.at(i).destination_state() << " is not in the set of states." << endl;
            valid = false;
        }
        if (!tape_alphabet.is_element(transitions.at(i).read_character()))
        {
            cout << "Error: read character " << transitions.at(i).read_character() << " is not in the tape alphabet." << endl;
            valid = false;
            return;
        }
        if (!tape_alphabet.is_element(transitions.at(i).write_character()))
        {
            cout << "Error: write character " << transitions.at(i).write_character() << " is not in the tape alphabet." << endl;
            valid = false;
            return;
        }
        if (transitions.at(i).move_direction() != 'L' && transitions.at(i).move_direction() != 'R')
        {
            cout << "Error: move direction " << transitions.at(i).move_direction() << " is not valid." << endl;
            valid = false;
            return;
        }
    }
    valid = true;
}

void Transition_Function::view() const
{
    cout << "delta = { ";
    for (unsigned int i = 0; i < transitions.size(); i++)
    {
        cout << endl;
        cout << transitions.at(i).source_state() << " " << transitions.at(i).read_character() << " " << transitions.at(i).destination_state() << " " << transitions.at(i).write_character() << " " << transitions.at(i).move_direction();
    }
    cout << " }" << endl;
}

void Transition_Function::find_transition(string source_state, char read_character, string &destination_state, char &write_character, direction &move_direction, bool &valid) const
{
    for (unsigned int i = 0; i < transitions.size(); ++i)
    {
        if (transitions.at(i).source_state() == source_state && transitions.at(i).read_character() == read_character)
        {
            destination_state = transitions.at(i).destination_state();
            write_character = transitions.at(i).write_character();
            move_direction = transitions.at(i).move_direction();
            valid = true;
            return;
        }
    }
    valid = false;
}