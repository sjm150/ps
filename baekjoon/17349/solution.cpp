#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    pair<int, int> a[9];
    for (auto &[b, a]: a) cin >> b >> a;
    vector<int> cnd;
    for (int i = 1; i <= 9; i++) {
        int cnt = 0;
        for (auto [b, a]: a) {
            if ((b == 1) != (a == i)) cnt++;
        }
        if (cnt == 1) cnd.push_back(i);
    }
    cout << (cnd.size() == 1 ? cnd[0] : -1) << '\n';
}