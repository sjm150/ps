#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int n = queue1.size();
    vector<int> tot(2 * n);
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        tot[i] = queue1[i];
        sum1 += queue1[i];
    }
    for (int i = 0; i < n; i++) {
        tot[i + n] = queue2[i];
        sum2 += queue2[i];
    }
    
    int idx1 = 0, idx2 = n;
    bool poss = false;
    int cnt = 0;
    while (true) {
        if (sum1 == sum2) {
            poss = true;
            break;
        } else if (sum1 > sum2) {
            sum1 -= tot[idx1];
            sum2 += tot[idx1];
            idx1++;
            if (idx1 == 2 * n) break;
        } else if (sum1 < sum2) {
            sum1 += tot[idx2];
            sum2 -= tot[idx2];
            idx2++;
            if (idx2 == 2 * n) idx2 = 0;
            if (idx2 == n) break;
        }
        cnt++;
    }
    
    if (poss) return cnt;
    else return -1;
}