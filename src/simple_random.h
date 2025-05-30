//
// Created by cyan on 5/29/25.
//

#ifndef SIMPLE_RANDOM_H
#define SIMPLE_RANDOM_H
#include <random>

#include "random_source.h"


class SimpleRandom final : public RandomSource {
    std::mt19937 gen;
    std::uniform_real_distribution<float> floatDist;
public:
    float nextFloat() override;

    int nextInt(int low, int high) override;
};



#endif //SIMPLE_RANDOM_H
