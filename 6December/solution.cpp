#include <bits/stdc++.h>
#include <vector>

//First solution
int counter(std::vector<std::string> data){
    int result = 0;
    for(size_t i = 0; i < data.size(); i++){
        for(size_t j = 0; j < data[i].size(); j++){
            if(data[i][j] == 'X') result++; 
        }
    }

    return result;
}

std::vector<std::string> get_data6(){
    std::ifstream inFile("6December/input.txt");
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

int solution6(){
    int result = 0;
    std::vector<std::string> data = get_data6();
    size_t x = 0;
    size_t y = 0;
    //I just want to find the starting position here
    for(size_t i = 0; i < data.size(); i++){
        for(size_t j = 0; j < data[0].size(); j++){
            if(data[i][j] == '^' || data[i][j] == 'v' || data[i][j] == '<' || data[i][j] == '>'){
                y = i;
                x = j;
                i = data.size() + 1;
                j = data[0].size() + 1;
            }
        }    
    }
    
    while(y < data.size() && x < data[0].size()){
        if(data[y][x] == '^'){
            data[y][x] = 'X'; 
            if(y-1 < 0 || y == 0) break;
            if(data[y-1][x] == '#' && x+1 < data[0].size()  && data[y][x+1] == '#'){
                y++;
                data[y][x] = 'v';
            }
            else if(data[y-1][x] == '#'){
               x++;
               data[y][x] = '>';
            } 
            else{
               y--;
               data[y][x] = '^'; 
            }
        } 
        if(data[y][x] == '>'){
            data[y][x] = 'X'; 
            if(x+1 >= data[0].size() || x == data[0].size()) break;
            if(data[y][x+1] == '#' && y+1 < data.size() && data[y+1][x] == '#'){
                x--;
                data[y][x] = '<';
            }
            else if(data[y][x+1] == '#'){
               y++;
               data[y][x] = 'v';
            } 
            else{
               x++;
               data[y][x] = '>'; 
            }
        } 
        if(data[y][x] == 'v'){
            data[y][x] = 'X'; 
            if(y+1 >= data.size() || y == data.size()) break;
            if(data[y+1][x] == '#' && x-1 >= 0 && data[y][x-1] == '#'){
                y--;
                data[y][x] = '^';
            }
            else if(data[y+1][x] == '#'){
               x--;
               data[y][x] = '<';
            } 
            else{
               y++;
               data[y][x] = 'v'; 
            }
        } 
        if(data[y][x] == '<'){
            data[y][x] = 'X'; 
            if(x-1 < 0 || x == 0) break;
            if(data[y][x-1] == '#' && y-1 >= 0 && data[y-1][x] == '#'){
                x++;
                data[y][x] = '>';
            }
            else if(data[y][x-1] == '#'){
               y--;
               data[y][x] = '^';
            } 
            else{
               x--;
               data[y][x] = '<'; 
            }
        } 
    }
    result = counter(data);

    return result;
}

//Second solution

using Position = std::pair<size_t, size_t>;

bool check_loop(std::vector<std::string> data, Position player, Position obstacle){
    size_t y = player.first;
    size_t x = player.second;
    std::set<std::tuple<Position, char>> visited;
    data[obstacle.first][obstacle.second] = 'O';
    std::tuple<Position, char> vis;
    const size_t STEP_LIMIT = 1e6;
    size_t steps = 0;

    while(y < data.size() && x < data[0].size()){
        steps++;
        if(steps > STEP_LIMIT) return true;
        if(data[y][x] == '^'){
            data[y][x] = 'X'; 
            vis = {{y, x}, '^'};
            if(y-1 < 0 || y == 0) break;
            if(data[y-1][x] == 'O' && visited.count(vis) > 0) return true;
            visited.insert(vis);
            if((data[y-1][x] == '#' || data[y-1][x] == 'O') && x+1 < data[0].size() && (data[y][x+1] == '#' || data[y][x+1] == 'O')){
                y++;
                data[y][x] = 'v';
            }
            else if(data[y-1][x] == '#' || data[y-1][x] == 'O'){
               x++;
               data[y][x] = '>';
            } 
            else{
               y--;
               data[y][x] = '^'; 
            }
        } 
        else if(data[y][x] == '>'){
            data[y][x] = 'X'; 
            vis = {{y, x}, '>'};
            if(x+1 >= data[0].size() || x == data[0].size()) break;
            if(data[y][x+1] == 'O' && visited.count(vis) > 0) return true;
            visited.insert(vis);
            if((data[y][x+1] == '#' || data[y][x+1] == 'O') && y+1 < data.size() && (data[y+1][x] == '#' || data[y+1][x] == 'O')){
                x--;
                data[y][x] = '<';
            }
            else if(data[y][x+1] == '#' || data[y][x+1] == 'O'){
               y++;
               data[y][x] = 'v';
            } 
            else{
               x++;
               data[y][x] = '>'; 
            }
        } 
        else if(data[y][x] == 'v'){
            data[y][x] = 'X'; 
            vis = {{y, x}, 'v'};
            if(y+1 >= data.size() || y == data.size()) break;
            if(data[y+1][x] == 'O' && visited.count(vis) > 0) return true;
            visited.insert(vis);
            if((data[y+1][x] == '#' || data[y+1][x] == 'O') && x-1 >= 0 && (data[y][x-1] == '#' || data[y][x-1] == 'O')){
                y--;
                data[y][x] = '^';
            }
            else if(data[y+1][x] == '#' || data[y+1][x] == 'O'){
               x--;
               data[y][x] = '<';
            } 
            else{
               y++;
               data[y][x] = 'v'; 
            }
        } 
        else if(data[y][x] == '<'){
            data[y][x] = 'X'; 
            vis = {{y, x}, '<'};
            if(x-1 < 0 || x == 0) break;
            if(data[y][x-1] == 'O' && visited.count(vis) > 0) return true;
            visited.insert(vis);
            if((data[y][x-1] == '#' || data[y][x-1] == 'O') && y-1 >= 0 && (data[y-1][x] == '#' || data[y-1][x] == 'O')){
                x++;
                data[y][x] = '>';
            }
            else if(data[y][x-1] == '#' || data[y][x-1] == 'O'){
               y--;
               data[y][x] = '^';
            } 
            else{
               x--;
               data[y][x] = '<'; 
            }
        } 
    }

    return false;
}

int second_solution6(){
    int result = 0;
    std::vector<std::string> data = get_data6();
    Position player;
    for(size_t i = 0; i < data.size(); i++){
        for(size_t j = 0; j < data[0].size(); j++){
            if(data[i][j] == '^' || data[i][j] == 'v' || data[i][j] == '<' || data[i][j] == '>'){
                player.first = i;
                player.second = j;
                i = data.size() + 1;
                j = data[0].size() + 1;
            }
        }    
    }

    for(size_t i = 0; i < data.size(); i++){
        for(size_t j = 0; j < data[0].size(); j++){
            Position obstacle = {i, j};
            if(obstacle == player) continue;
            if(check_loop(data, player, obstacle)){
                result++;
            }
        }    
    }

    return result;
}

