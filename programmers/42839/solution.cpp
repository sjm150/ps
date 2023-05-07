#include <string>
#include <vector>
#include <set>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void find_primes(int curr, set<int>& primes, vector<int>& list, vector<bool>& selected) {
    if (primes.find(curr) == primes.end() && is_prime(curr)) primes.insert(curr);
    for (int i = 0; i < list.size(); i++) {
        if (selected[i]) continue;
        selected[i] = true;
        find_primes(curr * 10 + list[i], primes, list, selected);
        selected[i] = false;
    }
}

int solution(string numbers) {
    int n = numbers.length();
    set<int> primes;
    vector<int> list;
    vector<bool> selected(n, false);
    
    for (char c: numbers) list.push_back(c - '0');
    find_primes(0, primes, list, selected);
    
    return primes.size();
}