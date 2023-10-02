#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k[100000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> k[i];
    ll msum = k[0];
    deque<pair<int, ll>> dq;
    if (k[0] > 0) dq.emplace_back(0, k[0]);
    for (int i = 1; i < n; i++) {
        while (!dq.empty() && dq.front().first < i - d) dq.pop_front();
        ll sum = k[i];
        if (!dq.empty()) sum += dq.front().second;
        if (sum > msum) msum = sum;
        if (sum <= 0) continue;
        while (!dq.empty() && dq.back().second < sum) dq.pop_back();
        dq.emplace_back(i, sum);
    }
    cout << msum << '\n';
}