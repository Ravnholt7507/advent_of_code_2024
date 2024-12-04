#include <bits/stdc++.h>

std::vector<std::string> get_data(){
    std::ifstream inFile("4December/first_input.txt");
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

int solution(){
    int result = 0;
    std::vector<std::string> data = get_data();
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
