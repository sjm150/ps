#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += n + 2 - 2 * i;
        if (cnt % m == 0) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int a: ans) cout << a << '\n';
}