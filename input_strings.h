#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Input_Strings
{
private:
    vector<string> string_list;
    bool is_updated = false;

public:
    Input_Strings(string definition_file_name);
    void view();
    bool add_string(string new_string);
    bool remove_string(int index);
    string get_string(int index);
    bool check_status();
};