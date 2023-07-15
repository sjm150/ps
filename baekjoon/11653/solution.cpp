#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 2; n > 1; i++) {
        while (n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
}