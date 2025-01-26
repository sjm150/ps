#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mx = 5000;
    vector<int> cnt(mx + 1, 0);
    vector<long long> tot(mx + 1, 0), mn(mx + 1, 1e18);
    for (int i = 1; i < 1e5; i++) {
        int sum = 0;
        for (int j = i; j; j /= 10) sum += j % 10;
        cnt[sum]++;
        tot[sum] += i;
        if (cnt[sum] <= mx) mn[cnt[sum]] = min(mn[cnt[sum]], tot[sum]);
    }
    int n; cin >> n;
    cout << mn[n] << '\n';
}