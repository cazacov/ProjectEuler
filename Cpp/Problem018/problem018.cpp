/*
 * Project Euler
 * Problem 18: Maximum path sum I
 *
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<std::vector<int>> read_data(const char *file_name);

int main() {
    std::vector<std::vector<int>> numbers = read_data("data.txt");

    // replace every element with a sum of the element itself and its max adjacent number from the row below

    for (int row = numbers.size() - 2; row >= 0; row--)
    {
        for (int i = 0; i < numbers[row].size(); i++)
        {
            auto elem = numbers[row][i];
            auto elem_below = numbers[row+1][i];
            auto elem_below_right = numbers[row+1][i+1];

            numbers[row][i] = elem + std::max(elem_below, elem_below_right);
        }
    }

    // After applying this transformation to all rows the top element will be the maximum of all path totals
    std::cout << numbers[0][0] << std::endl;
    return 0;
}

std::vector<std::vector<int>> read_data(const char *file_name) {
    std::ifstream  data(file_name);
    std::string line;
    std::vector<std::vector<int> > result;
    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<int> row;
        while(std::getline(lineStream,cell,' '))
        {
            row.push_back(std::stoi(cell));
        }
        result.push_back(row);
    }
    return result;
}
