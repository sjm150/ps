#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int count = 0;
    char last = ' ';
    bool was_vowel = false;
    bool was_double = false;
    bool able = false;

    unordered_set<char> top;
    unordered_set<char> mid;
    for (char c : {'r', 'R', 's', 'e', 'f', 'a', 'q', 't', 'T', 'd', 'w', 'c', 'z', 'x', 'v', 'g'}) {
        top.insert(c);
    }
    for (char c : {'k', 'o', 'i', 'O', 'j', 'p', 'u', 'P', 'h', 'y', 'n', 'b', 'm', 'l'}) {
        mid.insert(c);
    }

    string buf;
    getline(cin, buf);

    for (char c : buf) {
        if (was_vowel) {
            if (top.find(c) != top.end()) {
                able = true;
                was_vowel = false;
            } else if (mid.find(c) != mid.end()) {
                able = false;
            } else {
                able = false;
                was_vowel = false;
            }
            was_double = false;
        } else {
            if (able) {
                if (mid.find(c) != mid.end()) {
                    count++;
                    
                    able = false;
                    was_vowel = true;
                } else {
                    switch (last) {
                        case 'r':
                            if (was_double || c != 't') {
                                able = false;
                            } else {
                                was_double = true;
                            }
                            break;
                        case 's':
                            if (was_double || (c != 'w' && c != 'g')) {
                                able = false;
                            } else {
                                was_double = true;
                            }
                            break;
                        case 'f':
                            if (was_double || (c != 'r' && c != 'a' && c != 'q' && c != 't' && c != 'x' && c != 'v' && c != 'g')) {
                                able = false;
                            } else {
                                was_double = true;
                            }
                            break;
                        case 'q':
                            if (was_double || c != 't') {
                                able = false;
                            } else {
                                was_double = true;
                            }
                            break;
                        default:
                            able = false;
                            break;
                    }
                }
            } else {
                if (mid.find(c) != mid.end()) {
                    was_vowel = true;
                }
            }
        }

        last = c;
    }

    cout << count << endl;
}