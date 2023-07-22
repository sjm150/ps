#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b >= 10 || b + c >= 10 || c + a >= 10) cout << "YES\n";
        else cout << "NO\n";
    }
}