#ifndef tape_alphabet_h
#define tape_alphabet_h

#include <vector>
using namespace std;

class Tape_Alphabet
{
private:
    vector<char> Alphabet;

public:
    void Load(File Definition, bool Valid);
    bool Is_Element(char value);
};

#endif