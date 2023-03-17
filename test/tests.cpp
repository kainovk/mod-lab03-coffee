// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"


CoffeeMachine prepareCoffeeMachine() {
    std::string drinks[] = { "Espresso", "Cappuccino", "Latte" };
    int prices[] = { 10, 15, 20 };
    CoffeeMachine result(prices, drinks, 3);
    return result;
}

TEST(task3, testShouldEndInWaitState) {
    CoffeeMachine machine = prepareCoffeeMachine();
    std::string expected = "WAIT";

    machine.on();
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
    machine.coin(19);
    machine.choice(3);
    machine.check();
    machine.cook();
    machine.finish();
    std::string actual = machine.getState();

    EXPECT_EQ(expected, actual);
}
