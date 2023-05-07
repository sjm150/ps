#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int n = number.length();
    string maxnum;

    int last_sel = -1;
    for (int i = 0; i < n - k; i++) {
        int max_idx = last_sel + 1;
        for (int j = max_idx; j <= i + k; j++) {
            if (number[j] == '9') {
                max_idx = j;
                goto push_char;
            } else if (number[j] > number[max_idx]) {
                max_idx = j;
            }
        }
        
        push_char:
        maxnum += number[max_idx];
        last_sel = max_idx;
    }
    
    return maxnum;
}