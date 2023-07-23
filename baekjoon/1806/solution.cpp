#include <iostream>
#include <algorithm>
using namespace std;

int num[100000];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> num[i];
    int st = 0, en = 0;
    int sum = num[0];
    int mind = 2 * n;
    while (en < n) {
        if (sum < s) {
            en++;
            sum += num[en];
        } else {
            mind = min(mind, en + 1 - st);
            sum -= num[st];
            st++;
        }
    }
    if (mind == 2 * n) cout << 0 << '\n';
    else cout << mind << '\n';
}