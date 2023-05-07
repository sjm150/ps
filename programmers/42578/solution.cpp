#include <string>
#include <vector>
#include <map>

#include<iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> categories;
    for (auto& cloth: clothes) {
        string& category = cloth[1];
        auto it = categories.find(category);
        if (it != categories.end()) {
            it->second++;
        } else {
            categories.insert(pair(category, 1));
        }
    }
    
    int comb = 1;
    for (auto& pair: categories) {
        int count = pair.second;
        comb *= count + 1;
    }
    return comb - 1;
}