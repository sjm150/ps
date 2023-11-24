#include <string>
#include <vector>
#include <map>

using namespace std;

char types[8] = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
map<char, int> idx;
void init_idx() {
    idx['R'] = 0;
    idx['T'] = 1;
    idx['C'] = 2;
    idx['F'] = 3;
    idx['J'] = 4;
    idx['M'] = 5;
    idx['A'] = 6;
    idx['N'] = 7;
}

string solution(vector<string> survey, vector<int> choices) {
    init_idx();
    int scores[8] = {0};
    
    int n = survey.size();
    for (int i = 0; i < n; i++) {
        int c = choices[i];
        if (c < 4) scores[idx[survey[i][0]]] += 4 - c;
        else if (c > 4) scores[idx[survey[i][1]]] += c - 4;
    }
    
    string res = "";
    for (int i = 0; i < 8; i += 2) {
        if (scores[i] >= scores[i + 1]) res += types[i];
        else res += types[i + 1];
    }
    return res;
}