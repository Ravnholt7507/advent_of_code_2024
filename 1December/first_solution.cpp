#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "first_solution.h"


bool comparator(int first, int second){
    return first <= second;
}

file_output get_data(){
    std::ifstream inFile("1December/first_input.txt");
    std::string line;
    int num;
    file_output data;

    std::vector<int> tempVec;
    
    if(inFile){
        while(getline(inFile, line, '\n')) {
            std::istringstream ss(line); 

            while(ss >> num){
                tempVec.push_back(num);
            }
            data.first.push_back(tempVec[0]);
            data.second.push_back(tempVec[1]);
            tempVec.clear();
        }
    }
    else{
        std::cout << "File not found" << std::endl;
    }

    return data;
}

int solution(){
    file_output data = get_data();

    std::vector<int> first_list = data.first;
    std::vector<int> second_list= data.second;

    int result = 0;
    
    //sort lists
    sort(first_list.begin(), first_list.end(), comparator);
    sort(second_list.begin(), second_list.end(), comparator);

    for(long unsigned int i = 0; i < first_list.size(); i++){
        if(first_list[i] < second_list[i]){
            result += (second_list[i] - first_list[i]);
        }
        else if (first_list[i] > second_list[i]){
            result += (first_list[i] - second_list[i]);
        }
    }

    return result;
}
