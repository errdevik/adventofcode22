#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// X -> Rock
// Y -> Paper
// Z -> Scissiros

// A -> Rock
// B -> Paper
// C -> Scissiros

std::unordered_map<char, char> wins = {
    {'X', 'Z'},
    {'Y', 'X'},
    {'Z', 'Y'},
};

std::unordered_map<char, char> lose = {
    {'Z', 'X'},
    {'X', 'Y'},
    {'Y', 'Z'},
};

std::unordered_map<char, char> encryption = {
    {'A', 'X'},
    {'B', 'Y'},
    {'C', 'Z'},
};

std::unordered_map<char, int> scores = {
    {'X', 1},
    {'Y', 2},
    {'Z', 3},
};

int playRoundPart1(char left, char right)
{
    char decLeft = encryption[left];
    int score = scores[right];

    if (wins[right] == decLeft) // Win
    {
        score += 6;
    }
    else if (wins[decLeft] == right) // Lose
    {
        score += 0;
    }
    else
    {
        score += 3;
    }

    return score;
}

int playRoundPart2(char left, char right)
{
    int score = 0;
    char decLeft = encryption[left];

    if (right == 'X') // Lose
    {
        score += scores[wins[decLeft]];
    }
    else if (right == 'Y') // Draw
    {
        score += scores[decLeft] + 3;
    }
    else if (right == 'Z') // Win
    {
        score += scores[lose[decLeft]] + 6;
    }

    return score;
}

int main()
{
    std::string line;
    int resultPart1 = 0;
    int resultPart2 = 0;

    while (std::getline(std::cin, line))
    {
        if (line.length() == 3)
        {
            char left = line[0];
            char right = line[2];
            resultPart1 += playRoundPart1(left, right);
            resultPart2 += playRoundPart2(left, right);
        }
    }
    std::cout << "Result 1: " << resultPart1 << "\n";
    std::cout << "Result 2: " << resultPart2 << "\n";

    return 0;
}