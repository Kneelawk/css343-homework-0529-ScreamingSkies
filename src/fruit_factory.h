//
// Created by cyan on 5/29/25.
//

#ifndef FRUIT_FACTORY_H
#define FRUIT_FACTORY_H
#include <functional>
#include <vector>

#include "bananator.h"
#include "dragon_fruit.h"
#include "drawberry.h"
#include "fruit.h"
#include "random_source.h"


class FruitFactory {
    RandomSource &rng;
    std::vector<std::pair<std::function<Fruit *()>, float> > fruits;
    float totalWeight = 0;

public:
    explicit FruitFactory(RandomSource &rng) : rng(rng) {
    }

    Fruit *spawn() const;

    void addFruitSpawner(const std::pair<std::function<Fruit *()>, float> &spawner);

    void addDefaultFruits() {
        addFruitSpawner({[] { return new DragonFruit(); }, 0.1});
        addFruitSpawner({[] { return new Bananator(); }, 0.3});
        addFruitSpawner({[] { return new Drawberry(); }, 0.4});
    }
};


#endif //FRUIT_FACTORY_H
