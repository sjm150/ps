#include <iostream>

using namespace std;

int n, m;
int num[100000];
int psum[100001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i];
    psum[0] = 0;
    for (int i = 1; i <= n; i++) psum[i] = psum[i - 1] + num[i - 1];
    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << psum[j] - psum[i - 1] << '\n';
    }
}