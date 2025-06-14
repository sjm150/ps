#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        vector<string> s(h);
        for (auto &s: s) cin >> s;

        vector<vector<int>> cnt(h, vector<int>(w));
        auto get = [&](int i, int j) {
            if (i < 0 || j < 0) return 0;
            else return cnt[i][j];
        };
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cnt[i][j] = get(i - 1, j) + get(i, j - 1) - get(i - 1, j - 1) + (s[i][j] == '#' ? 1 : -1);
            }
        }

        int ofs = h * w;
        vector<int> ccnt(ofs * 2 + 1, 0);
        long long ans = 0;
        if (h < w) {
            for (int i = 0; i < h; i++) {
                for (int j = i; j < h; j++) {
                    ccnt[ofs] = 1;
                    for (int k = 0; k < w; k++) ans += ccnt[get(j, k) - get(i - 1, k) + ofs]++;
                    for (int k = 0; k < w; k++) ccnt[get(j, k) - get(i - 1, k) + ofs] = 0;
                }
            }
        } else {
            for (int i = 0; i < w; i++) {
                for (int j = i; j < w; j++) {
                    ccnt[ofs] = 1;
                    for (int k = 0; k < h; k++) ans += ccnt[get(k, j) - get(k, i - 1) + ofs]++;
                    for (int k = 0; k < h; k++) ccnt[get(k, j) - get(k, i - 1) + ofs] = 0;
                }
            }
        }

        cout << ans << '\n';
    }
}