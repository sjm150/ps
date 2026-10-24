class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i < 12; i++) d[i] += d[i - 1];
        auto cnv = [&](string &s) { return d[stoi(s.substr(0, 2)) - 1] + stoi(s.substr(3, 2)); };
        return max(0, min(cnv(leaveAlice), cnv(leaveBob)) - max(cnv(arriveAlice), cnv(arriveBob)) + 1);
    }
};