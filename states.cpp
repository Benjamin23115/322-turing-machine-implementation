#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "states.h"

using namespace std;

void States::load(ifstream& definition, bool& valid){
    valid = false;
    string token;
    definition >> token;
    while(token != "INPUT_ALPHABET:"){    
        if(is_element(token)){
            valid = false;
            break;
        } else {
            names.push_back(token);
        }
        definition >> token;
    }
    if(names.size() == 0){
        valid = false;
    } else {
        valid = true;
    }
}

void States::view() const{
    cout << "Q = { ";
    for(unsigned int i = 0; i < names.size(); i++){
        cout << names[i] << " ";
    }
    cout << "}" << endl;
}

bool States::is_element(string value) const{
    for(unsigned int i = 0; i < names.size(); i++){
        if(names[i] == value){
            return true;
        }
    }
    return false;
}