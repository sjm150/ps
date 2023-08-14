#include <iostream>
using namespace std;
typedef long long ll;

ll f[91];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; i++) f[i] = f[i - 2] + f[i - 1];
    cout << f[n] << '\n';
}