//
// Created by cyan on 5/29/25.
//

#ifndef BANANATOR_H
#define BANANATOR_H
#include "fruit.h"


class Bananator final : public Fruit {
protected:
    std::string getDamageMessage(int) override {
        if (health > 10) {
            return "Bananator squishes slightly.";
        }
        if (health > 0) {
            return "Bananator looks bruised.";
        }
        return "Bananator is flattened.";
    }

public:
    explicit Bananator()
        : Fruit(20) {
    }

    std::string getName() override {
        return "Bananator";
    }

    std::string getAttackMessage() override {
        return "Bananator chomps you!";
    }

    int getAttackDamage() override {
        return 8;
    }
};



#endif //BANANATOR_H
