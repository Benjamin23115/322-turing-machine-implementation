#ifndef tape_definition_h
#define tape_definition_h

#include <vector>
#include <fstream>

using namespace std;

class Tape_Alphabet {
private: 
    vector<char> alphabet;
public:
    void load(ifstream& definition, bool& valid);
    void view() const;

    bool is_element(char value) const;
};
#endif