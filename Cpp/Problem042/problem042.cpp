/* Project Euler
 * Problem 42: Coded triangle numbers
 * https://projecteuler.net/problem=42
 *
 * The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 * By converting each letter in a word to a number corresponding to its alphabetical position and adding these values
 * we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is
 * a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt, a 16K text file containing nearly two-thousand common English words, how many are triangle words?
 */

#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>

std::vector<std::string> read_words(const char *file_name);

bool is_triangle(std::string word);

int main() {

    auto words = read_words("words.txt");
    auto triangle_words = std::count_if(words.begin(), words.end(),
        [&] (auto word) {
            return is_triangle(std::move(word));
    });
    std::cout << triangle_words << std::endl;
    return 0;
}

bool is_triangle(std::string word) {

    auto number = std::accumulate(word.begin(), word.end(), 0,
[&](int acc, const char& c){
            return acc + c - 'A' + 1;
    });

    // check if it is a triangle number  (2* number = n*(n+1) for some natural n)
    auto sq = floor(sqrt(number * 2));
    return number * 2 == sq * (sq + 1);
}

std::vector<std::string> read_words(const char *file_name) {
    std::ifstream data(file_name);
    std::string line;
    std::vector<std::string> result;
    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<int> row;
        while(std::getline(lineStream,cell,','))
        {
            if (cell[0]=='"'){
                cell.erase(0,1);
            };
            if (cell[cell.length()-1] == '"') {
                cell.erase(cell.length()-1,1);
            }
            result.push_back(cell);
        }
    }
    return result;
}