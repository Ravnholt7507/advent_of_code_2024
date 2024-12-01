#include <vector>

#include "first_solution.h"

int second_solution(){
    file_output data = get_data();
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
