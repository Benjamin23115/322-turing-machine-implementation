#include "states.h"
#include "string_pointer.h"

#include <string>

using namespace std;

int state::number_of_states = 0;

state::state()
{
    name = new string;
    ++number_of_states;
}
state::state(string state_name)
{
    name = new string(state_name);
    ++number_of_states;
}
state::state(const state &state)
{
    name = new string(*state_name);
    ++number_of_states;
}
state::~state()
{
    delete name;
    --number_of_states;
}

state &state::operator=(const state &state)
{
    if (this != &state)
    {
        *name = *state_name;
    }
    return *this;
}

void state::get_name(string &state_name) const
{
    state_name = *name;
}
void state::set_name(string state_name)
{
    *name = state_name;
}
int state::total_number_of_state()
{
    return number_of_states;
}