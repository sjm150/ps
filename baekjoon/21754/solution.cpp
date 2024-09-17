#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (auto &s: grid) cin >> s;
    auto run = [&](int mni, int mxi, int mnj, int mxj, int &u, int &b, int &l, int &r) {
        for (int i = mni; i < mxi; i++) {
            for (int j = mnj; j < mxj; j++) {
                if (grid[i][j] == '.') continue;
                u = min(u, i);
                b = max(b, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    };
    auto chk = [&](int au, int ab, int al, int ar, int bu, int bb, int bl, int br) {
        for (int i = au; i <= ab; i++) {
            for (int j = al; j <= ar; j++) {
                if (grid[i][j] == '.') return false;
            }
        }
        for (int i = bu; i <= bb; i++) {
            for (int j = bl; j <= br; j++) {
                if (grid[i][j] == '.') return false;
            }
        }
        cout << "YES\n";
        for (int i = au; i <= ab; i++) {
            for (int j = al; j <= ar; j++) {
                grid[i][j] = 'a';
            }
        }
        for (int i = bu; i <= bb; i++) {
            for (int j = bl; j <= br; j++) {
                grid[i][j] = 'b';
            }
        }
        for (auto &s: grid) cout << s << '\n';
        return true;
    };
    for (int l = 1; l < n; l++) {
        int au = n, ab = -1, al = m, ar = -1;
        int bu = n, bb = -1, bl = m, br = -1;
        run(0, l, 0, m, au, ab, al, ar);
        run(l, n, 0, m, bu, bb, bl, br);
        if (au == n) continue;
        if (bu == n) continue;
        if (chk(au, ab, al, ar, bu, bb, bl, br)) exit(0);
    }
    for (int l = 1; l < m; l++) {
        int au = n, ab = -1, al = m, ar = -1;
        int bu = n, bb = -1, bl = m, br = -1;
        run(0, n, 0, l, au, ab, al, ar);
        run(0, n, l, m, bu, bb, bl, br);
        if (au == n) continue;
        if (bu == n) continue;
        if (chk(au, ab, al, ar, bu, bb, bl, br)) exit(0);
    }
    cout << "NO\n";
}