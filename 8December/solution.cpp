#include <bits/stdc++.h>
#include <vector>

//First solution
std::vector<std::string> get_data8(){
    std::ifstream inFile("8December/input.txt");
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

size_t solution8(){
    //std::vector<std::string> data = {"............",
    //                                 "........0...",
    //                                 ".....0......",
    //                                 ".......0....",
    //                                 "....0.......",
    //                                 "......A.....",
    //                                 "............",
    //                                 "............",
    //                                 "........A...",
    //                                 ".........A..",
    //                                 "............",
    //                                 "............"};
    std::vector<std::string> data = get_data8();
    std::map<std::pair<size_t, size_t>, char> node_positions;

    for(size_t i = 0; i < data.size(); i++){
        for(size_t j = 0; j < data[i].size(); j++){
           if(data[i][j] != '.') {
               std::pair<size_t, size_t> current;
               current.first = i;
               current.second = j;
               node_positions[current] = data[i][j];
           }
        }
    }

    std::map<std::pair<size_t, size_t>, char>::iterator itr;
    std::set<std::pair<size_t, size_t>> already_counted;
    for(auto const& itr : node_positions){
        for(auto const& second_itr : node_positions){
            if(itr == second_itr || itr.second != second_itr.second) continue;
            size_t y;
            size_t x;
            if(itr.first.first > second_itr.first.first) y = itr.first.first + (itr.first.first - second_itr.first.first); 
            else y = itr.first.first - (second_itr.first.first - itr.first.first);
            if(itr.first.second > second_itr.first.second) x = itr.first.second + (itr.first.second - second_itr.first.second); 
            else x = itr.first.second - (second_itr.first.second - itr.first.second);
            if(y >= 0 && y < data.size() && x >= 0 && x < data[0].size()) already_counted.insert({y, x});
        }
    }
    
    return already_counted.size();
}
