#include <bits/stdc++.h>

//First solution

using namespace std;
std::vector<std::vector<int>> get_data7() {
    std::vector<std::vector<int>> result;
    std::ifstream file("7December/input.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open the file");
    }

    std::string line;
    while (std::getline(file, line, '\n')) {
        std::istringstream stream(line);
        std::vector<int> row;

        int key;
        char colon;
        stream >> key >> colon;  // Read the key and the colon.
        if (colon != ':') {
            throw std::runtime_error("Invalid format in file");
        }
        row.push_back(key); // First value (key) is stored.

        int value;
        while (stream >> value) {
            row.push_back(value); // Append values.
        }

        if(row.size() > 1) result.push_back(row);
    }

    file.close();
    return result;
}

bool recursive_check(vector<int> data, size_t goal, size_t akkum){
    if(data.size() < 2){
        if(data[0] + akkum == goal) return true;
        else if(data[0] * akkum == goal) return true; 
        else return false;
    }
    else{
        size_t current = data[0];
        data.erase(data.begin());
        if(recursive_check(data, goal, (akkum + current))) return true;
        else if(recursive_check(data, goal, (akkum * current))) return true;
        else return false;
    }

}

bool check_solution(vector<int> data, size_t goal){
    return recursive_check(data, goal, 0);
}

int solution7(){
    long long int result = 0;
//    vector<vector<int>> data = {{190, 10, 19},
//                                {3267, 81, 40, 27},
//                                {83, 17, 5},
//                                {156, 15, 6},
//                                {7290, 6, 8, 6, 15},
//                                {161011, 16, 10, 13},
//                                {192, 17, 8, 14},
//                                {21037, 9, 7, 18, 13},
//                                {292, 11, 6, 16, 20}};
    vector<vector<int>> data = get_data7();
    
    for(auto i : data){
        size_t goal = i[0];
        i.erase(i.begin());
        if(check_solution(i, goal)) result += goal;
    }
    return result;
}
