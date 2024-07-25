#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    long long ans = 0;
    int pre = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] <= a[i]) {
            int d = 0;
            for (int j = a[i - 1]; j <= a[i]; j *= 2) d++;
            pre = max(0, pre - d + 1);
        } else {
            int d = 0;
            for (int j = a[i]; j < a[i - 1]; j *= 2) d++;
            pre += d;
        }
        ans += pre;
    }

    cout << ans << '\n';
}