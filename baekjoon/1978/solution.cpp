#include <iostream>

using namespace std;

bool notprime[1001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    notprime[1] = true;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 2 * i; j <= 1000; j += i) {
            notprime[j] = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (!notprime[num]) cnt++;
    }
    cout << cnt << '\n';
}