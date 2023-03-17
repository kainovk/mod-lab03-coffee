// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <iostream>


class CoffeeMachine {
public:
    CoffeeMachine(int* prices, std::string* drinks, int count);
    void on();
    void off();
    void coin(int c);
    std::string getMenu();
    std::string getState();
    void choice(int drinkIndex);
    void check();
    void cancel();
    void cook();
    void finish();
private:
    enum State { OFF, WAIT, ACCEPT, CHOICE, CHECK, COOK };
    int* _prices;
    std::string* _drinks;
    int _count;
    int _balance;
    int _chosen;
    State _state;
};

#endif  // INCLUDE_AUTOMATA_H_
