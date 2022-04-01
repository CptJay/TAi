//
// Created by Jay on 1/04/2022.
//

#ifndef CLION_PARSER_H
#define CLION_PARSER_H
#include "iostream"
#include "fstream"
#include "iomanip"
#include "json.hpp"


using json = nlohmann::json;

class State;
class Transition;
class Parser {
public:

    Parser();

    Parser(const std::string &fname);

    std::string getType() const;

    std::vector<std::string> getAlphabet() const;

    std::vector<State *> getStates() const;

    std::vector<Transition *> getTransitions() const;

    void setType(const std::string &type);

    void setAlphabet(const std::vector<std::string> &alphabet);

    void setStates(const std::vector<State *> &states);

    void setTransitions(const std::vector<Transition *> &transitions);

    void print() const;

protected:
    std::string type;
    std::vector<std::string> alphabet;
    std::vector<State*> states;
    std::vector<Transition*> transitions;
};


#endif //CLION_PARSER_H
