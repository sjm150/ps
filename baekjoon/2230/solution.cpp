#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int s = 0, e = 0;
    int mind = INT32_MAX;
    while (e < n) {
        if (a[e] - a[s] < m) {
            e++;
        } else {
            mind = min(mind, a[e] - a[s]);
            s++;
        }
    }
    cout << mind << '\n';
}