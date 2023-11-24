#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    int r = rc.size(), c = rc[0].size();
    deque<int> lq, rq;
    vector<deque<int>> dqs(r);
    for (int i = 0; i < r; i++) {
        lq.push_back(rc[i][0]);
        rq.push_back(rc[i][c - 1]);
        for (int j = 1; j < c - 1; j++) dqs[i].push_back(rc[i][j]);
    }
    
    int base = 0;
    for (auto& op: operations) {
        if (op[0] == 'S') {
            lq.push_front(lq.back()); lq.pop_back();
            rq.push_front(rq.back()); rq.pop_back();
            base--;
            if (base < 0) base += r;
        } else {
            int en = base + r - 1;
            if (en >= r) en -= r;
            dqs[base].push_front(lq.front()); lq.pop_front();
            rq.push_front(dqs[base].back()); dqs[base].pop_back();
            dqs[en].push_back(rq.back()); rq.pop_back();
            lq.push_back(dqs[en].front()); dqs[en].pop_front();
        }
    }
    
    for (int i = 0; i < r; i++) {
        rc[i][0] = lq.front(); lq.pop_front();
        rc[i][c - 1] = rq.front(); rq.pop_front();
        for (int j = 1; j < c - 1; j++) {
            int cur = base + i;
            if (cur >= r) cur -= r;
            rc[i][j] = dqs[cur].front();
            dqs[cur].pop_front();
        }
    }
    return rc;
}