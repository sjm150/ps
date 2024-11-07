#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size(), sum = 0;
    for (int i = 0; i < n / 2; i++) sum += s[i] - 'A';
    for (int i = 0; i < n / 2; i++) s[i] = (s[i] - 'A' + sum) % 26 + 'A';
    sum = 0;
    for (int i = n / 2; i < n; i++) sum += s[i] - 'A';
    for (int i = n / 2; i < n; i++) s[i] = (s[i] - 'A' + sum) % 26 + 'A';
    for (int i = 0; i < n / 2; i++) cout << char((s[i] + s[i + n / 2] - 2 * 'A') % 26 + 'A');
    cout << '\n';
}