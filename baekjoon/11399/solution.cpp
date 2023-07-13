#include <iostream>
#include <algorithm>

using namespace std;

int p[1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    int total_sum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p[i];
        total_sum += sum;
    }
    cout << total_sum << '\n';
}