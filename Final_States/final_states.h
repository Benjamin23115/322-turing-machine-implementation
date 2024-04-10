#ifndef final_states_h
#define final_states_h
#include <vector>
#include <string>
using namespace std;

class Final_States
{
private:
    vector<string> Names;

public:
    void Load(File definition, bool valid);
    void View();
    int Size();
    string Element(int index);
    bool Is_Element(string value);
};

#endif