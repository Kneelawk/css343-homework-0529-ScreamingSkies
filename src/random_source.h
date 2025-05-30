//
// Created by cyan on 5/29/25.
//

#ifndef RANDOM_SOURCE_H
#define RANDOM_SOURCE_H



class RandomSource {
public:
    virtual ~RandomSource() = default;

    virtual float nextFloat() = 0;
    virtual int nextInt(int low, int high) = 0;
};



#endif //RANDOM_SOURCE_H
