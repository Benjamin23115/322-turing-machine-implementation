#include "turing_machine.h"
#include "config_settings.h"
#include "input_strings.h"

#include <exception>
#include <string>
#include <iostream>

using namespace std;

string toLower(const std::string &str)
{
    std::string result = str;
    for (char &ch : result)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ch += 32;
        }
    }
    return result;
}
void showHelp()
{
    cout << "D  Delete input string from list" << endl;
    cout << "X  Exit Application" << endl;
    cout << "H  Help user " << endl;
    cout << "I  Insert input string into list" << endl;
    cout << "L  List input strings" << endl;
    cout << "Q  Quit operation of Turing machine" << endl;
    cout << "R  Run Turing machine on input string" << endl;
    cout << "E  Set maximum number of transitions to perform" << endl;
    cout << "W  Show status of application" << endl;
    cout << "T  Truncate instantaneous descriptions" << endl;
    cout << "V  View Turing Machine" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Error: Invalid number of arguments" << endl;
        return 1;
    }

    ConfigSettings configs(argv[1]);

    Turing_Machine tm(configs.get_file_name());

    if (!tm.is_valid_definition())
    {
        return 1;
    }
    Input_Strings inputs(configs.get_file_name());

    string command;
    string entry;
    while (toLower(command).front() != 'x')
    {
        cout << "Command: ";
        getline(cin, command);
        switch (command.front())
        {
        case 'h':
            showHelp();
            break;
        case 'w':
            cout << "TM being used is: '" << configs.get_file_name() << " " << endl;
            cout << "Max Transitions: " << configs.get_max_cells() << endl;
            cout << "Max Cells: " << configs.get_max_transitions() << endl;
            cout << "TM Status: ";
            if (!tm.is_operating() && !tm.is_used())
            {
                cout << "No string has been read yet" << endl;
            }
            else if (tm.is_operating())
            {
                cout << "String '" << tm.input_string() << "' is currently running" << endl;
                cout << tm.total_number_of_transitions() << ".  transitions have been run" << endl;
            }
            else
            {
                cout << "String '" << tm.input_string() << "' has finished running" << endl;
                if (tm.is_accepted_input_string())
                {
                    cout << "Has been accepted at " << tm.total_number_of_transitions() << " lines" << endl;
                }
                else if (tm.is_rejected_input_string())
                {
                    cout << "Has been rejected at " << tm.total_number_of_transitions() << " lines" << endl;
                }
                else
                {
                    cout << "Error: String Acceptance/Rejection is malfunctioning" << endl;
                }
            }
            cout << "Cpts 322" << endl
                 << "Spring 2024" << endl
                 << "Neil Corrigan" << endl
                 << "Benjamin Farias Dela Mora" << endl
                 << "v1.1" << endl;
            break;
        case 'v':
            tm.view_description();
            break;
        case 'd':
            cout << "Input String Number: ";
            getline(cin, entry);

            if (inputs.remove_string(stoi(entry)))
            {
                cout << "String Deleted" << endl;
            }
            else
            {
                cout << "invalid number" << endl;
            }
            break;
        case 'i':
            cout << "Please insert a new String from SIGMA*: " << endl;
            getline(cin, entry);
            if (inputs.add_string(entry))
            {
                cout << entry << " has been added to list" << endl;
            }
            else
            {
                cout << "List is unchanged" << endl;
            }
            break;
        case 'l':
            inputs.view();
            break;
        case 'q':
            if (tm.is_operating())
            {
                tm.terminate_operation();
            }
            else
            {
                cout << "Error: No string is currently being run" << endl;
            }
            break;
        case 'r':
            if (configs.get_op_state() == 0 || configs.get_op_state() == 3)
            {
                cout << "Please enter a string: ";
                getline(cin, command);
            }
            tm.initialize(inputs.get_string(stoi(command)));
            tm.view_instantaneous_description(configs.get_max_cells());
            tm.perform_transitions(configs.get_max_transitions());
            if (tm.is_accepted_input_string())
            {
            }

            break;
        case 'e':
            int maxNumberOfTransitionsInput;
            cout << "Max number of Transitions [" << configs.get_max_transitions() << "]:" << endl;
            getline(cin, entry);
            maxNumberOfTransitionsInput = stoi(entry);
            if (maxNumberOfTransitionsInput < 1)
            {
                cout << "Invalid entry: Setting unchanged" << endl;
            }
            else
            {
                configs.set_max_transitions(maxNumberOfTransitionsInput);
                cout << "Setting changed to " << configs.get_max_transitions() << endl;
            }

            break;
        case 't':
            int truncateInput;
            cout << "Number of Cells[" << configs.get_max_cells() << "]:" << endl;
            getline(cin, entry);
            truncateInput = stoi(entry);
            if (truncateInput < 1)
            {
                cout << "Invalid entry: Setting unchanged" << endl;
            }
            else
            {
                configs.set_max_cells(truncateInput);
                cout << "Setting changed to " << configs.get_max_cells() << endl;
            }
            break;
        case 'x':

            break;
        default:
            cout << "Invalid Command" << endl;
        }
    }
    return 0;
}