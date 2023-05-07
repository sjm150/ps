#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> visit_group(n);
    for (int i = 0; i < n; i++) {
        visit_group[i] = -1;
    }
    
    vector<int> next_visit;
    for (int i = 0; i < n; i++) {
        if (visit_group[i] >= 0) continue;
        
        next_visit.push_back(i);
        visit_group[i] = answer;

        while (!next_visit.empty()) {
            int curr = next_visit.back();
            next_visit.pop_back();
            
            for (int next = 0; next < n; next++) {
                if (computers[curr][next] == 1 && visit_group[next] < 0) {
                    visit_group[next] = answer;
                    next_visit.push_back(next);
                }
            }
        }
        
        answer++;
    }
    
    
    return answer;
}