//
// Created by cyan on 5/29/25.
//

#include "simple_random.h"

float SimpleRandom::nextFloat() {
    return floatDist(gen);
}

int SimpleRandom::nextInt(const int low, const int high) {
    std::uniform_int_distribution<int> dist(low, high);
    return dist(gen);
}
