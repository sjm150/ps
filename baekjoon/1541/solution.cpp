#include <iostream>

using namespace std;

int num[25];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n = 0;
    while (!cin.eof()) cin >> num[n++];
    int sum = num[0];
    bool neg = false;
    for (int i = 1; i < n; i++) {
        if (num[i] < 0) neg = true;
        if (neg) sum -= abs(num[i]);
        else sum += num[i];
    }
    cout << sum << '\n';
}