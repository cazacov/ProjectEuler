//
// Created by Victor on 14.11.2019.
//

#include "PokerRules.h"
#include <algorithm>
#include <map>

enum Rank {
    HighCard,
    OnePair,
    TwoPairs,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush
};



struct Card {
    short score;
    char suit;
    Card(std::string card) {
        suit = card[1];

        switch (card[0]) {
            case 'T':
                score = 10;
                break;
            case 'J':
                score = 11;
                break;
            case 'Q':
                score = 12;
                break;
            case 'K':
                score = 13;
                break;
            case 'A':
                score = 14;
                break;
            default:
                score = card[0] - '0';
        }
    }
};
struct RankResult {
    Rank rank;
    short rank_value;
    std::vector<Card> cards;
};


RankResult calculate_rank(std::vector<std::string> hand) {

    RankResult result;
    result.rank = HighCard;
    result.rank_value = 0;

    std::map<int, int> score_map;
    for (int i = 0; i <= 14; i++) {
        score_map[i] = 0;
    }

    for (Card card : hand) {
        result.cards.push_back(card);
        score_map[card.score] += 1;
    }
    std::sort(result.cards.begin(), result.cards.end(), [](const Card &lhs, const Card &rhs) {
        return lhs.score > rhs.score;
    });

    bool hasTwo = false;
    bool hasThree = false;

    for (auto &score: score_map) {
        if (score.second == 2) {
            hasTwo = true;
            if (result.rank < OnePair) {
                result.rank = OnePair;
                if (result.rank_value < score.first) {
                    result.rank_value = score.first;
                }
            }
        }
        if (score.second == 3) {
            hasThree = true;
            if (result.rank < ThreeOfAKind) {
                result.rank = ThreeOfAKind;
                result.rank_value = score.first;
            }
        }
        if (score.second == 4 && result.rank < FourOfAKind) {
            result.rank = FourOfAKind;
            result.rank_value = score.first;
        }
    }

    if (hasTwo && hasThree && result.rank < FullHouse) {
        result.rank = FullHouse;
    }

    if (result.rank < TwoPairs) {
        if (std::count_if(score_map.begin(), score_map.end(), [](const auto &score) {
            return score.second == 2;
        }) == 2) {
            result.rank = TwoPairs;
        }
    }

    if (result.rank < Straight) {
        int sc = result.cards[0].score;
        int i;
        for (i = 0; i < 5; i++) {
            if (result.cards[i].score != sc--) {
                break;
            }
        }
        if (i == 5) {
            result.rank = Straight;
            result.rank_value = result.cards[0].score;
        }
    }

    auto suit = result.cards[0].suit;
    if (result.rank < Flush) {
        if (std::all_of(result.cards.begin(), result.cards.end(), [suit](const Card &card) {
            return card.suit == suit;
        })) {
            if (result.rank == Straight) {
                result.rank = StraightFlush;
            }
            else if (result.rank < Flush){
                result.rank = Flush;
                result.rank_value = result.cards[0].score;
            }
        }
    }

    if (result.rank == StraightFlush && result.cards[0].score == 14) {
        result.rank = RoyalFlush;
    }
    return result;
}


bool PokerRules::is_first_winner(const std::vector<std::string> &hand1, const std::vector<std::string> &hand2) {

    auto rankOne = calculate_rank(hand1);
    auto rankTwo = calculate_rank(hand2);

    if (rankOne.rank != rankTwo.rank) {
        return rankOne.rank > rankTwo.rank;
    }
    else if (rankOne.rank_value != rankTwo.rank_value) {
        return rankOne.rank_value > rankTwo.rank_value;
    }
    else {
        for (int i = 0; i < 5; i++) {
            if (rankOne.cards[i].score != rankTwo.cards[i].score) {
                return rankOne.cards[i].score > rankTwo.cards[i].score;
            }
        }
    }
    return true;
}
