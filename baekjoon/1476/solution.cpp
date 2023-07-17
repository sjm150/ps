#include <iostream>

using namespace std;

const int emax = 15, smax = 28, mmax = 19;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int e, s, m;
    cin >> e >> s >> m;
    e--, s--, m--;
    for (int i = e; ; i += emax) {
        if (i % smax == s && i % mmax == m) {
            cout << i + 1 << '\n';
            break;
        }
    }
}