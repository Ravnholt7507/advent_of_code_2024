#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "solution.h"

struct file_output{
    std::vector<int> first;
    std::vector<int> second;
};

bool comparator(int first, int second){
    return first <= second;
}

file_output get_data1(){
    std::ifstream inFile("1December/input.txt");
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

int solution1(){
    file_output data = get_data1();

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

int second_solution1(){
    file_output data = get_data1();
    std::vector<int> first_list = data.first;
    std::vector<int> second_list = data.second;
    
    int result = 0;

    //Gonna bruteforce this due to time constraints
    int counter;
    for(long unsigned int i = 0; i < first_list.size(); i++){ 
        counter = 0; 
        for(long unsigned int j = 0; j < first_list.size(); j++){
            if(first_list[i] == second_list[j]){
                counter++;
            } 
        }
        result += (first_list[i] * counter);
    }

    return result;
}
