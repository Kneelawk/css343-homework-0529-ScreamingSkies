//
// Created by cyan on 5/29/25.
//

#ifndef DRAGON_FRUIT_H
#define DRAGON_FRUIT_H
#include "fruit.h"


class DragonFruit final : public Fruit {
public:
    explicit DragonFruit()
        : Fruit(100) {
    }

    std::string getName() override {
        return "Dragon Fruit";
    }

    std::string getAttackMessage() override {
        return "Dragon Fruit breathes fire over you!";
    }

    int getAttackDamage() override {
        return 15;
    }

protected:
    std::string getDamageMessage(int) override {
        if (health > 75) {
            return "Dragon Fruit loses some of its scales.";
        }
        if (health > 50) {
            return "Dragon Fruit loses a little juice.";
        }
        if (health > 25) {
            return "Dragon Fruit can no longer fly.";
        }
        if (health > 0) {
            return "Dragon Fruit is on its last legs.";
        }
        return "Dragon Fruit explodes in a fireball. (You're fine though.)";
    }
};



#endif //DRAGON_FRUIT_H
