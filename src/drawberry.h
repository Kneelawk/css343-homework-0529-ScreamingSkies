//
// Created by cyan on 5/29/25.
//

#ifndef DRAWBERRY_H
#define DRAWBERRY_H
#include "fruit.h"


class Drawberry final : public Fruit {
protected:
    std::string getDamageMessage(int) override {
        return "Drawberry goes squish!";
    }

public:
    explicit Drawberry()
        : Fruit(10) {
    }

    std::string getName() override {
        return "Drawberry";
    }

    std::string getAttackMessage() override {
        return "Drawberry catches you in its web!";
    }

    int getAttackDamage() override {
        return 4;
    }
};



#endif //DRAWBERRY_H
