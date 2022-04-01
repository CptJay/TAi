//
// Created by User on 28/03/2022.
//

#include "NFA.h"
#include "DFA.h"

NFA::NFA() {}

NFA::NFA(const string &fname) {

}

DFA NFA::toDFA() {
    DFA dfa;


    return dfa;
}

void NFA::readJson(const string &fname) {
    //inlezen
    ifstream input(fname);
    json j;
    input >> j;

    //gegevens importeren
    for (const auto &el: j["alphabet"]) {
        alfabet.push_back(el);
    }

    //
    for (auto el: j["states"]) {
        states.push_back(el["name"]);
        if (el["starting"]) startState = el["name"];
        else if (el["accepting"]) fstates.push_back(el["name"]);
    }


    //
    for (auto el: j["transitions"]) {
        nextState[el["from"]][el["input"]].push_back(el["to"]);
    }
}
