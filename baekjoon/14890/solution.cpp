#include <bits/stdc++.h>
using namespace std;

int n, l;

bool isposs(vector<int>& path) {
    vector<int> used(n, false);
    int ph = path[0];
    for (int i = 1; i < n; i++) {
        if (ph == path[i]) continue;
        int dh = path[i] - ph;
        if (dh == 1) {
            for (int ii = i - 1; ii >= i - l; ii--) {
                if (ii < 0 || path[ii] != path[i - 1] || used[ii]) return false;
            }
        } else if (dh == -1) {
            for (int ii = i; ii < i + l; ii++) {
                if (ii >= n || path[ii] != path[i]) return false;
                used[ii] = true;
            }
            i = i + l - 1;
        } else {
            return false;
        }
        ph = path[i];
    }
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> l;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> tgrd(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            tgrd[j][i] = grid[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (isposs(grid[i])) cnt++;
        if (isposs(tgrd[i])) cnt++;
    }

    cout << cnt << '\n';
}