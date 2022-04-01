//
// Created by Jay on 31/03/2022.
//

#include "State.h"


State::State() {}

State::State(const string &name, bool accepting, bool starting) : name(name), accepting(accepting),
                                                                  starting(starting) {}

const string &State::getName() const {
    return name;
}

void State::setName(const string &name) {
    State::name = name;
}

bool State::isAccepting() const {
    return accepting;
}

void State::setAccepting(bool accepting) {
    State::accepting = accepting;
}

bool State::isStarting() const {
    return starting;
}

void State::setStarting(bool starting) {
    State::starting = starting;
}


