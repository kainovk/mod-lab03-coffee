// Copyright 2022 UNN-IASR
#include "Automata.h"


CoffeeMachine::CoffeeMachine(int* prices, std::string* drinks, int count)
    : _balance(0), _chosen(-1), _state(OFF), _prices(prices),
    _drinks(drinks), _count(count) {}

void CoffeeMachine::on() {
    if (_state == OFF) {
        _state = WAIT;
    }
}

void CoffeeMachine::off() {
    if (_state == WAIT) {
        _state = OFF;
    }
}

void CoffeeMachine::coin(int c) {
    if (_state == WAIT || _state == ACCEPT) {
        _state = ACCEPT;
        _balance += c;
    }
}

void CoffeeMachine::cancel() {
    if (_state == CHECK || _state == CHOICE || _state == ACCEPT) {
        _state = WAIT;
        _chosen = -1;
    }
}

void CoffeeMachine::choice(int drinkIndex) {
    if (_state == ACCEPT || _state == CHOICE) {
        if (drinkIndex >= 1 && drinkIndex <= _count) {
            _chosen = drinkIndex - 1;
        } else {
            _chosen = -1;
        }
        _state = CHOICE;
    }
}

void CoffeeMachine::check() {
    if (_state == CHOICE && _chosen != -1) {
        if (_balance >= _prices[_chosen]) {
            _balance -= _prices[_chosen];
            _state = CHECK;
        }
    }
}

void CoffeeMachine::cook() {
    if (_state == CHECK) {
        _state = COOK;
    }
}

void CoffeeMachine::finish() {
    if (_state == COOK) {
        std::cout << "Take your " << _drinks[_chosen] << std::endl;
        _state = WAIT;
        _chosen = -1;
    }
}

std::string CoffeeMachine::getMenu() {
    std::string menu;
    for (int i = 0; i < _count; ++i) {
        menu += std::to_string(i + 1) + ". " + _drinks[i] +
            " - " + std::to_string(_prices[i]) + " $\n";
    }
    return menu;
}

std::string CoffeeMachine::getState() {
    switch (_state) {
    case OFF: return "OFF";
    case WAIT: return "WAIT";
    case ACCEPT: return "ACCEPT";
    case CHOICE: return "CHOICE";
    case CHECK: return "CHECK";
    case COOK: return "COOK";
    }
    return "";
}
