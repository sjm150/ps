#include <iostream>

using namespace std;

int num[1000], sum[1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    int max_sum = sum[0] = num[0];
    for (int i = 1; i < n; i++) {
        sum[i] = num[i];
        for (int j = 0; j < i; j++) {
            if (num[i] > num[j]) sum[i] = max(sum[i], sum[j] + num[i]);
        }
        max_sum = max(max_sum, sum[i]);
    }
    cout << max_sum << '\n';
}