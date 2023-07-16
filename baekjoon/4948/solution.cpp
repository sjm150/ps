#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    vector<bool> prime(246913, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < 246913; i++) {
        if (!prime[i]) continue;
        for (int j =  i * i; j < 246913; j += i) prime[j] = false;
    }
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (prime[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}