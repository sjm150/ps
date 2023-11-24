#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> ti;

const int inf = 1e9;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int maxa = alp, maxc = cop;
    for (auto& prob: problems) {
        if (prob[0] > maxa) maxa = prob[0];
        if (prob[1] > maxc) maxc = prob[1];
    }
    
    vector<vector<int>> mint(maxa + 1, vector<int>(maxc + 1, 1e9));
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    mint[alp][cop] = 0;
    pq.emplace(0, alp, cop);
    while (!pq.empty()) {
        auto [t, a, c] = pq.top(); pq.pop();
        if (t != mint[a][c]) continue;
        
        if (a < maxa && mint[a + 1][c] > t + 1) {
            mint[a + 1][c] = t + 1;
            pq.emplace(t + 1, a + 1, c);
        }
        if (c < maxc && mint[a][c + 1] > t + 1) {
            mint[a][c + 1] = t + 1;
            pq.emplace(t + 1, a, c + 1);
        }
        for (auto& prob: problems) {
            if (prob[0] > a || prob[1] > c) continue;
            int na = min(maxa, a + prob[2]);
            int nc = min(maxc, c + prob[3]);
            int nt = t + prob[4];
            if (mint[na][nc] > nt) {
                mint[na][nc] = nt;
                pq.emplace(nt, na, nc);
            }
        }
    }
    
    return mint[maxa][maxc];
}