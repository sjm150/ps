#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

typedef struct State {
    int smt, ints;
    State(int smt, int ints): smt(smt), ints(ints) {}
} state_t;

const int inf = 1e9;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pi>> edges(n + 1);
    for (auto &path: paths) {
        int i = path[0], j = path[1], w = path[2];
        edges[i].emplace_back(w, j);
        edges[j].emplace_back(w, i);
    }

    vector<state_t> states(n + 1, State(0, inf));
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    for (int s: summits) {
        states[s] = State(s, 0);
        pq.emplace(0, s, s);
    }
    while (!pq.empty()) {
        auto [ints, smt, cur] = pq.top(); pq.pop();
        if (states[cur].ints != ints) continue;

        for (auto [w, nxt]: edges[cur]) {
            int nints = max(w, ints);
            if (states[nxt].ints > nints) {
                states[nxt] = State(smt, nints);
                pq.emplace(nints, smt, nxt);
            } else if (states[nxt].ints == nints && states[nxt].smt > states[cur].smt) {
                states[nxt].smt = states[cur].smt;
            }
        }
    }
    
    state_t ans = states[gates[0]];
    for (int g: gates) {
        if (ans.ints > states[g].ints) ans = states[g];
        else if (ans.ints == states[g].ints && ans.smt > states[g].smt) ans = states[g];
    }
    return {ans.smt, ans.ints};
}