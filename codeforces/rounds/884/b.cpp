#include <iostream>

using namespace std;

bool not_prime[200002];
void init() {
    for (int i = 2; i <= 200001; i++) {
        for (int j = i * 2; j <= 200001; j += i) {
            not_prime[j] = true;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int curr = 4;
        for (int i = 0; i < n; i++) {
            if (i == n / 2) cout << 1 << ' ';
            else if (i == 0) cout << 2 << ' ';
            else if (i == n - 1) cout << 3 << ' ';
            else cout << curr++ << ' ';
        }
        cout << '\n';
    }
}