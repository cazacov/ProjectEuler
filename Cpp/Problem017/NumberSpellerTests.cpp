//
// Created by Victor on 15.10.2019.
//

#include "NumberSpellerTests.h"
#include "NumberSpeller.h"
#define CATCH_CONFIG_MAIN

#include "catch.hpp"

NumberSpeller speller;

TEST_CASE( "Single digit numbers are translated properly", "[single]") {
    REQUIRE(speller.number_to_text(1) == "one");
    REQUIRE(speller.number_to_text(2) == "two");
    REQUIRE(speller.number_to_text(3) == "three");
    REQUIRE(speller.number_to_text(4) == "four");
    REQUIRE(speller.number_to_text(5) == "five");
    REQUIRE(speller.number_to_text(6) == "six");
}

TEST_CASE( "Two digits numbers are translated properly", "[twodigit]") {
    REQUIRE(speller.number_to_text(12) == "twelve");
    REQUIRE(speller.number_to_text(30) == "thirty");
    REQUIRE(speller.number_to_text(42) == "forty-two");
    REQUIRE(speller.number_to_text(33) == "thirty-three");
    REQUIRE(speller.number_to_text(98) == "ninety-eight");
}

TEST_CASE( "Three digits numbers are translated properly", "[threedigit]") {
    REQUIRE(speller.number_to_text(100) == "one hundred");
    REQUIRE(speller.number_to_text(200) == "two hundred");
    REQUIRE(speller.number_to_text(342) == "three hundred and forty-two");
}

TEST_CASE( "Four digits numbers are translated properly", "[fourdigit]") {
    REQUIRE(speller.number_to_text(1000) == "one thousand");
    REQUIRE(speller.number_to_text(2000) == "two thousand");
    REQUIRE(speller.number_to_text(2019) == "two thousand nineteen");
}