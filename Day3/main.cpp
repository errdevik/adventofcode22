#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
#include <assert.h>

#include <algorithm>

int get(int code)
{
    return (code > 90 ? code - 'a' + 1 : code - 'A' + 27);
}

int getPriority(const std::string &rucksuck)
{
    int len = rucksuck.length();
    std::set<char> halfsuck(rucksuck.begin(), rucksuck.begin() + (len / 2));

    for (int i = (len / 2); i < len; ++i)
    {
        if (halfsuck.count(rucksuck[i]))
        {
            return get(rucksuck[i]);
        }
    }
    throw std::runtime_error("bad length");
}

int getId(const std::vector<std::string> &v)
{
    std::vector<char> tmp;
    std::set_intersection(v[0].begin(), v[0].end(),
                          v[1].begin(), v[1].end(),
                          std::back_inserter(tmp));

    std::vector<char> result;
    std::set_intersection(tmp.begin(), tmp.end(),
                          v[2].begin(), v[2].end(),
                          std::back_inserter(result));

    assert(result.size() == 1);
    return get(*result.begin());
}

int main()
{
    std::string line;
    int result = 0;
    int result2 = 0;
    std::vector<std::string> group;

    while (std::getline(std::cin, line))
    {
        if (line.length() != 0)
        {
            result += getPriority(line);
            std::sort(line.begin(), line.end());
            group.push_back(line);
            if (group.size() == 3)
            {
                result2 += getId(group);
                group.clear();
            }
        }
    }
    std::cout << "Result1: " << result << "\n";
    std::cout << "Result2: " << result2 << "\n";
    return 0;
}