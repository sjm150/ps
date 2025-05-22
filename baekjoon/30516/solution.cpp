#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    vector<int> ans;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > 0 && a[i - 1] == a[i]) {
            ans.push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    ans.push_back(cnt);

    if (ans.size() == 2 && a[0] > 0 && a[0] == a[n - 1]) {
        if (ans[0] > 1) {
            cout << 3 << '\n';
            cout << 1 << ' ' << ans[0] - 1 << ' ' << ans[1] << '\n';
            cout << 1 << ' ' << 3 << ' ' << 2 << '\n';
        } else if (ans[1] > 1) {
            cout << 3 << '\n';
            cout << ans[0] << ' ' << ans[1] - 1 << ' ' << 1 << '\n';
            cout << 2 << ' ' << 1 << ' ' << 3 << '\n';
        } else {
            cout << -1 << '\n';
        }
    } else {
        cout << ans.size() << '\n';
        for (int a: ans) cout << a << ' ';
        cout << '\n';
        for (int i = ans.size(); i; i--) cout << i << ' ';
        cout << '\n';
    }
}