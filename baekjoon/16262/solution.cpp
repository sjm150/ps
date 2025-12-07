#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) {
            cin >> a;
            a--;
        }

        vector<bool> vst(n, false), st(n, false);
        function<void(int)> dfs = [&](int cur) {
            vst[cur] = true;
            if (a[cur] < 0) return;
            if (vst[a[cur]]) st[a[cur]] = false;
            else dfs(a[cur]);
        };
        for (int i = 0; i < n; i++) {
            if (vst[i]) continue;
            st[i] = true;
            dfs(i);
        }

        vector<int> ss;
        for (int i = 0; i < n; i++) {
            if (st[i]) ss.push_back(i);
        }
        int sz = ss.size();
        for (int i = 0; i < sz; i++) {
            int cur = ss[i];
            while (a[cur] >= 0) cur = a[cur];
            a[cur] = ss[i + 1 == sz ? 0 : i + 1];
        }

        int cnt = 0;
        fill(vst.begin(), vst.end(), false);
        for (int i = 0; i < n; i++) {
            if (vst[i]) continue;
            dfs(i);
            cnt++;
        }

        cout << n - cnt << '\n';
        for (int a: a) cout << a + 1 << ' ';
        cout << '\n';
    }
}