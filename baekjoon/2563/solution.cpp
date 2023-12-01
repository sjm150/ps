#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<vector<bool>> grid(100, vector<bool>(100));
    int n; cin >> n;
    while (n--) {
        int x, y; cin >> x >> y;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                grid[x + i][y + j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (grid[i][j]) cnt++;
        }
    }
    cout << cnt << '\n';
}