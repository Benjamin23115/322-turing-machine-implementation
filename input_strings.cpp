#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "input_strings.h"

using namespace std;

Input_Strings::Input_Strings(string definition_file_name)
{
    string token;

    ifstream definition(definition_file_name + ".str");
    while (definition >> token)
    {
        string_list.push_back(token);
    }
    definition.close();
}

void Input_Strings::view()
{
    if (string_list.empty())
    {
        cout << "List is empty" << endl;
    }
    else
    {
        for (unsigned int i = 0; i < string_list.size(); i++)
        {
            cout << i + 1 << ". " << string_list[i] << endl;
        }
    }
}

bool Input_Strings::add_string(string new_string)
{
    string_list.push_back(new_string);
    return true;
}

bool Input_Strings::remove_string(int index)
{
    if (index < 1 || index > string_list.size())
    {
        return false;
    }

    string_list.erase(string_list.begin() + index - 1);
    return true;
}

string Input_Strings::get_string(int index)
{
    if (index < 1 || index > string_list.size())
    {
        return "";
    }

    return string_list[index - 1];
}

bool Input_Strings::check_status()
{
    return is_updated;
}
