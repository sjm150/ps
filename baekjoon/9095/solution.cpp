#include <iostream>

using namespace std;

int cache[12];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    cache[0] = 1;
    for (int i = 1; i <= 11; i++) {
        cache[i] += cache[i - 1];
        if (i >= 2) cache[i] += cache[i - 2];
        if (i >= 3) cache[i] += cache[i - 3];
    }
    while (t--) {
        int n;
        cin >> n;
        cout << cache[n] << '\n';
    }
}