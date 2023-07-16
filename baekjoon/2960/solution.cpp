#include <iostream>

using namespace std;

bool nprime[1001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        if (nprime[i]) continue;
        k--;
        if (k == 0) {
            cout << i << '\n';
            return 0;
        }
        for (int j = i * i; j <= n; j += i) {
            if (!nprime[j]) {
                k--;
                if (k == 0) {
                    cout << j << '\n';
                    return 0;
                }
                nprime[j] = true;
            }
        }
    }
}