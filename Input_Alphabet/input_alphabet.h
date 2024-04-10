#ifndef input_alphabet_h
#define input_alphabet_h
#include <vector>
using namespace std;

class Input_Alphabet
{
private:
    vector<char> Alphabet;

public:
    void Load(File Definition, bool Valid);
    void View();
    int Size();
    char Element(int index);
    bool Is_Element(char value);
};

#endif