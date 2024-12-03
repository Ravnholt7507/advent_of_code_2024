#include <bits/stdc++.h>
#include <regex>

std::vector<std::string> get_data(){
    std::ifstream inFile("3December/first_input.txt");
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

int solution(){
    int result = 0;
    std::regex str_to_match(R"(mul\((\d+),(\d+)\))");
    std::vector<std::string> data = get_data();

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

