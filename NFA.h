//
// Created by User on 28/03/2022.
//

#ifndef CLION_NFA_H
#define CLION_NFA_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>
#include "json.hpp"


using namespace std;

class DFA;
class NFA {
public:
    NFA();
    explicit NFA(const string &fname);
    void readJson(const string &fname);
    DFA toDFA();

private:
    string type;
    vector<string> alfabet;
    vector<string> states;
    map<string, map<string, vector<string>>> nextState;

    string startState;
    vector<string> fstates;
};


#endif //CLION_NFA_H
