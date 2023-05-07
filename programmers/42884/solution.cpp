#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int n = routes.size();
    sort(routes.begin(), routes.end(),
         [](vector<int>& a, vector<int>& b) {
             if (a[0] == b[0]) return a[1] < b[1];
             else return a[0] < b[0];
         }
    );
    
    int camera = 1;
    int l = -30000, r = 30000;
    for (auto& route: routes) {
        int lcurr = route[0], rcurr = route[1];
        if (lcurr <= r) {
            l = lcurr;
            r = min(r, rcurr);
        } else {
            camera++;
            l = lcurr;
            r = rcurr;
        }
    }
    
    return camera;
}