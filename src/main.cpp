// Copyright 2022 UNN-IASR
#include "Automata.h"

#include <iostream>


int main() {
    std::string drinks[] = { "Espresso", "Cappuccino", "Latte" };
    int prices[] = { 10, 15, 20 };
    CoffeeMachine machine(prices, drinks, 3);
    machine.on();
    std::cout << "Menu:\n" << machine.getMenu() << std::endl;
    machine.coin(20);
    machine.choice(2);
    machine.check();
    machine.cook();
    machine.finish();
    return 0;
}
