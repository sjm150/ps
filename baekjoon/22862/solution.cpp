#include <iostream>
using namespace std;

int s[1000000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> s[i];
    int st = 0, en = 0;
    int ocnt = s[0] % 2 == 0 ? 0 : 1;
    int maxlen = 1 - ocnt;
    while (en < n) {
        if (ocnt <= k) {
            en++;
            if (en == n) break;
            if (s[en] % 2 == 0) maxlen = max(maxlen, en - st + 1 - ocnt);
            else ocnt++;
        } else {
            if (s[st] % 2 == 1) {
                ocnt--;
                if (ocnt <= k) maxlen = max(maxlen, en - st - ocnt);
            }
            st++;
        }
    }
    cout << maxlen << '\n';
}