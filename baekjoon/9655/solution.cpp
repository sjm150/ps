#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << ((n % 2 == 1) ? "SK" : "CY") << '\n';
}