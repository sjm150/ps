#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int q1, q2, q3, q4, a;
    q1 = q2 = q3 = q4 = a = 0;
    while (n--) {
        int x, y; cin >> x >> y;
        if (x == 0 || y == 0) {
            a++;
            continue;
        }
        if (x > 0) {
            if (y > 0) q1++;
            else q4++;
        } else {
            if (y > 0) q2++;
            else q3++;
        }
    }
    cout << "Q1: " << q1 << '\n';
    cout << "Q2: " << q2 << '\n';
    cout << "Q3: " << q3 << '\n';
    cout << "Q4: " << q4 << '\n';
    cout << "AXIS: " << a << '\n';
}