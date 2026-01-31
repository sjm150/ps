#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k, x;
    cin >> n >> k >> x;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        while (c--) {
            int a;
            cin >> a;
            for (int j = 0; j < x; j++) edges[i].push_back(x * (a - 1) + j);
        }
    }
    vector<int> b(n);
    for (int &b: b) cin >> b;

    vector<int> mch(n, -1), rmch(k * x, -1);
    vector<bool> vst(n);
    function<bool(int)> bpm = [&](int cur) {
        vst[cur] = true;
        for (int nxt: edges[cur]) {
            if (rmch[nxt] < 0 || (!vst[rmch[nxt]] && bpm(rmch[nxt]))) {
                mch[cur] = nxt;
                rmch[nxt] = cur;
                return true;
            }
        }
        return false;
    };

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return b[i] > b[j]; });
    for (int i: ord) {
        fill(vst.begin(), vst.end(), false);
        bpm(i);
    }

    for (int i = 0; i < k; i++) {
        int cnt = 0;
        for (int j = 0; j < x; j++) cnt += rmch[i * x + j] >= 0;
        cout << cnt << ' ';
        for (int j = 0; j < x; j++) {
            if (rmch[i * x + j] >= 0) cout << rmch[i * x + j] + 1 << ' ';
        }
        cout << '\n';
    }
}