//
// Created by Victor on 15.10.2019.
//

#ifndef PROBLEM017_NUMBERSPELLER_H
#define PROBLEM017_NUMBERSPELLER_H

#include <string>

class NumberSpeller {
public:
    std::string NumberToText(int n) const;
    std::string convert1to20(int n) const;
    std::string convertTens(int n) const;
    std::string convertHundreds(int n) const;
};


#endif //PROBLEM017_NUMBERSPELLER_H
