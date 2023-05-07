#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> part_map;
    for (string& name: participant) {
        auto it = part_map.find(name);
        if (it != part_map.end()) {
            it->second++;
        } else {
            part_map.emplace(name, 1);
        }
    }
    
    for (string& name: completion) {
        auto it = part_map.find(name);
        if (it != part_map.end()) {
            it->second--;
            if (it->second == 0) {
                part_map.erase(it);
            }
        }
    }
    
    return part_map.begin()->first;
}