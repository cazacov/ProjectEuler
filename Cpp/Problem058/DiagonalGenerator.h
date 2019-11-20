//
// Created by Victor on 20.11.2019.
//

#ifndef PROBELM058_DIAGONALGENERATOR_H
#define PROBELM058_DIAGONALGENERATOR_H


class DiagonalGenerator {
private:
    long last_block = 1;
    long last_value = 2;
    long last_result = 0;
    bool is_last_in_block = false;
public:

    long operator *() { return last_result; }

    long operator++ (int) {
        if (is_last_in_block) {
            last_block++;
        }
        is_last_in_block = !is_last_in_block;
        last_value += last_block;
        last_result = last_value - ((!is_last_in_block && (last_block & 0x01)) ? 1 : 0);
        return last_result;
    }
};


#endif //PROBELM058_DIAGONALGENERATOR_H
