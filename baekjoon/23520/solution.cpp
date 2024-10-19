#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n), cnt(n, 0), pre(n, -1);
    for (int &a: a) cin >> a;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (cnt[i] < cnt[j] + (a[j] == a[i])) {
                cnt[i] = cnt[j] + (a[j] == a[i]);
                pre[i] = j;
            }
        }
    }
    vector<int> ans;
    function<void(int)> push = [&](int cur) {
        if (pre[cur] >= 0) push(pre[cur]);
        ans.push_back(a[cur]);
    };
    int mi = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    push(mi);
    cout << ans.size() << ' ' << cnt[mi] << '\n';
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}