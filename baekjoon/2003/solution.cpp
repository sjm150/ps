#include <iostream>
using namespace std;

int a[10000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int s = 0, e = 0;
    int sum = a[0];
    int cnt = 0;
    while (e < n) {
        if (sum == m) cnt++;
        if (sum < m) sum += a[++e];
        else sum -= a[s++];
    }
    cout << cnt << '\n';
}