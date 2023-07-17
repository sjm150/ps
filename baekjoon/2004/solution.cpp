#include <iostream>

using namespace std;

long long int cnt(int x, int m) {
    long long int ret = 0;
    for (long long int i = m; x / i > 0; i *= m) ret += x / i;
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    long long int cnt2 = cnt(n, 2) - cnt (m, 2) - cnt(n - m, 2);
    long long int cnt5 = cnt(n, 5) - cnt (m, 5) - cnt(n - m, 5);
    cout << min(cnt2, cnt5) << '\n';
}