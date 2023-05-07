#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    vector<set<int>> combs(9);
    int concat = N;
    for (int i = 1; i <= 8; i++) {
        if (concat == number) return i;
        combs[i].emplace(concat);
        concat = concat * 10 + N;
    }
    
    for (int i = 2; i <= 8; i++) {
        auto& curr = combs[i];
        for (int j = 1; j <= i / 2; j++) {
            int k = i - j;
            for (int jnum: combs[j]) {
                for (int knum: combs[k]) {
                    if (knum + jnum == number) return i;
                    curr.emplace(knum + jnum);
                    if (abs(knum - jnum) == number) return i;
                    curr.emplace(abs(knum - jnum));
                    if (knum * jnum == number) return i;
                    curr.emplace(knum * jnum);
                    if (jnum) {
                        if (knum / jnum == number) return i;
                        curr.emplace(knum / jnum);
                    }
                    if (knum) {
                        if (jnum / knum == number) return i;
                        curr.emplace(jnum / knum);
                    }
                }
            }
        }
    }
    
    return -1;
}