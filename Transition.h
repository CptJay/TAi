//
// Created by Jay on 1/04/2022.
//

#ifndef CLION_TRANSITION_H
#define CLION_TRANSITION_H
#include "iostream"

class Transition {
public:
    const std::string &getFrom() const;

    void setFrom(const std::string &from);

    const std::string &getTo() const;

    void setTo(const std::string &to);

    const std::string &getInput() const;

    void setInput(const std::string &input);

private:
    std::string from;
    std::string to;
    std::string input;
};


#endif //CLION_TRANSITION_H
