#include <iostream>
#include <unordered_set>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int N;
    std::unordered_set<int> cards;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int card;
        std::cin >> card;
        cards.insert(card);
    }

    std::cin >> N;
    for (int i = 0; i < N-1; i++) {
        int card;
        std::cin >> card;
        std::cout << ( (cards.find(card) != cards.end()) ? 1 : 0 ) << " ";
    }
    int card;
    std::cin >> card;
    std::cout << ( (cards.find(card) != cards.end()) ? 1 : 0 ) << std::endl;

    return 0;
}
