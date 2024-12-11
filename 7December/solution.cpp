#include <bits/stdc++.h>

//First solution
using namespace std;
std::vector<std::vector<uint64_t>> get_data7() {
    std::vector<std::vector<uint64_t>> result;
    std::ifstream file("7December/input.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open the file");
    }

    std::string line;
    while (std::getline(file, line, '\n')) {
        std::istringstream stream(line);
        std::vector<uint64_t> row;

        uint64_t key;
        char colon;
        stream >> key >> colon;
        if (colon != ':') {
            throw std::runtime_error("Invalid format in file");
        }
        row.push_back(key); 

        int value;
        while (stream >> value) {
            row.push_back(value); 
        }

        if(row.size() > 1) result.push_back(row);
    }

    file.close();
    return result;
}

bool recursive_check(const vector<uint64_t>& data, uint64_t goal, uint64_t akkum, size_t index) {
    if (index >= data.size()) {
        return akkum == goal; 
    }

    uint64_t current = data[index];

    return recursive_check(data, goal, akkum + current, index + 1) ||
           recursive_check(data, goal, akkum * current, index + 1);
}

bool check_solution(const vector<uint64_t>& data, uint64_t goal) {
    uint64_t akkum = data[0];
    return recursive_check(data, goal, akkum, 1);
}

uint64_t solution7(){
    uint64_t result = 0;
//    vector<vector<int>> data = {{190, 10, 19},
//                                {3267, 81, 40, 27},
//                                {83, 17, 5},
//                                {156, 15, 6},
//                                {7290, 6, 8, 6, 15},
//                                {161011, 16, 10, 13},
//                                {192, 17, 8, 14},
//                                {21037, 9, 7, 18, 13},
//                                {292, 11, 6, 16, 20}};
    vector<vector<uint64_t>> data = get_data7();
    int counter = 0; 
    for(auto& i : data){
        if (i.empty()) continue;
        uint64_t goal = i[0];
        vector<uint64_t> numbers(i.begin() + 1, i.end());
        if(check_solution(numbers, goal)){ result += goal;
            counter++;
        }
    }
    return result;
}
