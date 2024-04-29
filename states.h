#ifndef states_h
#define states_h

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class States {
private:
    vector<string> names;
public:
    void load(ifstream& definition, bool& valid);
    void view() const;
    bool is_element(string value) const;
};

#endif