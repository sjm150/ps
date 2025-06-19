#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<char> c(n);
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> c[i] >> s[i];

    vector<int> mx(n, 0), cur(n, 0);
    for (int i = 0; i < m; i++) {
        int tot = 0;
        for (int j = 0; j < n; j++) tot += (c[j] == 'L' ? -1 : 1) * (s[j][i] - '0');
        for (int j = 0; j < n; j++) {
            cur[j] += tot - (c[j] == 'L' ? -1 : 1) * (s[j][i] - '0');
            mx[j] = max(mx[j], abs(cur[j]));
        }
    }

    int idx = min_element(mx.begin(), mx.end()) - mx.begin();
    cout << idx + 1 << '\n';
    cout << mx[idx] << '\n';
}