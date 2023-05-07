#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();
    int total_time = 0;
    priority_queue<pair<int, int>> pq; // job time, request time
    
    sort(jobs.begin(), jobs.end());

    int done = 0;
    int idx = 0;
    int time = 0;
    while (done < n) {
        while (idx < n && jobs[idx][0] <= time) {
            pq.emplace(-jobs[idx][1], jobs[idx][0]);
            idx++;
        }
        
        if (!pq.empty()) {
            time += -pq.top().first;
            total_time += time - pq.top().second;
            pq.pop();
            done++;
        } else {
            time = jobs[idx][0];
        }
    }
    
    return total_time / n;
}