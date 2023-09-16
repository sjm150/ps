#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

pi wire[100000];
pi lst[100000];
int pre[100000];
int lidx;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> wire[i].first >> wire[i].second;
    sort(wire, wire + n);
    for (int i = 0; i < n; i++) {
        auto [s, e] = wire[i];
        int idx = upper_bound(lst, lst + lidx, pair(e, i)) - lst;
        if (idx == lidx) lidx++;
        lst[idx] = {e, i};
        if (idx == 0) pre[i] = -1;
        else pre[i] = lst[idx - 1].second;
    }
    vector<bool> rem(n, false);
    int cur = lst[lidx - 1].second;
    while (cur != -1) {
        rem[cur] = true;
        cur = pre[cur];
    }
    cout << n - lidx << '\n';
    for (int i = 0; i < n; i++) {
        if (!rem[i]) cout << wire[i].first << '\n';
    }
}