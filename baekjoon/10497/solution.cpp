#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef tuple<int, int, int> ti3;
    typedef tuple<int, int, int, int> ti4;
    int m;
    cin >> m;
    vector<ti3> cir;
    vector<ti4> rec;
    while (m--) {
        string s;
        cin >> s;
        if (s[0] == 'r') {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            rec.emplace_back(x1, y1, x2, y2);
        } else {
            int x, y, r;
            cin >> x >> y >> r;
            cir.emplace_back(x, y, r);
        }
    }
    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        for (auto [x1, y1, x2, y2]: rec) cnt += x1 <= x && x <= x2 && y1 <= y && y <= y2;
        for (auto [x1, y1, r]: cir) cnt += (x - x1) * (x - x1) + (y - y1) * (y - y1) <= r * r;
        cout << cnt << '\n';
    }
}