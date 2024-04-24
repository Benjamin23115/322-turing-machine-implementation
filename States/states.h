#ifndef states_h
#define states_h

#include "string_pointer.h"
#include <string>

using namespace std;

class State
{
private:
    String_Pointer Names;
    static int number_of_states;

public:
    State();
    State(string state_name);
    State(const State &state);
    virtual ~State();
    State &operator=(const State &state);
    void get_name(string &state_name) const;
    void set_name(string state_name);
    static int total_number_of_state();
};
typedef State *state_pointer;

#endif