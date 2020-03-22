class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (empty(board) || empty(board[0]) || empty(word)) {
      return false;
    }
    for (int i = 0; i < size(board); ++i) {
      for (int j = 0; j < size(board[0]); ++j) {
        if (dfs(board, i, j, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, int i, int j, string_view word, int n) {
    if (board[i][j] != word[n]) {
      return false;
    }
    if (n == size(word) - 1) {
      return true;
    }
    char t = board[i][j];
    board[i][j] = '#';
    if (i > 0 && dfs(board, i - 1, j, word, n + 1)) {
      return true;
    }
    if (i + 1 < size(board) && dfs(board, i + 1, j, word, n + 1)) {
      return true;
    }
    if (j > 0 && dfs(board, i, j - 1, word, n + 1)) {
      return true;
    }
    if (j + 1 < size(board[0]) && dfs(board, i, j + 1, word, n + 1)) {
      return true;
    }
    board[i][j] = t;
    return false;
  }
};
