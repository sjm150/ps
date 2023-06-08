#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int bytes;
    cin >> bytes;
    for (int i = 0; i <= (bytes - 1) / 4; i++) cout << "long ";
    cout << "int\n";
}