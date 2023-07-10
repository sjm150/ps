#include <iostream>

using namespace std;

const int mod = 1000000;
int sec[5001], num[5001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n; i++) sec[i] = s[i - 1] - '0';
    num[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (sec[i] != 0) num[i] = num[i - 1];
        int n = sec[i - 1] * 10 + sec[i];
        if (10 <= n && n <= 26) num[i] = (num[i] + num[i - 2]) % mod;
        if (num[i] == 0) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << num[s.length()] << '\n';
}