#include <iostream>

using namespace std;

bool notprime[1000001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int m, n;
    cin >> m >> n;
    notprime[1] = true;
    for (int i = 2; i <= n; i++) {
        if (notprime[i]) continue;
        for (int j = 2 * i; j <= n; j += i) notprime[j] = true;
    }
    for (int i = m; i <= n; i++) {
        if (!notprime[i]) cout << i << '\n';
    }
}