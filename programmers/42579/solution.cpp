#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    // genre name -> genre total play, genre song play rank
    map<string, pair<int, priority_queue<pair<int, int>>>> ranks;
    for (int i = 0; i < genres.size(); i++) {
        string& genre = genres[i];
        int play = plays[i];
        
        auto it = ranks.find(genre);
        if (it == ranks.end()) {
            priority_queue<pair<int, int>> genresong_rank;
            genresong_rank.push(pair(play, -i));
            ranks.insert(pair(genre, pair(play, genresong_rank)));
        } else {
            int& total_play = it->second.first;
            auto& genresong_rank = it->second.second;
            total_play += play;
            genresong_rank.push(pair(play, -i));
        }
    }
    
    priority_queue<pair<int, string>> genre_rank;
    for (auto& p: ranks) {
        const string& genre_name = p.first;
        int total_play = ranks.find(genre_name)->second.first;
        genre_rank.push(pair(total_play, genre_name));
    }
    
    vector<int> best_songs;
    while (!genre_rank.empty()) {
        string genre_name = genre_rank.top().second;
        genre_rank.pop();
        
        auto& genresong_rank = ranks.find(genre_name)->second.second;
        for (int i = 0; i < 2; i++) {
            if (genresong_rank.empty()) break;
            best_songs.push_back(-genresong_rank.top().second);
            genresong_rank.pop();
        }
    }
    
    return best_songs;
}