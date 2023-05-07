#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string name) {
    int n = name.length();
    int move_ud = 0, move_rl = 0;
    for (char alpha: name) {
        move_ud += min(alpha - 'A', 'Z' + 1 - alpha);
    }

    int fclose = 0, bclose = n;
    int ffar = 0, bfar = n;
    for (int i = 1; i <= n / 2; i++) {
        if (name[i] != 'A') {
            if (fclose == 0) fclose = i;
            ffar = i;
        }
    }
    for (int i = n - 1; i > (n - 1) / 2; i--) {
        if (name[i] != 'A') {
            if (bclose == n) bclose = i;
            bfar = i;
        }
    }
    if (fclose + ffar != 0 || bclose != n || bfar != n)
        move_rl = min(min(bclose, n - fclose), 2 * min(ffar, n - bfar) + max(ffar, n - bfar));

    return move_ud + move_rl;
}