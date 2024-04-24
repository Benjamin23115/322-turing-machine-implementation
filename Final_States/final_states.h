#ifndef final_states_h
#define final_states_h
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Final_States
{
private:
    vector<string> Names;

public:
    void load(ifstream &definition, bool &valid);
    void View() const;
    int Size() const;
    string Element(int index);
    bool Is_Element(string value);
};

#endif