#include <iostream>

using namespace std;

int out[200000];

bool not_prime[200001];
void init() {
    for (int i = 2; i <= 200000; i++) {
        for (int j = i * 2; j <= 200000; j += i) {
            not_prime[j] = true;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int s = 0, e = n - 1;
        int m = (s + e + 1) / 2;
        int ml = m - 1, mr = m + 1;
        out[m] = 1;
        int curr = 2;
        while (s <= ml) {
            if (not_prime[curr]) out[ml--] = curr++;
            else out[s++] = curr++;
            if (mr > e) break;
            if (not_prime[curr]) out[mr++] = curr++;
            else out[e--] = curr++;
        }
        for (int i = 0; i < n; i++) cout << out[i] << ' ';
        cout << '\n';
    }
}