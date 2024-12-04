#include "first_solution.h"
#include <vector>

int second_solution() {
    int result = 0;
    std::vector<std::string> data = get_data();
    for (long unsigned int i = 0; i < data.size(); i++) {
        for (long unsigned int j = 0; j < data[i].length(); j++) {
            // Check down right 
            if ((data.size() - i) >= 2 && (data[i].length() - j) >= 2 &&
                ((data[i][j] == 'M' && data[i+1][j+1] == 'A' && data[i+2][j+2] == 'S') ||
                 (data[i][j] == 'S' && data[i+1][j+1] == 'A' && data[i+2][j+2] == 'M'))) {
                // Check down left (if right is found)
                if ((data.size() - i) >= 2 && 
                    ((data[i][j+2] == 'M' && data[i+1][j+1] == 'A' && data[i+2][j] == 'S') ||
                     (data[i][j+2] == 'S' && data[i+1][j+1] == 'A' && data[i+2][j] == 'M'))) {
                    result++;
                }
            }
        }
    }
    return result;
}

