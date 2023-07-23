#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int pre, mind = INT32_MAX;
        cin >> pre;
        for (int i = 1; i < n; i++) {
            int cur;
            cin >> cur;
            mind = min(mind, cur - pre);
            pre = cur;
        }
        if (mind < 0) cout << 0 << '\n';
        else cout << mind / 2 + 1 << '\n';
    }
}