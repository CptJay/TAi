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

using namespace std;
using json = nlohmann::json;

class DFA {
private:
    vector<string> states;
    map<string, bool> stateAcceptanceDict;
    map<string, map<string, string>> nextState;
    vector<string> fstates;
    vector<string> alfabet;
    string startState;


public:
    DFA();
    explicit DFA(const string &fname);
    void addAcceptanceState(const vector<string>& states, const vector<string>& fstates);
    void transition(const string &from, const string &to, const string &input);
    void printJson(const json& fname) const;
    bool accepts(const string &inP);
    void readInJson(const string &fname);
    void print() const;
};

#endif //CLION_DFA_H
