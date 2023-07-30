#include <iostream>
using namespace std;
typedef long long ll;

const int r = 31;
const int m = 1234567891;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int l; string s; cin >> l >> s;
    ll hash = 0;
    for (int i = l - 1; i >= 0; i--) hash = (hash * r + (s[i] - 'a' + 1)) % m;
    cout << hash << '\n';
}