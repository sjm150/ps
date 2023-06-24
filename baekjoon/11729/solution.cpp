#include <iostream>
#include <vector>

using namespace std;


void print_move(int from, int to, int num) {
    if (num == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    print_move(from, 6 - from - to, num - 1);
    print_move(from, to, 1);
    print_move(6 - from - to, to, num - 1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    print_move(1, 3, n);
}