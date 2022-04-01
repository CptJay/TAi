//
// Created by Jay on 1/04/2022.
//

#include "Transition.h"

const std::string &Transition::getFrom() const {
    return from;
}

void Transition::setFrom(const std::string &from) {
    Transition::from = from;
}

const std::string &Transition::getTo() const {
    return to;
}

void Transition::setTo(const std::string &to) {
    Transition::to = to;
}

const std::string &Transition::getInput() const {
    return input;
}

void Transition::setInput(const std::string &input) {
    Transition::input = input;
}
