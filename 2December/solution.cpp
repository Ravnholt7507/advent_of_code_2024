#include "solution.h"
#include <vector>

//First solution
std::vector<std::vector<int>> get_data2(){
    std::ifstream inFile("2December/input.txt");
    std::string line;
    int num;
    std::vector<std::vector<int>> data;

    std::vector<int> tempVec;
    
    if(inFile){
        while(getline(inFile, line, '\n')) {
            std::istringstream ss(line); 

            while(ss >> num){
                tempVec.push_back(num);
            }
            data.push_back(tempVec);
            tempVec.clear();
        }
    }
    else{
        std::cout << "File not found" << std::endl;
    }

    return data;
}

int solution2(){
    int result = 0;
    std::vector<std::vector<int>> data = get_data2();

    bool failed; 
    for(long unsigned int i = 0; i < data.size(); i++){
       failed = false;
       if(data[i][0] < data[i][1]){
           for(long unsigned int j = 0; j < data[i].size() - 1; j++){
               if(!(data[i][j] < data[i][j+1] && (data[i][j+1] - data[i][j]) >= 1 && (data[i][j+1] - data[i][j]) <= 3)){
                   failed = true;
               } 
           }
       }
       else if(data[i][0] > data[i][1]){
            for(long unsigned int j = 0; j < data[i].size() - 1; j++){
               if(!(data[i][j] > data[i][j+1] && (data[i][j] - data[i][j+1]) >= 1 && (data[i][j] - data[i][j+1]) <= 3)){
                   failed = true;
               } 
            } 
       }
       else{
            failed = true;
       }
       if(!failed){
            result++;
       }
    }    

    return result;
}

//Second solution
bool is_safe(const std::vector<int>& levels) {
    if (levels.size() < 2) return true;

    bool increasing = levels[0] < levels[1];
    for (size_t i = 0; i < levels.size() - 1; ++i) {
        int diff = std::abs(levels[i + 1] - levels[i]);
        if ((increasing && !(levels[i] < levels[i + 1])) ||
            (!increasing && !(levels[i] > levels[i + 1])) ||
            (diff < 1 || diff > 3)) {
            return false; 
        }
    }
    return true;
}

int second_solution2() {
    int result = 0;
    std::vector<std::vector<int>> data = get_data2();  

    for (const auto& levels : data) {
        if (is_safe(levels)) {
            result++;
        } else {
            bool dampened_safe = false;
            for (size_t i = 0; i < levels.size(); ++i) {
                std::vector<int> modified_levels = levels;
                modified_levels.erase(modified_levels.begin() + i);
                if (is_safe(modified_levels)) {
                    dampened_safe = true;
                    break;
                }
            }
            if (dampened_safe) result++;
        }
    }

    return result;
}
