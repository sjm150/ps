#include <iostream>

using namespace std;

int main() {
    long long int N;
    cin >> N;
    int mod = N % 7;
    bool win = mod != 0 & mod != 2;
    cout << (win ? "SK" : "CY") << endl;
}