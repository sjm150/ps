#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int cnt = 0;
    while (n--) {
        int x; cin >> x;
        if (x) cnt++;
        else cnt--;
    }
    cout << (cnt > 0 ? "Junhee is cute!\n" : "Junhee is not cute!\n");
}