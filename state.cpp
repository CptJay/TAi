//
// Created by Jay on 31/03/2022.
//

#include "state.h"

state::state(const string &name, bool accepting, bool starting) : name(name), accepting(accepting),
                                                                  starting(starting) {}

const string &state::getName() const {
    return name;
}

void state::setName(const string &name) {
    state::name = name;
}

bool state::isAccepting() const {
    return accepting;
}

void state::setAccepting(bool accepting) {
    state::accepting = accepting;
}

bool state::isStarting() const {
    return starting;
}

void state::setStarting(bool starting) {
    state::starting = starting;
}


