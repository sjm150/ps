#include <iostream>

using namespace std;

long long int pow(int a, int b, int c) {
    if (b == 1) return a % c;
    if (b % 2 == 0) {
        long long int temp = pow(a, b / 2, c);
        return temp * temp % c;
    } else {
        long long int temp = pow(a, b / 2, c);
        return temp * temp % c * a % c;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c) << '\n';
}