#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c; cin >> a >> b >> c;
    if (b % a || c % a) {
        cout << "둘다틀렸근\n";
        return 0;
    }
    b /= a, c /= a;
    auto exp2 = [](int x) {
        for (int i = 2; i <= x; i *= 2) {
            if (i == x) return true;
        }
        return false;
    };
    if (c >= 0) {
        for (int i = 0; i <= abs(b); i++) {
            if (i != abs(b) - i && i * (abs(b) - i) == c) {
                if (b < 0 && exp2(i) && exp2(abs(b) - i)) cout << "이수근\n";
                else cout << "정수근\n";
                return 0;
            }
        }
    } else {
        for (int i = 1; i * (abs(b) + i) <= -c; i++) {
            if (i * (abs(b) + i) == -c) {
                cout << "정수근\n";
                return 0;
            }
        }
    }
    cout << "둘다틀렸근\n";
}