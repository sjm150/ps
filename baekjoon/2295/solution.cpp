#include <iostream>
#include <algorithm>

using namespace std;

int num[1000];
int sum[1000000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    int nn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[nn++] = num[i] + num[j];
        }
    }
    sort(sum, sum + nn);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (binary_search(sum, sum + nn, abs(num[i] - num[j]))) {
                ans = max(ans, max(num[i], num[j]));
            }
        }
    }
    cout << ans << '\n';
}