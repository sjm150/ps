#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<char> tar(n), str(n);
    for (int i = 0; i < n; i++) cin >> tar[i];
    for (int i = 0; i < n; i++) cin >> str[i];
    vector<int> pi(n);
    pi[0] = -1;
    int i = 1, j = 0;
    while (i < n) {
        if (tar[i] == tar[j]) {
            pi[i] = pi[j];
        } else {
            pi[i] = j;
            while (j >= 0 && tar[i] != tar[j]) j = pi[j];
        }
        i++, j++;
    }
    int cnt;
    if (n % (n - j)) cnt = 1;
    else cnt = n / (n - j);
    int g = gcd(cnt, n);
    cout << cnt / g << '/' << n / g << '\n';
}