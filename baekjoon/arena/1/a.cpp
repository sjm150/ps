#include <bits/stdc++.h>
using namespace std;

bool odd[10];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int i = 0; i < 5; i++) {
        int num; cin >> num;
        odd[num] = !odd[num];
    }
    for (int i = 0; i < 10; i++) {
        if (odd[i]) {
            cout << i << '\n';
            break;
        }
    }
}