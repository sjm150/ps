#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n, k;
string s;
vector<pi> sameseq;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> k >> s;
    char c = s[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == c) {
            cnt++;
        } else {
            if (cnt >= k) sameseq.emplace_back(i - cnt, i);
            c = s[i];
            cnt = 1;
        }
    }
    if (cnt >= k) sameseq.emplace_back(n - cnt, n);
    for (int l = n; l >= k - 1; l--) {
        bool exst = false;
        for (int i = 0; i < n; i += l) {
            auto it = lower_bound(sameseq.begin(), sameseq.end(), pi(i + l, 0));
            while (it != sameseq.begin()) {
                it--;
                if (it->second <= i) break;
                int len = min(i + l, it->second) - max(i, it->first);
                if (len >= k) {
                    exst = true;
                    break;
                }
            }
            if (exst) break;
        }
        if (!exst) {
            cout << l << '\n';
            break;
        }
    }
}