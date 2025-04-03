#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int w, h, b; cin >> w >> h >> b;
    vector<vector<int>> g(h, vector<int>(w));
    for (auto &g: g) {
        for (int &g: g) cin >> g;
    }
    while (b--) {
        auto ng = g;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                ng[i][j] = 0;
                for (int ii = i - 1; ii <= i + 1; ii++) {
                    for (int jj = j - 1; jj <= j + 1; jj++) {
                        ng[i][j] += g[(ii + h) % h][(jj + w) % w];
                    }
                }
            }
        }
        swap(g, ng);
    }
    set<int> s;
    for (auto &g: g) {
        for (int g: g) s.insert(g);
    }
    cout << s.size() << '\n';
}