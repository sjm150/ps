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
        int maxi = 0, maxq = 0;
        for (int i = 1; i <= n; i++) {
            int w, q;
            cin >> w >> q;
            if (w <= 10 && maxq < q) {
                maxi = i;
                maxq = q;
            }
        }
        cout << maxi << '\n';
    }
}