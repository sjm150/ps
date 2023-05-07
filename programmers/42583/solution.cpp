#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    q.push(truck_weights[0]);
    int total_weight = truck_weights[0];
    int next = 1;

    int time = 1;
    while (next < truck_weights.size()) {
        if (q.size() == bridge_length) {
            total_weight -= q.front();
            q.pop();
        }
        
        if (total_weight + truck_weights[next] <= weight) {
            q.push(truck_weights[next]);
            total_weight += truck_weights[next];
            next++;
        } else {
            q.push(0);
        }
        
        time++;
    }
    
    return time + bridge_length;
}