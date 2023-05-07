#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int count = 0;
    
    for (int s: scoville) pq.push(s);
    
    while (pq.top() < K) {
        if (pq.size() < 2) return -1;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
        count++;
    }
    
    return count;
}