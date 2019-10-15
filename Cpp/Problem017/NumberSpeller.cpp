//
// Created by Victor on 15.10.2019.
//

#include "NumberSpeller.h"

std::string NumberSpeller::NumberToText(int n) const {

    std::string result;
    if (n < 20) {
        result = convert1to20(n);
    }
    else if (n < 100)
    {
        result = convertTens((n / 10)*10);
        if (n % 10)
        {
            result += "-" + NumberToText(n % 10);
        }
    }
    else if (n < 1000)
    {
        result = convertHundreds((n / 100)*100);
        if ( n % 100)
        {
            result + " and " + NumberToText(n % 100);
        }
    }
    else {
        result = "Not supported yet";
    }
    return result;
}

std::string NumberSpeller::convert1to20(int n) const {
    switch (n) {
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eighteen";
        case 19:
            return "nineteen";
        default:
            return "";
    }
}

std::string NumberSpeller::convertTens(int n) const {
    switch (n)
    {
        case 20:
            return "twenty";
        case 30:
            return "thirty";
        case 40:
            return "forty";
        case 50:
            return "fifty";
        case 60:
            return "sixty";
        case 70:
            return "seventy";
        case 80:
            return "eighty";
        case 90:
            return "ninety";
        default: return "";
    }
}

std::string NumberSpeller::convertHundreds(int n) const {
    auto hundreds = n / 100;
    return NumberToText(hundreds) + " hundred";
}
