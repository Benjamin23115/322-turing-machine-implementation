#ifndef input_alphabet_h
#define input_alphabet_h
#include <fstream>
#include <vector>
using namespace std;

class Input_Alphabet
{
private:
    vector<char> Alphabet;

public:
    void load(fstream &definition, bool &valid);
    void View();
    int Size();
    char Element(int index);
    bool Is_Element(char value) const;
};

#endif