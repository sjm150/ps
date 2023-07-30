#include <iostream>
#include <algorithm>
using namespace std;

int d[300000];
int round(double x) {
    return x + 0.500001;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int rm = round(n * 0.15);
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d, d + n);
    int sum = 0;
    for (int i = rm; i < n - rm; i++) sum += d[i];
    cout << round(double(sum) / (n - 2 * rm)) << '\n';
}