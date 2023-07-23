#include <iostream>
typedef long long ll;
using namespace std;

int fib[30];
void init() {
    fib[1] = 1;
    for (int i = 2; i < 30; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << 1 << '\n';
            continue;
        } else if (k == 2) {
            cout << n + 1 << '\n';
            continue;
        } else if (k >= 30) {
            cout << 0 << '\n';
            continue;
        }
        int cnt = 0;
        for (int i = 0; i * fib[k - 1] <= n; i++) {
            int v = n - i * fib[k - 1];
            if (v % fib[k - 2] == 0 && v / fib[k - 2] <= i) cnt++;
        }
        cout << cnt << '\n';
    }
}