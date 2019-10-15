#include <iostream>
#include "NumberSpeller.h"

int count_letters(std::string text);

int main() {
    NumberSpeller speller;

    int letter_count = 0;
    for (int n = 1; n <= 1000; n++) {
        auto number_text = speller.number_to_text(n);
        letter_count += count_letters(number_text);
    }

    std::cout << letter_count << std::endl;
    return 0;
}

// Count letters skipping spaces and hyphens
int count_letters(std::string text) {
    int result = 0;
    for (char &c : text)
    {
        if (c != ' ' && c != '-')
        {
            result++;
        }
    }
    return result;
}