#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int wmax = 0, hmax = 0;
    for (auto& size: sizes) {
        int w = max(size[0], size[1]);
        int h = min(size[0], size[1]);
        if (w > wmax) wmax = w;
        if (h > hmax) hmax = h;
    }
    return wmax * hmax;
}