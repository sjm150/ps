#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x;
    cin >> x;
    int sum = 0, i = 1;
    while (sum + i < x) {
        sum += i;
        i++;
    }
    x -= sum;
    if (i % 2 == 0) cout << x << '/' << i + 1 - x << '\n';
    else cout << i + 1 - x << '/' << x << '\n';
}