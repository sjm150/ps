#include <iostream>
#include <algorithm>

using namespace std;

int v[10000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n);
    long long int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = v[i] + v[j];
            cnt += upper_bound(v + j + 1, v + n, -sum) - lower_bound(v + j + 1, v + n, -sum);
        }
    }
    cout << cnt << '\n';
}