#include <iostream>

using namespace std;

long long int p[100];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    p[0] = p[1] = p[2] = 1;
    p[3] = p[4] = 2;
    p[5] = 3;
    for (int i = 6; i < 100; i ++) p[i] = p[i - 1] + p[i - 5];
    while (t--) {
        int n;
        cin >> n;
        cout << p[n - 1] << '\n';
    }
}