#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int open_brackets = 0;
    for (char c: s) {
        if (c == '(') {
            open_brackets++;
        } else {
            if (open_brackets == 0) return false;
            open_brackets--;
        }
    }
    
    return open_brackets == 0;
}