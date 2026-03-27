#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.size();
    auto solve = [&]() {
        for (int i = n / 2 * 2; i; i -= 2) {
            int l = accumulate(s.begin(), s.begin() + i / 2, 0) - '0' * (i / 2);
            int r = accumulate(s.begin() + i / 2, s.begin() + i, 0) - '0' * (i / 2);
            if (l == r) return i;
            for (int j = i; j < n; j++) {
                l += s[j - i / 2] - s[j - i];
                r += s[j] - s[j - i / 2];
                if (l == r) return i;
            }
        }
        return 0;
    };
    cout << solve() << '\n';
}