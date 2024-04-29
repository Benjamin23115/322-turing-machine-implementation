#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "input_strings.h"

using namespace std;

Input_Strings::Input_Strings(string definition_file_name)
{
    string token;

    ifstream definition(definition_file_name.append(".str"));
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
            cout << i + 1 << ". " << string_list.at(i) << endl;
        }
    }
}
bool Input_Strings::add_string(string new_string)
{

    return false;
}
bool Input_Strings::remove_string(int index)
{
    return false;
}
string Input_Strings::get_string(int index)
{
    return string_list.at(index - 1);
}
bool Input_Strings::check_status()
{
    return is_updated;
}