#include <string>
#include <vector>

using namespace std;

typedef struct Piece {
    int w;
    int h;
    int size;
    vector<vector<int>> shape;
} piece_t;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

pair<pair<int, int>, pair<int, int>> range_dfs(vector<vector<int>>& game_board, int x, int y, int offset) {
    int n = game_board.size();
    int xmin = x, xmax = x;
    int ymin = y, ymax = y;
    game_board[x][y] = 1 - offset;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n &&
           0 <= ny && ny < n &&
           game_board[nx][ny] == offset) {
            auto res = range_dfs(game_board, nx, ny, offset);
            xmin = min(xmin, res.first.first);
            ymin = min(ymin, res.first.second);
            xmax = max(xmax, res.second.first);
            ymax = max(ymax, res.second.second);
        }
    }
    
    return pair(pair(xmin, ymin), pair(xmax, ymax));
}

int shape_dfs(vector<vector<int>>& game_board, vector<vector<int>>& shape, int x, int y, int xmin, int ymin, int offset) {
    int n = game_board.size();
    int size = 1;
    game_board[x][y] = 1 - offset;
    shape[x - xmin][y - ymin] = 1;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n &&
           0 <= ny && ny < n &&
           game_board[nx][ny] == offset) size += shape_dfs(game_board, shape, nx, ny, xmin, ymin, offset);
    }
    
    return size;
}

piece_t piece_dfs(vector<vector<int>>& game_board, int x, int y, int offset) {
    vector<vector<int>> clone(game_board);
    auto res = range_dfs(clone, x, y, offset);
    int xmin = res.first.first;
    int ymin = res.first.second;
    int xmax = res.second.first;
    int ymax = res.second.second;
    
    int w = xmax - xmin + 1;
    int h = ymax - ymin + 1;
    vector<vector<int>> shape(w, vector<int>(h, 0));
    int size = shape_dfs(game_board, shape, x, y, xmin, ymin, offset);
    
    return Piece { w, h, size, shape };
}

bool fits(piece_t& slot, piece_t& piece) {
    if (slot.size != piece.size) return false;
    int w = slot.w;
    int h = slot.h;

    if (w == piece.w && h == piece.h) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (slot.shape[i][j] != piece.shape[i][j]) goto upsidedown;
            }
        }
        return true;
        
        upsidedown:
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (slot.shape[i][j] != piece.shape[w - 1 - i][h - 1 - j]) goto oddturn;
            }
        }
        return true;
    }
    
    oddturn:
    if (w == piece.h && h == piece.w) {
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (slot.shape[i][j] != piece.shape[h - 1 - j][i]) goto threeturn;
            }
        }
        return true;
        
        threeturn:
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (slot.shape[i][j] != piece.shape[j][w - 1 - i]) return false;
            }
        }
        return true;
    }
    
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int n = game_board.size();
    vector<piece_t> slots;
    vector<piece_t> pieces;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0) slots.push_back(piece_dfs(game_board, i, j, 0));
            if (table[i][j] == 1) pieces.push_back(piece_dfs(table, i, j, 1));
        }
    }
    
    vector<bool> matched(pieces.size(), false);
    int size = 0;
    for (auto& slot: slots) {
        for (int i = 0; i < pieces.size(); i++) {
            if (!matched[i] && fits(slot, pieces[i])) {
                matched[i] = true;
                size += slot.size;
                break;
            }
        }
    }

    return size;
}