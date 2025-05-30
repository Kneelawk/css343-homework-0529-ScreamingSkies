//
// Created by cyan on 5/29/25.
//

#include "fruit_factory.h"

#include <stdexcept>

Fruit *FruitFactory::spawn() const {
    const float selection = rng.nextFloat() * totalWeight;
    float accumulated = 0;
    for (const auto &spawner: fruits) {
        accumulated += spawner.second;
        if (accumulated > selection) {
            return spawner.first();
        }
    }

    throw std::logic_error("Tried to spawn nothing!");
}

void FruitFactory::addFruitSpawner(const std::pair<std::function<Fruit *()>, float> &spawner) {
    fruits.push_back(spawner);
    totalWeight += spawner.second;
}
