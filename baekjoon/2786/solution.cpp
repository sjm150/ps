#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> ba(n);
    for (int i = 0; i < n; i++) cin >> ba[i].second >> ba[i].first;
    sort(ba.begin(), ba.end());

    vector<long long> bsum(n);
    bsum[0] = ba[0].first;
    for (int i = 1; i < n; i++) bsum[i] = bsum[i - 1] + ba[i].first;
    vector<int> mina(n), maxd(n);
    mina[n - 1] = ba[n - 1].second;
    for (int i = n - 2; i >= 0; i--) mina[i] = min(mina[i + 1], ba[i].second);
    maxd[0] = ba[0].second - ba[0].first;
    for (int i = 1; i < n; i++) maxd[i] = min(maxd[i - 1], ba[i].second - ba[i].first);

    cout << mina[0] << '\n';
    for (int i = 1; i < n; i++) cout << min(bsum[i] + maxd[i], bsum[i - 1] + mina[i]) << '\n';
}