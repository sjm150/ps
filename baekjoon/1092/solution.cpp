#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    int m;
    cin >> m;
    multiset<int> w;
    while (m--) {
        int x;
        cin >> x;
        w.insert(x);
    }
    if (*max_element(a.begin(), a.end()) < *prev(w.end())) {
        cout << -1 << '\n';
    } else {
        int t = 0;
        for (; !w.empty(); t++) {
            for (int a: a) {
                auto it = w.upper_bound(a);
                if (it != w.begin()) w.erase(prev(it));
            }
        }
        cout << t << '\n';
    }
}