#include <bits/stdc++.h>
using namespace std;

int n, w;
int per[10001][2];
int cnt[10001][3];

void calc() {
    for (int i = 2; i <= n; i++) {
        cnt[i][0] = cnt[i][1] = cnt[i - 1][2];
        if (per[i][0] + per[i - 1][0] <= w && cnt[i][0] < cnt[i - 1][1] + 1) cnt[i][0] = cnt[i - 1][1] + 1;
        if (per[i][1] + per[i - 1][1] <= w && cnt[i][1] < cnt[i - 1][0] + 1) cnt[i][1] = cnt[i - 1][0] + 1;
        cnt[i][2] = max(cnt[i][0], cnt[i][1]);
        if (per[i][0] + per[i][1] <= w && cnt[i][2] < cnt[i - 1][2] + 1) cnt[i][2] = cnt[i - 1][2] + 1;
        if (per[i][0] + per[i - 1][0] <= w && per[i][1] + per[i - 1][1] <= w &&
            cnt[i][2] < cnt[i - 2][2] + 2) cnt[i][2] = cnt[i - 2][2] + 2;
    }
}

int solve() {
    fill(cnt[0], cnt[0] + 3, 0);
    fill(cnt[1], cnt[1] + 3, 0);
    if (per[1][0] + per[1][1] <= w) cnt[1][2] = 1;
    calc();
    int maxc = cnt[n][2];

    if (per[1][0] + per[n][0] <= w) {
        cnt[1][0] = cnt[1][2] = 1;
        cnt[1][1] = 0;
        calc();
        if (maxc < cnt[n][1]) maxc = cnt[n][1];
    }

    if (per[1][1] + per[n][1] <= w) {
        cnt[1][1] = cnt[1][2] = 1;
        cnt[1][0] = 0;
        calc();
        if (maxc < cnt[n][0]) maxc = cnt[n][0];
    }

    if (per[1][0] + per[n][0] <= w && per[1][1] + per[n][1] <= w) {
        cnt[1][0] = cnt[1][1] = 1;
        cnt[1][2] = 2;
        calc();
        if (maxc < cnt[n - 1][2]) maxc = cnt[n - 1][2];
    }

    return 2 * n - maxc;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> w;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> per[j][i];
            }
        }
        cout << solve() << '\n';
    }
}