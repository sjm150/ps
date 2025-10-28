#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        string s;
        getline(cin, s);
        if (s == "EOI") break;
        for (char &c: s) {
            if ('a' <= c && c <= 'z') c += 'A' - 'a';
        }
        cout << (s.find("NEMO") != string::npos ? "Found\n" : "Missing\n");
    }
}