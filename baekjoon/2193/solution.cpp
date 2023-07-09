#include <iostream>

using namespace std;

long long int num[90];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i < n; i++) {
        num[i] = num[i - 1] + num[i - 2];
    }
    cout << num[n - 1] << '\n';
}