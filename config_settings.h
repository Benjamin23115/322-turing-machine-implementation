#include <string>

using namespace std;

class ConfigSettings
{
private:
    int MAX_TRANSITIONS = 1;
    int MAX_CELLS = 32;
    int OP_STATE = 0;
    string fileName;

public:
    ConfigSettings(string fileName)
    {
        this->fileName = fileName;
    };
    int get_max_transitions() const
    {
        return MAX_TRANSITIONS;
    };
    int get_max_cells() const
    {
        return MAX_CELLS;
    };
    int get_op_state() const
    {
        return OP_STATE;
    };
    string get_file_name() const
    {
        return fileName;
    };
    void set_max_transitions(int value)
    {
        MAX_TRANSITIONS = value;
    };
    void set_max_cells(int value)
    {
        MAX_CELLS = value;
    };
    void set_op_state(int value)
    {
        OP_STATE = value;
    };
};