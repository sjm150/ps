#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int j = upper_bound(v.begin(), v.end(), 0) - v.begin();
    int i = j - 1;

    int minv = INT32_MAX, mini, minj;
    if (j <= n - 2) {
        minv = v[j] + v[j + 1];
        mini = j, minj = j + 1;
    }
    if (i >= 1 && minv > -(v[i - 1] + v[i])) {
        minv = -(v[i - 1] + v[i]);
        mini = i - 1, minj = i;
    }

    while (0 <= i && j < n) {
        int cur = v[i] + v[j];
        if (minv > abs(cur)) {
            minv = abs(cur);
            mini = i, minj = j;
        }
        if (cur > 0) i--;
        else if (cur < 0) j++;
        else break;
    }

    cout << v[mini] << ' ' << v[minj] << '\n';
}