#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<string> grid(8);
    for (auto &s: grid) cin >> s;
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) cnt += (i + j) % 2 == 0 && grid[i][j] == 'F';
    }
    cout << cnt << '\n';
}