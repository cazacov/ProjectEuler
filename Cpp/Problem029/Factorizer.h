//
// Created by Victor on 24.10.2019.
//

#ifndef PROBLEM029_FACTORIZER_H
#define PROBLEM029_FACTORIZER_H


#include <vector>

class Factorizer {
private:
    std::vector<int> primes_pool;
public:
    Factorizer(std::vector<int> &pool);

    std::vector<std::pair<int, int>> do_factorization(int i);
};


#endif //PROBLEM029_FACTORIZER_H
