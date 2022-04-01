//
// Created by Jay on 1/04/2022.
//

#include "Parser.h"
#include "State.h"
#include "Transition.h"

Parser::Parser() {}

Parser::Parser(const std::string &fname) {
    // read from json file
    std::ifstream input(fname);
    json j;
    input >> j;

    // import data
    this->type = j["type"];
    for (auto &el: j["alphabet"]) {
        this->alphabet.push_back(el);
    }
    for (auto &el: j["states"]) {
        auto *state = new State;
        state->setName(el["name"]);
        state->setStarting(el["starting"]);
        state->setAccepting(el["accepting"]);
        this->states.push_back(state);
    }
    for (auto &el: j["transitions"]) {
        auto *transition = new Transition;
        transition->setFrom(el["from"]);
        transition->setTo(el["to"]);
        transition->setInput(el["input"]);
        transitions.push_back(transition);
    }
}

string Parser::getType() const {
    return type;
}

std::vector<std::string> Parser::getAlphabet() const {
    return alphabet;
}

std::vector<State *> Parser::getStates() const {
    return states;
}

std::vector<Transition *> Parser::getTransitions() const {
    return transitions;
}

void Parser::setType(const string &type) {
    Parser::type = type;
}

void Parser::setAlphabet(const std::vector<std::string> &alphabet) {
    Parser::alphabet = alphabet;
}

void Parser::setStates(const std::vector<State *> &states) {
    Parser::states = states;
}

void Parser::setTransitions(const std::vector<Transition *> &transitions) {
    Parser::transitions = transitions;
}

void Parser::print() const {
    json j;
    j["type"] = type;
    j["alphabet"] = alphabet;
    for (auto &state: states){
        json j2;
        j2["name"] = state->getName();
        j2["starting"] = state->isStarting();
        j2["accepting"] = state->isAccepting();
        j["states"].push_back(j2);
    }
    for (auto &transition: transitions){
        json j2;
        j2["from"] = transition->getFrom();
        j2["to"] = transition->getTo();
        j2["input"] = transition->getInput();
        j["transitions"].push_back(j2);
    }
    std::cout << std::setw(4) << j << std::endl;
}


