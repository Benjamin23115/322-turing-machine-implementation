#ifndef final_states_h
#define final_states_h

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Final_States
{
private:
    vector<string> names;

public:
    void load(ifstream &definition, bool &valid);
    void view() const;
    int size() const;
    string element(int index) const;
    bool is_element(string value) const;
};

#endif