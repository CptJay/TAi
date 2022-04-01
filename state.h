//
// Created by Jay on 31/03/2022.
//

#ifndef CLION_STATE_H
#define CLION_STATE_H
#include <iostream>
using namespace std;

class state {
public:
    state(const string &name, bool accepting, bool starting);

    const string &getName() const;

    void setName(const string &name);

    bool isAccepting() const;

    void setAccepting(bool accepting);

    bool isStarting() const;

    void setStarting(bool starting);

private:
    string name;
    bool accepting = false;
    bool starting = false;

};


#endif //CLION_STATE_H
