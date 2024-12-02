
#include "first_solution.h"
#include <vector>

std::vector<std::vector<int>> get_data(){
    std::ifstream inFile("2December/first_input.txt");
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

int solution(){
    int result = 0;
    std::vector<std::vector<int>> data = get_data();

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
