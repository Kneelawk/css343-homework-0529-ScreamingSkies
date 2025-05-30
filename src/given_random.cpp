//
// Created by cyan on 5/29/25.
//

#include "given_random.h"

float GivenRandom::nextFloat() {
    const float next = given[index];
    index = (index + 1) % given.size();
    return next;
}

int GivenRandom::nextInt(const int low, const int high) {
    return static_cast<int>(nextFloat() * (high - low)) + low;
}
