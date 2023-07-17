#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y;
        cin >> x >> y;
        bool able = true;
        while (k--) {
            int xx, yy;
            cin >> xx >> yy;
            if (!able) continue;
            if ((abs(x - xx) + abs(y - yy)) % 2 == 0) able = false;
        }
        if (able) cout << "YES\n";
        else cout << "NO\n";
    }
}