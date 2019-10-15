//
// Created by Victor on 15.10.2019.
//

#include "NumberSpellerTests.h"
#include "NumberSpeller.h"
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

NumberSpeller speller;

TEST_CASE( "Single digit numbers are translated properly", "[single]") {
    REQUIRE( speller.NumberToText(1) == "one");
    REQUIRE( speller.NumberToText(2) == "two");
    REQUIRE( speller.NumberToText(3) == "three");
    REQUIRE( speller.NumberToText(4) == "four");
    REQUIRE( speller.NumberToText(5) == "five");
    REQUIRE( speller.NumberToText(6) == "six");
}

TEST_CASE( "Two digits numbers are translated properly", "[twodigit]") {
    REQUIRE( speller.NumberToText(12) == "twelve");
    REQUIRE( speller.NumberToText(30) == "thirty");
    REQUIRE( speller.NumberToText(42) == "forty-two");
    REQUIRE( speller.NumberToText(33) == "thirty-three");
    REQUIRE( speller.NumberToText(98) == "ninety-eight");
}

TEST_CASE( "Three digits numbers are translated properly", "[threedigit]") {
    REQUIRE( speller.NumberToText(100) == "one hundred");
    REQUIRE( speller.NumberToText(200) == "two hundred");
    REQUIRE( speller.NumberToText(342) == "three hundred and forty-two");
}