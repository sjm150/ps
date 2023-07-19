#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    n--;
    while (n--) {
        int num;
        cin >> num;
        int g = gcd(m, num);
        cout << m / g << '/' << num / g << '\n';
    }
}