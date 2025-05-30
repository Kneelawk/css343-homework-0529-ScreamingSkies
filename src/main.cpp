#include <iostream>

#include "fruit.h"
#include "fruit_factory.h"
#include "ktest.hpp"
#include "simple_random.h"

int main() {
    ktest::runAllTests();

    std::cout <<
            "In the future, fruits have come to life.\nIn this world, it's eat or be eaten.\nYou are hungry. You must kill and eat fruits to survive."
            << std::endl;

    SimpleRandom random;
    FruitFactory factory(random);
    factory.addDefaultFruits();

    int remainingFruits = 10;
    int health = 50;
    Fruit *fruit = nullptr;

    std::string input;
    while (true) {
        std::cout << "You must find " << remainingFruits << " fruits or starve." << std::endl;
        std::cout << "Your health: " << health << std::endl;

        if (fruit == nullptr) {
            std::cout << "You are not battling any fruits at the moment." << std::endl;

            std::cout << "What would you like to do? (walk, quit)" << std::endl;
            if (!std::getline(std::cin, input)) {
                std::cout << "Oh well, play again sometime? Quitting..." << std::endl;
                return 0;
            }

            if (input == "walk") {
                fruit = factory.spawn();
                std::cout << "You encounter a " << fruit->getName() << std::endl;
            } else if (input == "quit") {
                std::cout << "Oh well, play again sometime? Quitting..." << std::endl;
                return 0;
            }
        } else {
            std::cout << "Fruit: " << fruit->getName() << std::endl;

            std::cout << "What would you like to do? (flee, attack, quit)" << std::endl;
            if (!std::getline(std::cin, input)) {
                std::cout << "Oh well, play again sometime? Quitting..." << std::endl;
                return 0;
            }

            if (input == "flee") {
                std::cout << "You flee." << std::endl;
                fruit = nullptr;
            } else if (input == "attack") {
                std::cout << "You attack " << fruit->getName() << ", dealing 15 points of damage!" << std::endl;
                std::cout << fruit->takeDamage(15) << std::endl;
                if (fruit->isLiving()) {
                    std::cout << fruit->getName() << " is still around though. It attacks back!" << std::endl;
                    std::cout << fruit->getAttackMessage() << std::endl;
                    std::cout << fruit->getName() << " deals " << fruit->getAttackDamage() << " points of damage!" <<
                            std::endl;
                    health -= fruit->getAttackDamage();

                    if (health <= 0) {
                        std::cout << "You are dead. GAME OVER" << std::endl;
                        return 0;
                    }
                } else {
                    std::cout << "You killed " << fruit->getName() << ". You may now eat it." << std::endl;
                    remainingFruits--;
                    delete fruit;
                    fruit = nullptr;

                    if (remainingFruits <= 0) {
                        std::cout << "You are full now. YOU WIN" << std::endl;
                        return 0;
                    }
                }
            } else if (input == "quit") {
                std::cout << "Oh well, play again sometime? Quitting..." << std::endl;
                return 0;
            }
        }
    }
}
