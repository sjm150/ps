#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int order = 0;
    int std = priorities[location];
    queue<int> q;
    for (int p: priorities) q.push(p);

    sort(priorities.begin(), priorities.end());    
    while (priorities.back() > std) {
        if (q.front() == priorities.back()) {
            q.pop();
            priorities.pop_back();
            order++;
        } else {
            q.push(q.front());
            q.pop();
        }
        
        location--;
        if (location < 0) location = q.size() - 1;
    }
    
    while (location >= 0) {
        if (q.front() == std) order++;
        q.pop();
        location--;
    }
    
    return order;
}