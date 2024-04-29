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
#include "input_alphabet.h"
#include "turing_machine.h"

using namespace std;

Turing_Machine::Turing_Machine(string definition_file_name)
{
    op_used = false;
    op_operating = false;
    accepted = false;
    rejected = false;
    valid = true; // Assume the definition is valid until proven otherwise

    ifstream definition(definition_file_name.append(".def"));
    if (!definition)
    {
        cout << "Error: Unable to open file " << definition_file_name << endl;
        valid = false;
    }

    string token;
    while (definition >> token && token != "STATES:")
    {
        description.push_back(token);
        description.push_back(" ");
    }

    if (token == "STATES:")
    {
        states.load(definition, valid);
    }
    else
    {
        cout << "Error: STATES: keyword not found." << endl;
        valid = false;
    }

    if (valid)
    {
        input_alphabet.load(definition, valid);
    }
    else
    {
        cout << "Error: INPUT_ALPHABET: keyword not found." << endl;
    }

    if (valid)
    {
        tape_alphabet.load(definition, valid);
    }
    else
    {
        cout << "Error: TAPE_ALPHABET: keyword not found." << endl;
    }

    if (valid)
    {
        transition_function.load(definition, valid);
    }
    else
    {
        cout << "Error: TRANSITION_FUNCTION: keyword not found." << endl;
        valid = false;
    }

    if (valid)
    {
        definition >> initial_state;
    }
    else
    {
        cout << "Error: INITIAL_STATE: keyword not found." << endl;
        valid = false;
    }

    definition >> token;
    if (token == "BLANK_CHARACTER:")
    {
        input_tape.load(definition, valid);
        if (valid)
        {
        }
    }
    else
    {
        cout << "Error: BLANK_CHARACTER: keyword not found." << endl;
        valid = false;
    }

    if (valid)
    {
        final_states.load(definition, valid);
        if (valid)
        {
        }
    }
    else
    {
        cout << "Error: FINAL_STATES: keyword not found." << endl;
    }
    definition.close();
}

void Turing_Machine::view_description() const
{
    for (unsigned int i = 0; i < description.size(); i++)
    {
        cout << description[i];
    }
    cout << endl;
    cout << "M = (" << endl;
    states.view();
    input_alphabet.view();
    tape_alphabet.view();
    transition_function.view();
    cout << "q0 = " << initial_state << endl;
    final_states.view();
}

void Turing_Machine::view_instantaneous_description(int maximum_number_of_cells) const
{
    cout << total_number_of_transitions() << ". " << input_tape.left(maximum_number_of_cells) << "[" << current_state << "]" << input_tape.right(maximum_number_of_cells) << endl;
}

void Turing_Machine::initialize(string input_string)
{
    this->original_input_string = input_string;
    this->current_state = initial_state;
    this->number_of_transitions = 0;
    input_tape.initialize(input_string);
}

void Turing_Machine::perform_transitions(int maximum_number_of_transitions)
{
    if (!op_operating)
    {
        op_operating = true;
    }

    while (number_of_transitions < maximum_number_of_transitions)
    {

        char read_character = input_tape.current_character();

        if (final_states.is_element(current_state))
        {
            accepted = true;
            op_used = true;
            op_operating = false;
            break;
        }

        string destination_state;
        char write_character;
        direction move_direction;

        transition_function.find_transition(current_state, read_character, destination_state, write_character, move_direction, valid);

        if (!valid)
        {
            cout << "Error: No transition found for state " << current_state << " and tape character " << read_character << "." << endl;
            op_used = true;
            op_operating = false;
            rejected = true;
            break;
        }

        input_tape.update(write_character, move_direction);
        current_state = destination_state;
        number_of_transitions++;
    }
}

void Turing_Machine::terminate_operation()
{
    if (op_used)
    {
        cout << "Input String file written" << endl;
    }
    op_operating = false;
}

string Turing_Machine::input_string() const
{
    if (op_used)
    {
        return original_input_string;
    }
    else
    {
        cout << "Error: Input string has not been initialized." << endl;
        return "";
    }
}

bool Turing_Machine::is_valid_definition() const
{
    return valid;
}

bool Turing_Machine::is_valid_input_string(string value) const
{
    return valid; // Placeholder implementation, needs to be implemented properly
}

int Turing_Machine::total_number_of_transitions() const
{
    return number_of_transitions;
}

bool Turing_Machine::is_used()
{
    return op_used;
}

bool Turing_Machine::is_operating()
{
    return op_operating;
}

bool Turing_Machine::is_accepted_input_string()
{
    return accepted;
}

bool Turing_Machine::is_rejected_input_string()
{
    return rejected;
}
