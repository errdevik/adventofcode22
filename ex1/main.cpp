#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string line;
    int current = 0;
    std::vector<int> calories;

    while (std::getline(std::cin, line))
    {
        if (line.length() == 0)
        {
            calories.push_back(current);
            current = 0;
        }
        current += std::atoi(line.c_str());
    }

    std::sort(calories.begin(), calories.end(), std::greater<int>());

    std::cout << "Soulution: " << calories[0] + calories[1] + calories[2] << "\n";

    return 0;
}