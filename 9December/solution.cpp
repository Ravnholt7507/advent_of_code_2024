#include <bits/stdc++.h>

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

//Second solution
//All Credit to topaz.github.io
//His full solution can be found at https://topaz.github.io/paste/#XQAAAQDsDAAAAAAAAAARmknGRw8TogB3OxrTBK4B/bN17W75Nu4TgcQ5V3D24il94B67UXf0M1F1lT/i6qIaysTKldl2HqGD9wEOymo7rBGMvSL4iGLsw+DzmndYtE8IE5wn739kdsk0iyeBxL4eI2LbmdeffuCTzR/INuatPiKVKkSM2cf4FBrc3vZwK8efvJx0wym8kmngV4EXYyhOFMmLgymevxrByhvWQ4AMIySLfdFsdkxdhlz3uCFIlPcYV7rMFK0qvDHoID20UeruwhQUhnTKmW1fLTdid2ERV0QHunYPhzkp1eIZjr+kbOkunqyvOywbgyZOym0x1r3zJe2Ksuek66m1kt1oxDvWjBWpniGqmrWEBZL0uK47HI82KD7GSq4ggcOhYLh+7ueOxBthJVfOPoUQbSZPxMdi7XkceVqs5QUj3FNgIAzcgfgeYo26V7sFuC4XyWlfff4KZ8RLNgQo1nHin8ZS0H1f2UdpNMKF6rFp45Od3R5upcmR9hVc1vRilIJgO6F1WIMHUe5LUMVRmEzRa5EPiyNTM0SWqQRLP2NIPw5ja20rOEPOrS6LgcfBeFYjcrnls40Tg2K+IhhBMchlpY9T4nGgd28KZST2ortxuR2YNdVXaIsYaZKPnurjyECnRY1C8LGpwBVh+zUkIxGjm//zj5d7J5rJ3qgaHZA73AwzuMf9oeCtDTUdzjpO3v+C40i1/Jh3goCOeAfElDI7mPT0+FaMNnvj2a+T1q36AwsfRZAeVawybI7+pthwB0QBcF9095Hezx7RXMMyrrzIHxljHbk+0zP7JA+J2HHh/2O+Nxhq6ebxEuG6SvdXR4lQNuqm3lfVRLIhLKKbygsQDs5ipcO1TrSp5feUVOtIm/BZr92W+E0QqAo6MXHxwWqc2JA+GKHsdQYOp4lw466/NbV7M1O28QsUnuy5V76kFeZnKYhj8k/YMe7n6DX5exVBLrqqMorE7bdXkFafE36C6Euqu3iyYDb7tr8Q7LqTC/MY4b+gMIfHHzP5KhakJEKdd8nF3pxK9EQBtkg/TWfd0gZqgdzNWOYe6WrcvyEM9kdg1rrJ+dv5El80W79tOLf3edjUE+rBiNc6dmob363SBaspqjIYCpGaffiUe5tLGp+xaVQ6zTg0QrNNf7Y2UiL5S7DEv81D/eWVcBgDJA+omhWCzjqIKTQng//cFC/P
unsigned long long int file_sum(int a, int n, int block_id){
    unsigned long long int s = (((2 * a) + n - 1) * n) / 2;
    return s * block_id;
}

uint64_t second_solution9(){
    std::ifstream input;
    input.open("9December/input.txt");
    if(input.is_open()){
        std::string line;
        std::getline(input, line);
        std::string cline = line;
        int n = line.size();
        int last_block_ptr = n % 2 == 0 ? n - 2 : n - 1;
        int ptr, block_id, block_ind;
        ptr = block_id = block_ind = 0;
        unsigned long long int result = 0;
        std::vector<std::queue<int>> files_by_size(10);
        std::unordered_map<int, char> moved;
        last_block_ptr = n % 2 == 0 ? n - 2 : n - 1;
        block_ind = 0;
        for(int i = last_block_ptr; i >= 0; i-=2){
            files_by_size[cline[i] - '0'].push(i);
        }
        for(ptr = 0; ptr < n; ){
            if(ptr % 2 == 0){
                if(moved.find(ptr) == moved.end()){
                    result += file_sum(block_ind, cline[ptr] - '0', ptr/2);
                    block_ind += (cline[ptr] - '0');
                } else {
                    block_ind += (moved[ptr] - '0');
                }
                ptr++;
            } else {
                int cur_space = cline[ptr] - '0';
                int max_ind = -1;
                int vec_ind = -1;
                for(int j = 1; j <= cur_space; j++){
                    std::queue<int>& temp = files_by_size[j];
                    if(!temp.empty() && (max_ind < temp.front()) && temp.front() > ptr){
                        max_ind = temp.front();
                        vec_ind = j;
                    }
                }
                if(max_ind == -1){
                    ptr++;
                    block_ind += cur_space;
                    continue;
                }

                cur_space = cline[max_ind] - '0';
                result += file_sum(block_ind, cur_space, max_ind/2);
                files_by_size[vec_ind].pop();

                moved[max_ind] = cline[max_ind];
                block_ind += cur_space;
                cline[max_ind] = '0';
                cline[ptr] -= cur_space;

                if(cline[ptr] == '0')
                    ptr++;
            }
        }
        return result;
    }
    return 0;
}
