#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    auto solve = [](string n) {
        int sz = n.size();
        int cnt[10] = {};
        for (char c: n) cnt[c - '0']++;

        int mx = *max_element(cnt, cnt + 10);
        bool ok = true;
        for (int c: cnt) {
            if (c && c < mx) {
                ok = false;
                break;
            }
        }
        if (ok) return n;

        for (int i = sz - 1; i >= 0; i--) {
            cnt[n[i] - '0']--;
            for (int j = n[i] - '0' + 1; j < 10; j++) {
                n[i] = j + '0';
                cnt[j]++;

                bool use[10] = {};
                int mx = *max_element(cnt, cnt + 10), ucnt = 0;
                for (int k = 0; k < 10; k++) {
                    if (cnt[k]) {
                        use[k] = true;
                        ucnt++;
                    }
                }

                bool ok = false;
                vector<int> tar(10, 0);
                for (int k = ucnt; k <= 10; k++) {
                    if (sz / k < mx) break;
                    if (sz % k == 0) {
                        vector<int> cur(10, 0);
                        for (int ii = 0; ii < 10; ii++) {
                            if (use[ii]) cur[ii] = sz / k;
                        }
                        int r = k - ucnt;
                        for (int ii = 0; ii < 10 && r; ii++) {
                            if (!use[ii]) {
                                cur[ii] = sz / k;
                                r--;
                            }
                        }
                        if (tar < cur) tar = cur;
                        ok = true;
                    }
                }

                if (ok) {
                    int d = 0;
                    for (int k = i + 1; k < sz; k++) {
                        while (cnt[d] == tar[d]) d++;
                        n[k] = d + '0';
                        cnt[d]++;
                    }
                    return n;
                }

                cnt[j]--;
            }
        }

        assert(false);
    };

    long long n;
    cin >> n;
    cout << solve(to_string(n)) << '\n';
}