#include <iostream>

using namespace std;

int n;
int num[1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    num[0] = 1;
    num[1] = 2;
    for (int i = 2; i < n; i++) {
        num[i] = (num[i - 1] + num[i - 2]) % 10007;
    }
    cout << num[n - 1] << '\n';
}