//
// Created by cyan on 5/29/25.
//

#ifndef FRUIT_H
#define FRUIT_H
#include <string>

class Fruit {
protected:
    int health;

    virtual std::string getDamageMessage(int amount) = 0;
public:
    explicit Fruit(const int health)
        : health(health) {
    }

    virtual ~Fruit() = default;

    virtual std::string getName() = 0;               // returns name of fruit, ex: Avocado
    virtual std::string getAttackMessage() = 0;      // returns message used when attacking
    virtual int getAttackDamage() = 0;          // returns amount of damage inflicted by attack

    std::string takeDamage(const int amount) {
        health -= amount;
        return getDamageMessage(amount);
    }

    bool isLiving() const {
        return health > 0;
    }
};



#endif //FRUIT_H
