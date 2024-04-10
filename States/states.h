#ifndef states_h
#define states_h

#include <vector>
#include <string>

using namespace std;

class States
{
private:
    vector<string> Names;

public:
    void Load(File definition, bool valid);
    void View();
    bool Is_Element(string value);
};

#endif