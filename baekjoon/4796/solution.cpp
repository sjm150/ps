#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for (int t = 1; ; t++) {
        int l, p, v;
        cin >> l >> p >> v;
        if (l == 0) break;
        cout << "Case " << t << ": " <<  v / p * l + min(v % p, l) << '\n';
    }
}