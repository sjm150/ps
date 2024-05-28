#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        vector<int> a;
        for (; x; x /= 2) {
            if (x % 2) a.push_back(1);
            else a.push_back(0);
        }

        if (a.back() == 1) a.push_back(0);
        int n = a.size(), p = -1;
        for (int i = 0; i < n; i++) {
            if (p < 0) {
                if (a[i] == 1) p = i;
            } else {
                if (a[i] == 0) {
                    if (i - p == 1) {
                        p = -1;
                    } else {
                        a[p] = -1;
                        a[i] = 1;
                        for (int j = p + 1; j < i; j++) a[j] = 0;
                        p = i;
                    }
                }
            }
        }

        cout << a.size() << '\n';
        for (int a: a) cout << a << ' ';
        cout << '\n';
    }
}