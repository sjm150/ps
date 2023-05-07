#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());

    int l = 0;
    int r = distance + 1;
    int bound = r;
    while (l <= r) {
        int m = (l + r) / 2;
        int removed = 0;
        
        int prev = 0;
        for (int i = 0; i < rocks.size(); i++) {
            int curr = rocks[i];
            if (curr - prev < m) removed++;
            else prev = curr;
        }
        if (distance - prev < m) removed++;
        
        if (removed > n) {
            bound = min(bound, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    return bound - 1;
}