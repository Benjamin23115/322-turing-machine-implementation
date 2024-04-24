#ifndef tape_alphabet_h
#define tape_alphabet_h
#include <fstream>
#include <vector>
using namespace std;

class Tape_Alphabet
{
private:
    vector<char> Alphabet;

public:
    void load(fstream &definition, bool &valid);
    bool Is_Element(char value) const;
};

#endif