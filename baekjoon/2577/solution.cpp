#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;

    int mul = a * b * c;
    int count[10] = {0,};
    while (mul > 0) {
        count[mul % 10]++;
        mul /= 10;
    }

    for (int c: count) cout << c << '\n';
}