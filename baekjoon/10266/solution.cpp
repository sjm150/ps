#include <bits/stdc++.h>
using namespace std;
const int mod = 360000;

void diff(vector<int>& a, vector<int>& d) {
    for (int i = 0; i < a.size() - 1; i++) d[i] = a[i + 1] - a[i];
    d[a.size() - 1] = a[0] - a[a.size() - 1] + mod;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n), d1(n), d2(2 * n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    diff(a, d1);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    diff(a, d2);
    for (int i = 0; i < n; i++) d2[i + n] = d2[i];

    vector<int> pi(n);
    pi[0] = -1;
    int i = 1, j = 0;
    while (i < n) {
        if (d1[i] == d1[j]) {
            pi[i] = pi[j];
        } else {
            pi[i] = j;
            while (j >= 0 && d1[i] != d1[j]) j = pi[j];
        }
        i++, j++;
    }

    i = 0, j = 0;
    while (i < 2 * n) {
        if (j < 0 || d2[i] == d1[j]) {
            i++, j++;
            if (j == n) {
                cout << "possible\n";
                return 0;
            }
        } else {
            j = pi[j];
        }
    }
    cout << "impossible\n";
}