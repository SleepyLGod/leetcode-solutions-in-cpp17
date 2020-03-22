class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    if (empty(board) || empty(board[0])) {
      return 0;
    }
    int m = size(board);
    int n = size(board[0]);
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] != 'X') &&
            ((j == 0) || board[i][j - 1] != 'X')) {
          ++res;
        }
      }
    }
    return res;
  }
};