#include <bits/stdc++.h>
#include <regex>

//First solution
std::vector<std::string> get_data3(){
    std::ifstream inFile("3December/input.txt");
    std::string line;
    std::vector<std::string> data;

    if(inFile){
        while(getline(inFile, line, '\n')) {
            data.push_back(line);
        }
    }
    else{
        std::cout << "File not found" << std::endl;
    }

    return data;
}

int solution3(){
    int result = 0;
    std::regex str_to_match(R"(mul\((\d+),(\d+)\))");
    std::vector<std::string> data = get_data3();

    for(long unsigned int i = 0; i < data.size(); i++){
        std::smatch match{};
        auto begin = std::sregex_iterator(data[i].cbegin(), data[i].cend(), str_to_match);
        auto end = std::sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            match = *it;
            int num1 = std::stoi(match[1].str());
            int num2 = std::stoi(match[2].str());
            result += (num1 * num2);
        }
    }

    return result;
}

//Second solution
int second_solution3() {
    std::vector<std::string> data = get_data3();

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
