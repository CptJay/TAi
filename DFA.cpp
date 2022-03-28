//
// Created by User on 18/02/2022.
//

#include "DFA.h"
#include "iostream"
#include <iomanip>

DFA::DFA() {
    states = {"S0", "S1", "S2"};
//    alfabet = {'0', '1'};
    startState = "S0";
    fstates = {"S0"};

    // make map to check for final states
    this->addAcceptanceState(states, fstates);

    // point to the next state
    nextState["S0"][alfabet[0]] = "S0";
    nextState["S0"][alfabet[1]] = "S1";
    nextState["S1"][alfabet[0]] = "S2";
    nextState["S1"][alfabet[1]] = "S0";
    nextState["S2"][alfabet[0]] = "S1";
    nextState["S2"][alfabet[1]] = "S2";
}

DFA::DFA(const string &fname) {
    // json
    this->readInJson(fname);
}

void DFA::readInJson(const string &fname) {
    //inlezen
    ifstream input(fname);
    json j;
    input >> j;

    //gegevens importeren
    for (const auto &el: j["alphabet"]) {
        alfabet.push_back(el);
    }

    for (auto el: j["states"]) {
        states.push_back(el["name"]);
        if (el["starting"]) startState = el["name"];
        else if (el["accepting"]) fstates.push_back(el["name"]);
    }

    this->addAcceptanceState(states, fstates);
    for (auto el2: j["transitions"]) {
        this->transition(el2["from"], el2["to"], el2["input"]);
    }
}

bool DFA::accepts(const string &inP) {
    string currentState = startState;
    for (auto c: inP) { //change current state
        string s(1, c);
        currentState = nextState[currentState][s];
    }
    return stateAcceptanceDict[currentState];
}

void DFA::addAcceptanceState(const vector<string> &states, const vector<string> &fstates) {
    for (const auto &state: states) {
        for (const auto &fstate: fstates) {
            if (state == fstate) {
                stateAcceptanceDict.insert(pair<string, bool>(state, true));
            } else {
                stateAcceptanceDict.insert(pair<string, bool>(state, false));
            }
        }
    }
}

void DFA::transition(const string &from, const string &to, const string &input) {
    nextState[from][input] = to;
    //test
}

void DFA::printJson(const json &fname) const {
    //tonen op scherm
    cout << setw(4) << fname << endl;
}

void DFA::print() const {
    json j3;
    json j2;
    map<string, string> temp_map;
    map<string, string> kk2;
    j3["type"] = "DFA";
    j3["alphabet"] = alfabet;

    for (const auto &state: states) {
        j2["name"] = state;

        if (state == startState) {
            j2["starting"] = true;
        } else {
            j2["starting"] = false;
        };

        for (const auto &el: stateAcceptanceDict) {
            if (el.first == state) {
                j2["accepting"] = el.second;
            }
        }
        j3["states"].push_back(j2);
    }
    temp_map.clear();
    for (const auto &el: nextState) {
        for (const auto &el2: el.second) {
            temp_map["from"] = el.first;
            temp_map["to"] = el2.second;
            temp_map["input"] = el2.first;
            j3["transitions"].push_back(temp_map);
        }
    }
    this->printJson(j3);
}
