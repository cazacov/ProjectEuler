/* ProjectEuler
 * Problem 22: Names scores
 *
 * Using names.txt, a 46K text file containing over five-thousand first names, begin by sorting it into
 * alphabetical order. Then working out the alphabetical value for each name, multiply this value by its
 * alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
 * is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 * What is the total of all the name scores in the file?
 */

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


std::vector<std::string> read_data(const char *file_name);

int word_score(std::basic_string<char> &word);

int main() {

    auto strings = read_data("p022_names.txt");
    std::sort(strings.begin(), strings.end());

    int score = 0;
    for (int i = 0; i < strings.size(); i++) {
        score += (i + 1) * word_score(strings[i]);
    }
    std::cout << score<< std::endl;
    return 0;
}

int word_score(std::string &word) {
    int result = 0;
    for (char& ch: word) {
        result += ch - 'A' + 1;
    }
    return result;
}

std::vector<std::string> read_data(const char *file_name) {
    std::ifstream  data(file_name);
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