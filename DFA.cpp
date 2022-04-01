//
// Created by User on 18/02/2022.
//

#include "DFA.h"
#include "iostream"
#include <iomanip>
#include "Parser.h"
#include "Transition.h"

DFA::DFA(const std::string &fname) {
    // import
    Parser parser(fname);
    type = parser.getType();
    alphabet = parser.getAlphabet();
    states = parser.getStates();
    transitions = parser.getTransitions();
    setStartState();

}

bool DFA::accepts(const string &word) {
    State *currentState = startState;
    std::string destinated;
    for (auto &c: word) {
        for (auto &transition: transitions){
            if (transition->getFrom() == currentState->getName() && c == transition->getInput()[0]){
                destinated = transition->getTo();
            }
        }
        for (auto &state: states){
            if (destinated == state->getName()){
                currentState = state;
            }
        }
    }
    if (currentState->isAccepting()){
        return true;
    }
    return false;
}


void DFA::setStartState() {
    for (auto &state: states) {
        if (state->isStarting()) {
            this->startState = state;
        }
    }
}

void DFA::print() const {
    Parser parser;
    parser.setType(type);
    parser.setAlphabet(alphabet);
    parser.setStates(states);
    parser.setTransitions(transitions);
    parser.print();
}
