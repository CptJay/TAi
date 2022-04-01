//
// Created by User on 18/02/2022.
//

#ifndef CLION_DFA_H
#define CLION_DFA_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>
#include "json.hpp"
#include "State.h"


using json = nlohmann::json;

class State;
class Transition;
class DFA {
private:
    std::string type;
    std::vector<std::string> alphabet;
    std::vector<State*> states;
    std::vector<Transition*> transitions;
    State* startState;

    void setStartState();


public:
    DFA(const string &fname);
    bool accepts(const string &word);
    void print() const;
};

#endif //CLION_DFA_H
