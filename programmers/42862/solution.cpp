#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int borrow = 0;
    vector<bool> spare(n, false);
    for (int idx: reserve) spare[idx - 1] = true;
    for (int& idx: lost) {
        if (spare[idx - 1]) {
            spare[idx - 1] = false;
            borrow++;
            idx = n + 1;
        }
    }
    
    sort(lost.begin(), lost.end());
    for (int idx: lost) {
        if (idx > n) break;
        idx--;
        if (idx > 0 && spare[idx - 1]) {
            spare[idx - 1] = false;
            borrow++;
        } else if (idx < n - 1 && spare[idx + 1]) {
            spare[idx + 1] = false;
            borrow++;
        }
    }
    
    return n - lost.size() + borrow;
}