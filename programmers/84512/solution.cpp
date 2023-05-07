#include <string>
#include <vector>

using namespace std;

int skip[5] = {781, 156, 31, 6, 1};
char alpha[5] = {'A', 'E', 'I', 'O', 'U'};

int solution(string word) {
    int order = 0;
    for (int i = 0; i < word.size(); i++) {
        order++;
        for (char a: alpha) {
            if (a == word[i]) break;
            order += skip[i];
        }
    }
    return order;
}