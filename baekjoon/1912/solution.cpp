#include <iostream>

using namespace std;

int num[100000], sum[100000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    int max_sum = sum[0] = num[0];
    for (int i = 1; i < n; i++) {
        sum[i] = max(0, sum[i - 1]) + num[i];
        max_sum = max(max_sum, sum[i]);
    }
    cout << max_sum << '\n';
}