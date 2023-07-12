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
        int min_ndn = n;
        for (int i = 1; i <= n; i++) {
            if (n % i != 0) {
                min_ndn = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) cout << (char) ('a' + i % min_ndn);
        cout << '\n';
    }
}