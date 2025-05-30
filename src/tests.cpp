//
// Created by cyan on 4/21/25.
//

#include "fruit_factory.h"
#include "given_random.h"
#include "ktest.hpp"

KTEST(fruit_factory_balance) {
    GivenRandom random = GivenRandom::buildClimbing(16);
    FruitFactory factory(random);
    factory.addDefaultFruits();

    int dragonFruitCount = 0;
    int drawberryCount = 0;
    int bananatorCount = 0;
    for (size_t i = 0; i < 16; i++) {
        Fruit *fruit = factory.spawn();
        if (fruit->getName() == "Dragon Fruit") {
            dragonFruitCount++;
        }
        if (fruit->getName() == "Drawberry") {
            drawberryCount++;
        }
        if (fruit->getName() == "Bananator") {
            bananatorCount++;
        }
    }

    KASSERT_EQ(2, dragonFruitCount);
    KASSERT_EQ(8, drawberryCount);
    KASSERT_EQ(6, bananatorCount);
}
