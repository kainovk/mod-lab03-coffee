// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"


TEST(task3, testShouldEndInWaitState) {
    std::string drinks[] = { "Espresso", "Cappuccino", "Latte" };
    int prices[] = { 10, 15, 20 };
    CoffeeMachine machine(prices, drinks, 3);
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
    std::string drinks[] = { "Espresso", "Cappuccino", "Latte" };
    int prices[] = { 10, 15, 20 };
    CoffeeMachine machine(prices, drinks, 3);
    std::string expected = "CHOICE";

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
    std::string drinks[] = { "Espresso", "Cappuccino", "Latte" };
    int prices[] = { 10, 15, 20 };
    CoffeeMachine machine(prices, drinks, 3);
    std::string expected = "CHOICE";

    machine.on();
    machine.coin(19);
    machine.choice(3);
    machine.check();
    machine.cook();
    machine.finish();
    std::string actual = machine.getState();

    EXPECT_EQ(expected, actual);
}
