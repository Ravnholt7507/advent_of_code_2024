#include "first_solution.h"
#include <vector>

int second_solution() {
    std::vector<std::string> data = get_data();

    std::regex str_to_match(R"(do\(\)|don't\(\)|mul\((\d+),(\d+)\))");

    bool mul_enabled = true;
    int result = 0;

    for(long unsigned int i = 0; i < data.size(); i++){
        std::smatch match{};
        auto begin = std::sregex_iterator(data[i].begin(), data[i].end(), str_to_match);
        auto end = std::sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            match = *it;

            if (match.str() == "do()") {
                mul_enabled = true; 
            } else if (match.str() == "don't()") {
                mul_enabled = false; 
            } else if (mul_enabled && match.size() == 3) { 
                int num1 = std::stoi(match[1].str());
                int num2 = std::stoi(match[2].str());
                result += (num1 * num2);
            } 
        }
    }

    return result;
}
