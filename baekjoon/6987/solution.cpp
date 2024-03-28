#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t = 4;
    while (t--) {
        int res[6][3], tmp[6][3];
        int tot = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> res[i][j];
                tot += res[i][j];
                tmp[i][j] = 0;
            }
        }
        if (tot != 30) {
            cout << 0 << ' ';
            continue;
        }
        const int mch[][2] = {{0, 2}, {1, 1}, {2, 0}};
        bool poss = false;
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i == 6) {
                poss = true;
                return;
            }
            if (j == 6) {
                dfs(i + 1, i + 2);
                return;
            }
            for (int m = 0; m < 3; m++) {
                if (res[i][mch[m][0]] == tmp[i][mch[m][0]] || res[j][mch[m][1]] == tmp[j][mch[m][1]]) continue;
                tmp[i][mch[m][0]]++, tmp[j][mch[m][1]]++;
                dfs(i, j + 1);
                tmp[i][mch[m][0]]--, tmp[j][mch[m][1]]--;
            }
        };
        dfs(0, 1);
        cout << poss << ' ';
    }
    cout << '\n';
}