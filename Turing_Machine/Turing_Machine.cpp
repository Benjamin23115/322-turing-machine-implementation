#include "turing_machine.h"
#include "transition.h"

#include <string>
#include <vector>
#include <sstream>
#include <fstream>

void Turing_Machine(const std::string &input,
                    std::string &states,
                    std::string &inputAlphabet,
                    std::string &tapeAlphabet,
                    std::vector<Transition> &transitions,
                    std::string &initialState,
                    std::string &blankCharacter,
                    std::vector<std::string> &finalStates)
{
    std::istringstream iss(input);
    std::string line;

    while (std::getline(iss, line))
    {
        if (line.find("STATES:") != std::string::npos)
        {
            states = line.substr(line.find(":") + 1);
        }
        else if (line.find("INPUT_ALPHABET:") != std::string::npos)
        {
            inputAlphabet = line.substr(line.find(":") + 1);
        }
        else if (line.find("TAPE_ALPHABET:") != std::string::npos)
        {
            tapeAlphabet = line.substr(line.find(":") + 1);
        }
        else if (line.find("TRANSITION_FUNCTION:") != std::string::npos)
        {
            while (std::getline(iss, line) && !line.empty())
            {
                std::istringstream ss(line);
                std::string currentState, nextState;
                char readSymbol, writeSymbol, moveDirection;
                ss >> currentState >> readSymbol >> nextState >> writeSymbol >> moveDirection;
                transitions.push_back({currentState, readSymbol, nextState, writeSymbol, moveDirection});
            }
        }
        else if (line.find("INITIAL_STATE:") != std::string::npos)
        {
            initialState = line.substr(line.find(":") + 1);
        }
        else if (line.find("BLANK_CHARACTER:") != std::string::npos)
        {
            blankCharacter = line.substr(line.find(":") + 1);
        }
        else if (line.find("FINAL_STATES:") != std::string::npos)
        {
            std::istringstream ss(line.substr(line.find(":") + 1));
            std::string state;
            while (ss >> state)
            {
                finalStates.push_back(state);
            }
        }
    }
}