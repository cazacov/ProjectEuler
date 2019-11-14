/* Project Euler
 * Problem 54: Poker hands
 *
 * In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
 *
 * High Card: Highest value card.
 * One Pair: Two cards of the same value.
 * Two Pairs: Two different pairs.
 * Three of a Kind: Three cards of the same value.
 * Straight: All cards are consecutive values.
 * Flush: All cards of the same suit.
 * Full House: Three of a kind and a pair.
 * Four of a Kind: Four cards of the same value.
 * Straight Flush: All cards are consecutive values of same suit.
 * Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
 *
 * The cards are valued in the order:
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
 *
 * If two players have the same ranked hands then the rank made up of the highest value wins; for example,
 * a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example,
 * both players have a pair of queens, then highest cards in each hand are compared (see example 4 below);
 * if the highest cards tie then the next highest cards are compared, and so on.
 *
 * The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains
 * ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards.
 * You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no
 * specific order, and in each hand there is a clear winner. How many hands does Player 1 win?
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "PokerRules.h"

std::vector<std::vector<std::vector<std::string>>> read_data(const char *file_name);

int main() {

    int wins = 0;
    for (auto game: read_data("poker.txt")) {
        if (PokerRules::is_first_winner(game[0], game[1])) {
            wins++;
        }
    }

    std::cout << wins << std::endl;
    return 0;
}



std::vector<std::vector<std::vector<std::string>>> read_data(const char *file_name) {
    std::vector<std::vector<std::vector<std::string>>> result;

    std::ifstream  data(file_name);
    std::string line;
    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::vector<std::string>> game;
        std::vector<std::string> hand;
        int n = 0;
        while(std::getline(lineStream, cell,' '))
        {
            hand.push_back(cell);
            n++;
            if (n == 5) {
                game.push_back(hand);
                n=0;
                hand.clear();
            }
        }
        result.push_back(game);
    }
    return result;
}
