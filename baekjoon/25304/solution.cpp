#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int total, n;
    cin >> total >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int price, num;
        cin >> price >> num;
        sum += price * num;
    }

    if (total == sum) cout << "Yes\n";
    else cout << "No\n";
}