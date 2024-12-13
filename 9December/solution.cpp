#include <bits/stdc++.h>
#include <string>

//First Solution
std::string get_data9(){
    // Create an input file stream
    std::ifstream file("9December/input.txt");

    // Check if the file is open
    if (!file.is_open()) {
        throw std::ios_base::failure("Failed to open the file.");
    }

    // Read the file content into a string
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Close the file
    file.close();

    return content;
}

uint64_t solution9(){
    uint64_t result = 0;
    //std::string data = "2333133121414131402";
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
        //std::cout<< i * (converted_data[i] - '0') << std::endl;
        result += i * std::stoi(converted_data[i]);
    }

    return result;
}

int second_solution9(){
    int result = 0;

    return result;
}
