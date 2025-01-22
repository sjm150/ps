#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;
        multiset<int> as, bs;
        for (int b: b) bs.insert(b);
        for (int a: a) {
            auto it = bs.find(a);
            if (it != bs.end()) bs.erase(it);
            else as.insert(a);
        }
        while (!bs.empty()) {
            int b = *bs.begin();
            if (b == 1) break;
            bs.erase(bs.begin());
            int bb[] = {b / 2, (b + 1) / 2};
            for (int b: bb) {
                auto it = as.find(b);
                if (it != as.end()) as.erase(it);
                else bs.insert(b);
            }
        }
        cout << (as.empty() && bs.empty() ? "YES\n" : "NO\n");
    }
}