#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char alph[15];
char pswd[15];
int num_vowel, num_conso;

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void print() {
    for (int i = 0; i < l; i++) cout << pswd[i];
    cout << '\n';
}

void select(int min_i, int selected) {
    if (selected == l) {
        if (num_vowel >= 1 && num_conso >= 2) print();
        return;
    }
    for (int i = min_i; i < c; i++) {
        bool v = is_vowel(alph[i]);
        v ? num_vowel++ : num_conso++;
        pswd[selected] = alph[i];
        select(i + 1, selected + 1);
        v ? num_vowel-- : num_conso--;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> l >> c;
    for (int i = 0; i < c; i++) cin >> alph[i];
    sort(alph, alph + c);
    select(0, 0);
}