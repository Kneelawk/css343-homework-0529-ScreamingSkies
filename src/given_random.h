//
// Created by cyan on 5/29/25.
//

#ifndef GIVEN_RANDOM_H
#define GIVEN_RANDOM_H
#include <vector>
#include <cstddef>

#include "random_source.h"


class GivenRandom final : public RandomSource {
    std::vector<float> given;
    size_t index = 0;

public:
    explicit GivenRandom(const std::vector<float> &given)
        : given(given) {
    }

    float nextFloat() override;

    int nextInt(int low, int high) override;

    static GivenRandom buildClimbing(const size_t count) {
        std::vector<float> floats;
        for (size_t i = 0; i < count; i++) {
            floats.push_back(static_cast<float>(i) / static_cast<float>(count));
        }
        return GivenRandom(floats);
    }
};


#endif //GIVEN_RANDOM_H
