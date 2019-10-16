/*
 * Project Euler
 * Problem 67: Maximum path sum II
 *
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt, a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem,
as there are 2^99 altogether! If you could check one trillion (10^12) routes every second it would take over twenty
billion years to check them all. There is an efficient algorithm to solve it. ;o)

 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<std::vector<int>> read_data(const char *file_name);

int main() {
    std::vector<std::vector<int>> numbers = read_data("p067_triangle.txt");

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