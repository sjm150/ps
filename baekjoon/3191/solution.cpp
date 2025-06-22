#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c, n, k;
    cin >> a >> b >> c >> n >> k;
    string s;
    cin >> s;

    vector<vector<int>> dst(n + 1, vector<int>(k + 1, 1e9));
    dst[0][0] = 0;
    map<int, int> lst;
    lst[0] = 0;
    
    int h = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'D') {
            h++;
            for (int j = 0; j <= k; j++) dst[i][j] = dst[i - 1][j] + b;
            auto it = lst.find(h);
            if (it != lst.end()) {
                int p = it->second;
                for (int j = 1; j <= k; j++) dst[i][j] = min(dst[i][j], dst[p][j - 1] + (i - p) * c);
            }
        } else if (s[i - 1] == 'R') {
            for (int j = 0; j <= k; j++) dst[i][j] = dst[i - 1][j] + a;
        } else {
            h--;
            for (int j = 0; j <= k; j++) dst[i][j] = dst[i - 1][j] + b;
            auto it = lst.find(h);
            if (it != lst.end()) {
                int p = it->second;
                for (int j = 1; j <= k; j++) dst[i][j] = min(dst[i][j], dst[p][j - 1] + (i - p) * c);
            }
        }
        lst[h] = i;
    }

    cout << *min_element(dst[n].begin(), dst[n].end()) << '\n';
}