#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) {
            cin >> a;
            a--;
        }

        vector<int> pos(n), e, o;
        for (int i = 0; i < n; i++) {
            pos[a[i]] = i;
            (i % 2 ? o : e).push_back(a[i]);
        }
        sort(e.begin(), e.end());
        sort(o.begin(), o.end());

        auto swp = [&](int i, int j) {
            assert(i % 2 == j % 2);
            swap(a[i], a[j]);
            swap(pos[a[i]], pos[a[j]]);
            swap(a[i + 1], a[j + 1]);
            swap(pos[a[i + 1]], pos[a[j + 1]]);
        };
        for (int i = 0; i < n - 3; i++) {
            int mn = (i % 2 ? o : e)[i / 2];
            if (pos[mn] == n - 1) swp(n - 4, n - 2);
            if (i != pos[mn]) swp(i, pos[mn]);
        }

        for (int a: a) cout << a + 1 << ' ';
        cout << '\n';
    }
}