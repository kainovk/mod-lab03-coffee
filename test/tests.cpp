// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"


TEST(task3, testShouldEndInWaitState) {
    CoffeeMachine machine = prepareCoffeeMachine();
    std::string expected = "WAIT";

    machine.on();
    std::cout << "Menu:\n" << machine.getMenu() << std::endl;
    machine.coin(20);
    machine.choice(2);
    machine.check();
    machine.cook();
    machine.finish();
    std::string actual = machine.getState();

    EXPECT_EQ(expected, actual);
}

TEST(task3, testShouldEndInChoiceStateIfChoiseIsNotInRange) {
    CoffeeMachine machine = prepareCoffeeMachine();
    std::string expected = "CHOISE";

    machine.on();
    std::cout << "Menu:\n" << machine.getMenu() << std::endl;
    machine.coin(20);
    machine.choice(4);
    machine.check();
    machine.cook();
    machine.finish();
    std::string actual = machine.getState();

    EXPECT_EQ(expected, actual);
}

TEST(task3, testShouldEndInChoiceStateIfNotEnoughCoins) {
    CoffeeMachine machine = prepareCoffeeMachine();
    std::string expected = "CHOISE";

    machine.on();
    std::cout << "Menu:\n" << machine.getMenu() << std::endl;
    machine.coin(19);
    machine.choice(3);
    machine.check();
    machine.cook();
    machine.finish();
    std::string actual = machine.getState();

    EXPECT_EQ(expected, actual);
}

CoffeeMachine prepareCoffeeMachine() {
    std::string drinks[] = { "Espresso", "Cappuccino", "Latte" };
    int prices[] = { 10, 15, 20 };
    return CoffeeMachine(prices, drinks, 3);
}
