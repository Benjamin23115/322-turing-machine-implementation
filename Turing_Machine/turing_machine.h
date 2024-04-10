#ifndef turing_machine_h
#define turing_machine_h

#include <vector>
#include <string>

using namespace std;

class TuringMachine
{
private:
    vector<string> Description;
    string Initial_State;
    string Current_State;
    string Original_Input;
    string Original_Input_String;
    int Number_Of_Transitions;
    bool Valid;
    bool Used;
    bool Operating;
    bool Accepted;
    bool Rejected;
    public:
    void Turing_Machine(string Definition_File_Name);
    void View_Definition();
    void View_Instantaneous_Description(int Maximum_Number_Of_Cells);
    void Initialize(string Input_String);
    void Perform_Transitions(int Maximum_Number_Of_Transitions);
    void Terminate_Operation();
    string Input_String();
    int Total_Number_Of_Transitions();
    bool Is_Valid_Definition();
    bool Is_Valid_Input_String();
    bool Is_Used();
    bool Is_Operating();
    bool Is_Accepted_Input_String();
    bool Is_Rejected_Input_String();
};
#endif