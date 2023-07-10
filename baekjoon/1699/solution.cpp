#include <iostream>

using namespace std;

int num[100001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++) num[i * i] = 1;
    for (int i = 2; i <= n; i++) {
        if (num[i] > 0) continue;
        num[i] = i;
        for (int j = 1; i - j * j > 0; j++) {
            num[i] = min(num[i], num[i - j * j] + 1);
        }
    }
    cout << num[n] << '\n';
}