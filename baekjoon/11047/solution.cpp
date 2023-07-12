#include <iostream>

using namespace std;

int a[10];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    n--;
    int num = 0;
    while (k != 0) {
        if (k >= a[n]) {
            num += k / a[n];
            k %= a[n];
        } else {
            n--;
        }
    }
    cout << num << '\n';
}