#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    set<int> s;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != a[i]) s.insert(i);
    }

    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            a[i] = x;
            if (i > 0) {
                if (a[i - 1] != a[i]) s.insert(i);
                else s.erase(i);
            }
            if (i + 1 < n) {
                if (a[i] != a[i + 1]) s.insert(i + 1);
                else s.erase(i + 1);
            }
        } else {
            int i;
            cin >> i;
            i--;
            auto it = s.upper_bound(i);
            if (it == s.begin()) {
                cout << "Spring\n";
            } else {
                int idx = *prev(it);
                bool up = a[idx - 1] < a[idx];
                if (idx != i) cout << (up ? "Autumn\n" : "Spring\n");
                else cout << (up ? "Summer\n" : "Winter\n");
            }
        }
    }
}