#include "crash.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

Crash::Crash(string reason) : runtime_error(reason.c_str())
{
    cout << "Application crashed due to: " << reason << endl;
}