#include <bits/stdc++.h>
using namespace std;

int val(string& mbti) {
    int v = 0;
    if (mbti[0] == 'I') v += 8;
    if (mbti[1] == 'N') v += 4;
    if (mbti[2] == 'F') v += 2;
    if (mbti[3] == 'P') v += 1;
    return v;
}

int dst(int a, int b) {
    int x = a ^ b;
    int d = 0;
    for (int i = 0; i < 4; i++) {
        d += x & 1;
        x = x >> 1;
    }
    return d;
}

int cnt[16];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fill(cnt, cnt + 16, 0);
        while (n--) {
            string mbti; cin >> mbti;
            cnt[val(mbti)]++;
        }
        int ans = 12;
        for (int i = 0; i < 16; i++) {
            if (cnt[i] == 0) continue;
            cnt[i]--;
            for (int j = 0; j < 16; j++) {
                if (cnt[j] == 0) continue;
                cnt[j]--;
                for (int k = 0; k < 16; k++) {
                    if (cnt[k] == 0) continue;
                    ans = min(ans, dst(i, j) + dst(j, k) + dst(k, i));
                }
                cnt[j]++;
            }
            cnt[i]++;
        }
        cout << ans << '\n';
    }
}