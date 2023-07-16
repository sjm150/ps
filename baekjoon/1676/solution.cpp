#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int cnt2 = 0, cnt5 = 0;
    for (int i = 2; i <= n; i++) {
        int num = i;
        while (num % 2 == 0) {
            num /= 2;
            cnt2++;
        }
        while (num % 5 == 0) {
            num /= 5;
            cnt5++;
        }
    }
    cout << min(cnt2, cnt5) << '\n';
}