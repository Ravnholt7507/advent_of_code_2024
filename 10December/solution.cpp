#include "solution.h"
using namespace std;

//First solution
vector<vector<int>> get_data10(){
    ifstream inFile("10December/input.txt");
    string line;
    vector<vector<int>> data;

    vector<int> tempVec;
    
    if(inFile){
        while(getline(inFile, line, '\n')) {
            for(char c : line){
                tempVec.push_back(c - '0');
            }
            data.push_back(tempVec);
            tempVec.clear();
        }
    }
    else{
        cout << "File not found" << endl;
    }

    return data;
}

void recursive_check(vector<vector<int>> &data, long unsigned int i, long unsigned int j, int last_num, int result, set<pair<int, int>> &already_found){
    if(data[i][j] == 9){
        already_found.insert(pair<int, int>(i, j));
    }
    if(j+1 < data[i].size() && data[i][j+1] == last_num + 1) recursive_check(data, i, j+1, data[i][j+1], result, already_found); 
    if(j > 0 && data[i][j-1] == last_num + 1) recursive_check(data, i, j-1, data[i][j-1], result, already_found); 
    if(i+1 < data.size() && data[i+1][j] == last_num + 1) recursive_check(data, i+1, j, data[i+1][j], result, already_found); 
    if(i > 0 && data[i-1][j] == last_num + 1) recursive_check(data, i-1, j, data[i-1][j], result, already_found); 
}

int check_trail(vector<vector<int>> &data, long unsigned int i, long unsigned int j){
    set<pair<int, int>> already_found;
    recursive_check(data, i, j, data[i][j], 0, already_found);
    return already_found.size();
}


int solution10(){
    int result = 0;
    vector<vector<int>> data = get_data10(); 
    
    for(long unsigned int i = 0; i < data.size(); i++){
        for(long unsigned int j = 0; j < data[i].size(); j++){
            if(data[i][j] == 0) result += check_trail(data, i, j);
        }
    }


    return result;
}


//Second solution

void recursive_check2(vector<vector<int>> &data, long unsigned int i, long unsigned int j, int last_num, int result, set<vector<pair<int, int>>> &already_found, vector<pair<int, int>> route){
    route.push_back(pair(i,j));
    if(data[i][j] == 9){
        already_found.insert(route);
    }
    if(j+1 < data[i].size() && data[i][j+1] == last_num + 1) recursive_check2(data, i, j+1, data[i][j+1], result, already_found, route); 
    if(j > 0 && data[i][j-1] == last_num + 1) recursive_check2(data, i, j-1, data[i][j-1], result, already_found, route); 
    if(i+1 < data.size() && data[i+1][j] == last_num + 1) recursive_check2(data, i+1, j, data[i+1][j], result, already_found, route); 
    if(i > 0 && data[i-1][j] == last_num + 1) recursive_check2(data, i-1, j, data[i-1][j], result, already_found, route); 
}

int check_trail2(vector<vector<int>> &data, long unsigned int i, long unsigned int j){
    set<vector<pair<int, int>>> already_found;
    vector<pair<int, int>> route{pair(i, j)};
    recursive_check2(data, i, j, data[i][j], 0, already_found, route);
    return already_found.size();
}

int second_solution10(){
    int result = 0;
    vector<vector<int>> data = get_data10(); 
    
    for(long unsigned int i = 0; i < data.size(); i++){
        for(long unsigned int j = 0; j < data[i].size(); j++){
            if(data[i][j] == 0) result += check_trail2(data, i, j);
        }
    }


    return result;
}
