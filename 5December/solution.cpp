#include <bits/stdc++.h>
#include <vector>

//First solution
struct sol5{
    std::vector<std::array<int, 2>> rules;
    std::vector<std::vector<int>> orderings;
};

sol5 get_data5(){
    std::ifstream inFile("5December/input.txt");
    std::string line;
    sol5 data;
    bool parsingRules = true;

    if(inFile){
        while(getline(inFile, line, '\n')) {
            if (line.empty()) continue;
            if (parsingRules) {
                if (line.find(',') != std::string::npos) {
                    parsingRules = false;
                } else {
                    std::istringstream iss(line);
                    std::array<int, 2> rule;
                    char separator;
                    if (iss >> rule[0] >> separator >> rule[1] && separator == '|') {
                        data.rules.push_back(rule);
                    }
                }
            }
            if (!parsingRules) {
                std::vector<int> ordering;
                std::istringstream iss(line);
                int value;
                char separator;
                while (iss >> value) {
                    ordering.push_back(value);
                    iss >> separator;
                }
                data.orderings.push_back(ordering);
            }
        }
    }
    else{
        std::cout << "File not found" << std::endl;
    }

    return data;
}

bool check_ordering(std::vector<int> ordering, std::vector<std::array<int, 2>> rules){
    for(long unsigned int i = 0; i < ordering.size(); i++){
        for(auto rule : rules){
            if(rule[0] == ordering[i] && i > 0){
                for(long unsigned int j = (i - 1); j < i && j >= 0; j--){
                    if(ordering[j] == rule[1]){ 
                        return false;
                    }
                }
            }
        } 
    }
    return true;
}

int solution5(){
    int result = 0;
    sol5 data = get_data5();
    
    for(long unsigned int i = 0; i < data.orderings.size(); i++){
        if(check_ordering(data.orderings[i], data.rules)){
            result += data.orderings[i][data.orderings[i].size() / 2];
        }
    }

    return result;
}

//Second solution
bool check_ordering_reverse(std::vector<int> &ordering, std::vector<std::array<int, 2>> rules){
    for(long unsigned int i = 0; i < ordering.size(); i++){
        for(auto rule : rules){
            if(rule[0] == ordering[i] && i > 0){
                for(long unsigned int j = (i - 1); j < i && j >= 0; j--){
                    if(ordering[j] == rule[1]){ 
                        ordering[i] = rule[1];
                        ordering[j] = rule[0];
                        return true;
                    }
                }
            }
        } 
    }
    return false;
}

int second_solution5(){
    int result = 0;
    sol5 data = get_data5();
    
    for(long unsigned int i = 0; i < data.orderings.size(); i++){
        if(!check_ordering(data.orderings[i], data.rules)){
            while(check_ordering_reverse(data.orderings[i], data.rules)) continue;
            result += data.orderings[i][data.orderings[i].size() / 2];
        }
    }

    return result;
}
