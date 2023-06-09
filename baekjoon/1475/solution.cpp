#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int count[10] = {0,};
    while (n > 0) {
        count[n % 10]++;
        n /= 10;
    }

    int req = (count[6] + count[9] + 1) / 2;
    for (int i = 0; i < 9; i++) {
        if (i != 6) req = max(req, count[i]);
    }

    cout << req << '\n';
}