#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int n = people.size();
    sort(people.begin(), people.end());
    int light = 0, heavy = n - 1;
    
    int num = 0;
    while (light <= heavy) {
        if (light == heavy) {
            num++;
            break;
        }
        
        if (people[light] + people[heavy] <= limit) light++;
        heavy--;
        num++;
    }
    
    return num;
}