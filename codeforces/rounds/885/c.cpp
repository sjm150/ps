#include <iostream>

using namespace std;

int a[100000], b[100000];

int get_mod3(int x, int y) {
    if (x == 0) return 0;
    if (y == 0) return 1;
    if (x <= y) return (get_mod3(y, y - x) + 1) % 3;
    int k = x / y;
    int r = x % y;
    if (k % 2 == 1) return (get_mod3(y, r) + 1) % 3;
    else return get_mod3(r, y);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int ztype = -1;
        for (int i = 0; i < n; i++) {
            int cura = a[i], curb = b[i];
            if (cura == 0 && curb == 0) continue;
            int z = get_mod3(cura, curb);
            if (ztype < 0) {
                ztype = z;
            } else {
                if (ztype != z) {
                    ztype = -2;
                    break;
                }
            }
        }
        if (ztype == -2) cout << "NO\n";
        else cout << "YES\n";
    }
}