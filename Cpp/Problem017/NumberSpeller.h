//
// Created by Victor on 15.10.2019.
//

#ifndef PROBLEM017_NUMBERSPELLER_H
#define PROBLEM017_NUMBERSPELLER_H

#include <string>

class NumberSpeller {
private:
    std::string convert_1to20(int n) const;
    std::string convert_tens(int n) const;
    std::string convert_hundreds(int n) const;
public:
    std::string number_to_text(int n) const;
};


#endif //PROBLEM017_NUMBERSPELLER_H
