#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> k;
    vector<int> x(k);
    int cnt = 0;
    for (int &x: x) {
        cin >> x;
        cnt += x / k;
        x %= k;
    }

    sort(x.begin(), x.end());
    int minr = k;
    for (int i = 0; i < k; i++) minr = min(minr, x[i] + k - i - 1);

    cout << cnt + minr << '\n';
}