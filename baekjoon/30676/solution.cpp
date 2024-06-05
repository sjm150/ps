#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l; cin >> l;
    if (l >= 620) cout << "Red\n";
    else if (l >= 590) cout << "Orange\n";
    else if (l >= 570) cout << "Yellow\n";
    else if (l >= 495) cout << "Green\n";
    else if (l >= 450) cout << "Blue\n";
    else if (l >= 425) cout << "Indigo\n";
    else cout << "Violet\n";
}