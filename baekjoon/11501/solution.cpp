#include <iostream>

using namespace std;

int p[1000000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> p[i];
        int maxp = 0;
        long long int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += max(0, maxp - p[i]);
            maxp = max(maxp, p[i]);
        }
        cout << sum << '\n';
    }
}