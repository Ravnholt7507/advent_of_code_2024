#include <bits/stdc++.h>

using namespace std;

//First solution
int recursive_check(vector<vector<int>> &data, long unsigned int i, long unsigned int j, int last_num, int result){
    cout << i << " " << j << "Max is " << data.size() << " and " << data[i].size()<< endl;
    if(data[i][j] == 9) return 1;
    if(j+1 < data[i].size() && data[i][j+1] == last_num + 1)result += recursive_check(data, i, j+1, data[i][j+1], result); 
    if(j-1 > 0 && data[i][j-1] == last_num + 1) result += recursive_check(data, i, j-1, data[i][j-1], result); 
    if(i+1 < data.size() && data[i+1][j] == last_num + 1) result += recursive_check(data, i+1, j, data[i+1][j], result); 
    if(i-1 >  0 && data[i-1][j] == last_num + 1) result += recursive_check(data, i-1, j, data[i-1][j], result); 
    return result;
}

int check_trail(vector<vector<int>> &data, long unsigned int i, long unsigned int j){
    int result = recursive_check(data, i, j, data[i][j], 0);
    return result;
}


int solution10(){
    int result = 0;
    vector<vector<int>> data = {{8, 9, 0, 1, 0, 1, 2, 3},
                                {7, 8, 1, 2, 1, 8, 7, 4},
                                {8, 7, 4, 3, 0, 9, 6, 5},
                                {9, 6, 5, 4, 9, 8, 7, 4},
                                {4, 5, 6, 7, 8, 9, 0, 3},
                                {3, 2, 0, 1, 9, 0, 1, 2},
                                {0, 1, 3, 2, 9, 8, 0, 1},
                                {1, 0, 4, 5, 6, 7, 3, 2}};
    for(long unsigned int i = 0; i < data.size(); i++){
        for(long unsigned int j = 0; j < data[i].size(); j++){
            if(data[i][j] == 0) result += check_trail(data, i, j);
        }
    }


    return result;
}


//Second solution
int second_solution10(){
    int result = 0;

    return result;
}
