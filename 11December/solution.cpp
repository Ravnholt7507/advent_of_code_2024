#include "solution.h"

using namespace std;
//First Solution
void blink(vector<long long> &data);

int solution11(){
    int num_blinks{25};
    vector<long long> data{4610211, 4, 0, 59, 3907, 201586, 929, 33750};    

    for(int i = 0; i < num_blinks; i++){
        blink(data);
    }

    return data.size();
}

void blink(vector<long long> &data){
    for(size_t i = 0; i < data.size(); i++) {
        string intasstring = to_string(data[i]);

        if(data[i] == 0){
            data[i] = 1;
        } else if((intasstring.length() % 2) == 0){
            string first_part = intasstring.substr(0, (intasstring.length() / 2));  
            string second_part = intasstring.substr(intasstring.length() / 2);  
            data[i] = stoll(first_part);
            data.insert(data.begin() + i + 1, stoll(second_part));
            i++;
        } else {
            data[i] = data[i] * 2024;
        } 
    }
}

//Second Solution
unsigned long long second_solution11(){

        vector<unsigned long long> data{4610211, 4, 0, 59, 3907, 201586, 929, 33750};    

        unordered_map<unsigned long long, unsigned long long> stones;

        for(auto num : data)
        {
            stones[(unsigned long long)num] = 1;
        }

        for (int i = 0; i < 75; ++i)
        {
            unordered_map<unsigned long long, unsigned long long> tmp;
            for (auto pair : stones) {
                unsigned long long stone = pair.first;
                unsigned long long count = pair.second;
                if (stone == 0)
                {
                    tmp[1] += count;
                }
                else if (to_string(stone).length() % 2 == 0)
                {
                    string stone_to_str = to_string(stone);
                    int n = stone_to_str.length();
                    unsigned long long left = stoull(stone_to_str.substr(0, n / 2));
                    unsigned long long right = stoull(stone_to_str.substr(n / 2, n / 2));
                    tmp[left] += count;
                    tmp[right] += count;
                } else {
                    tmp[stone * 2024] += count;
                }
            }
            stones = tmp;
        }

        unsigned long long result = 0;
        for (auto pair : stones) {
            result += pair.second;
        }
        return result;
}
