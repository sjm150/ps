#include <iostream>
using namespace std;

string s, p;
int pi[1000000];
void init() {
    int j = 0;
    pi[0] = -1;
    for (int i = 1; i < p.size(); i++) {
        if (p[i] == p[j]) {
            pi[i] = pi[j];
        } else {
            pi[i] = j;
            while (j >= 0 && p[i] != p[j]) j = pi[j];
        }
        j++;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> s >> p;
    init();
    bool find = false;
    int i = 0, j = 0;
    while (i < s.size()) {
        if (j < 0 || s[i] == p[j]) {
            i++, j++;
            if (j == p.size()) {
                find = true;
                break;
            }
        } else {
            j = pi[j];
        }
    }
    cout << (find ? 1 : 0) << '\n';
}