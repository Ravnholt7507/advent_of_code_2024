#include <bits/stdc++.h>
#include <string>
#include <vector>

//First Solution
std::string get_data9(){
    std::ifstream file("9December/input.txt");

    if (!file.is_open()) {
        throw std::ios_base::failure("Failed to open the file.");
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    file.close();

    return content;
}

uint64_t solution9(){
    uint64_t result = 0;
    std::string data = get_data9();
    std::vector<std::string> converted_data{};
    
    bool block = true;
    int index = 0;
    for(char c : data){
        if(block){
            for(int i = 0; i < c - '0'; i++){
                converted_data.push_back(std::to_string(index));
            }
            index++;
            block = false;
        } else {
            for(int i = 0; i < c - '0'; i++){
                converted_data.push_back(".");
            }
            block = true;
        }
    }

    for(size_t i = converted_data.size() - 1; i > 0; i-- ){
        if(converted_data[i] == ".") continue;
        size_t index; 
        for(size_t j = 0; j < converted_data.size(); j++){
            if(converted_data[j] == "."){
                index = j;
                break;
            }
        }
        if(index >= i) break;
        converted_data[index] = converted_data[i];
        converted_data[i] = ".";
    }
    for(size_t i = 0; i < converted_data.size(); i++){
        if(converted_data[i] == ".") break;
        result += i * std::stoi(converted_data[i]);
    }

    return result;
}

uint64_t second_solution9(){
    uint64_t result = 0;
    std::string data = "2333133121414131402";
    //std::string data = get_data9();
    std::vector<std::vector<std::string>> converted_data{};
    
    bool block = true;
    int current_index = 0;
    std::vector<std::string> counter;
    for(char c : data){
        if(block){
            counter.clear();
            for(int i = 0; i < c - '0'; i++){
                counter.push_back(std::to_string(current_index));
            }
            converted_data.push_back(counter);
            current_index++;
            block = false;
        } else {
            counter.clear();
            for(int i = 0; i < c - '0'; i++){
                counter.push_back(".");
            }
            if(!counter.empty())converted_data.push_back(counter);
            block = true;
        }
    }
    for(auto& row : converted_data){
        for(auto& elem : row) std::cout << elem;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(size_t i = converted_data.size() - 1; i > 0; i--){
        if(converted_data[i][0] == "." ||converted_data[i][0] == "") continue;
        for(size_t j = 0; j < i; j++){
            if(converted_data[j][0] == "." && converted_data[j].size() >= converted_data[i].size()){
                int len = converted_data[j].size() - converted_data[i].size();
                std::swap(converted_data[i], converted_data[j]);
                if(len > 0){
                    converted_data.insert(converted_data.begin() + j + 1, std::vector<std::string>(len, ".")); 
                    converted_data[i].erase(converted_data[i].end() - len, converted_data[i].end());
                } 
                break;
            }
        }
    }

    for(auto& row : converted_data){
        for(auto& elem : row) std::cout << elem;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    size_t index = 0;
    for(size_t i = 0; i < converted_data.size(); i++){
        if(converted_data[i][0].find(".") != std::string::npos){
            for(size_t j = 0; j < converted_data[i].size(); j++){
                index++;
            }
        } 
        else{
            for(size_t j = 0; j < converted_data[i].size(); j++){
                result += index * std::stoi(converted_data[i][j]);
                index++;
            }
        }
    }

    return result;
}
