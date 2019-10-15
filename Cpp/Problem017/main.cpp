#include <iostream>
#include "NumberSpeller.h"

int main() {
    NumberSpeller speller;

    auto one = speller.NumberToText(1);

    std::cout << one << std::endl;
    return 0;
}
