#include <string>
#include "direction.h"

using namespace std;

string uppercase(string s)
{
    string result = "";
    for (unsigned int i = 0; i < s.length(); i++)
    {
        result += toupper(s[i]);
    }
    return result;
}

direction uppercase(direction d)
{
    return d;
}