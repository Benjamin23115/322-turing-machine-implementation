#ifndef input_alphabet_h
#define input_alphabet_h

#include <vector>
#include <fstream>

using namespace std;

class Input_Alphabet
{
private:
    vector<char> alphabet;

public:
    void load(ifstream &definition, bool &valid);
    void view() const;
    int size() const;
    char element(int index) const;
    bool is_element(char value) const;
};
#endif