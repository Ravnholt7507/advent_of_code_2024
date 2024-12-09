#include "solution.h"

//First solution
std::vector<std::string> get_data4(){
    std::ifstream inFile("4December/input.txt");
    std::string line;
    std::vector<std::string> data;

    if(inFile){
        while(getline(inFile, line, '\n')) {
            data.push_back(line);
        }
    }
    else{
        std::cout << "File not found" << std::endl;
    }

    return data;
}

int solution4(){
    int result = 0;
    std::vector<std::string> data = get_data4();
    std::string row;
    for(long unsigned int i = 0; i < data.size(); i++){
        row = data[i];
        for(long unsigned int j = 0; j < row.length(); j++){
            //check right
            if((row.length()-j) > 3 && row[j] == 'X' && row[j+1] == 'M' && row[j+2] == 'A' && row[j+3] == 'S'){
                result++;
            } 
            //check reverse right
            if((row.length()-j) > 3 && row[j] == 'S' && row[j+1] == 'A' && row[j+2] == 'M' && row[j+3] == 'X'){
                result++;
            }
            //check down
            if((data.size()-i) > 3 && row[j] == 'X' && data[i+1][j] == 'M' && data[i+2][j] == 'A' && data[i+3][j] == 'S'){
                result ++;
            }
            //check reverse down
            if((data.size()-i) > 3 && row[j] == 'S' && data[i+1][j] == 'A' && data[i+2][j] == 'M' && data[i+3][j] == 'X'){
                result ++;
            }
            //check down right
            if((row.length()-j) > 3 && (data.size()-i) > 3 && row[j] == 'X' && data[i+1][j+1] == 'M' && data[i+2][j+2] == 'A' && data[i+3][j+3] == 'S'){
                result ++;
            }
            //Check reverse down right
            if((row.length()-j) > 3 && (data.size()-i) > 3 && row[j] == 'S' && data[i+1][j+1] == 'A' && data[i+2][j+2] == 'M' && data[i+3][j+3] == 'X'){
                result ++;
            }
            //check down left
            if((data.size()-i) > 3 && j >= 3 && row[j] == 'X' && data[i+1][j-1] == 'M' && data[i+2][j-2] == 'A' && data[i+3][j-3] == 'S'){
                result ++;
            }
            //check reverse down left
            if((data.size()-i) > 3 && j >= 3 && row[j] == 'S' && data[i+1][j-1] == 'A' && data[i+2][j-2] == 'M' && data[i+3][j-3] == 'X'){
                result ++;
            }
        }
    }
    
    return result;
}

//Second solution
int second_solution4() {
    int result = 0;
    std::vector<std::string> data = get_data4();
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
