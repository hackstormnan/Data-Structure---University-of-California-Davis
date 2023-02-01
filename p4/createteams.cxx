#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include "json.hpp"
#include "priorityqueue.h"

int main(int argc, char** argv) {

    size_t pos_comb = 0;
    std::ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    nlohmann::json resultjson;



    if (file.is_open()) {
        file >> jsonObject;
    }

    int num_player = jsonObject["metadata"]["numPlayers"];

    int num_teams=num_player/2;



    for (int i=num_player-1; i>=1; i--) {
        pos_comb += i;
    }


    PriorityQueue heap(pos_comb);
    Key key_insert;
    for (int i=0; i < pos_comb; i++) {
        double winPercentage = jsonObject["teamStats"][i]["winPercentage"];
        if (fabs(winPercentage - 50.0) <= 50) {
            key_insert = fabs(winPercentage - 50.0);
        }
        int first_player = jsonObject["teamStats"][i]["playerOne"];
        int second_player = jsonObject["teamStats"][i]["playerTwo"];
        std::pair <int,int> player_pair = std::make_pair(first_player, second_player);
        heap.insert(std::make_pair(key_insert, player_pair));
    }
heap.print_t();
    std::vector<Value> teams;
    int assigned[num_player];
    bool no_same = true;
    int i = 0;
    std::cout << "numteams= " <<num_teams <<std::endl;
    while (num_teams > 0) {

        KeyValuePair min_removed = heap.removeMin();
        for (int j = 0; j < i; j++) {
            if (assigned[j] == min_removed.second.first || assigned[j] == min_removed.second.second) {
                no_same = false;
                break;
            }
        }
        if(no_same == true) {
            teams.push_back(min_removed.second);
            assigned[i] = min_removed.second.first;
            assigned[++i] = min_removed.second.second;
            i++;
            num_teams--;
            resultjson["teams"].push_back(min_removed.second);
        }

        no_same = true;
    }



  std::cout << resultjson.dump(2);

}
