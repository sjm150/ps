#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int m;
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        if (binary_search(a, a + n, num)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}