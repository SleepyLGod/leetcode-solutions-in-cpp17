class Trie {
 public:
  void insert(string word) {
    Trie* t = this;
    for (auto& x : word) {
      if (!t->next[x - 'a']) {
        t->next[x - 'a'] = new Trie;
      }
      t = t->next[x - 'a'];
    }
    t->word = word;
  }

 public:
  vector<Trie*> next{vector<Trie*>(26)};
  string word;
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    if (empty(board) || empty(board[0])) {
      return res;
    }
    Trie* trie = new Trie;
    for (auto& x : words) trie->insert(x);
    for (int i = 0; i < size(board); ++i) {
      for (int j = 0; j < size(board[0]); ++j) {
        dfs(board, i, j, trie, res);
      }
    }
    return res;
  }

  void dfs(vector<vector<char>>& board, int i, int j, Trie* trie,
           vector<string>& res) {
    if (board[i][j] != '#' && trie->next[board[i][j] - 'a']) {
      trie = trie->next[board[i][j] - 'a'];
      if (!empty(trie->word)) {
        res.emplace_back(trie->word);
        trie->word.clear();
      }
      char t = board[i][j];
      board[i][j] = '#';
      if (i > 0) {
        dfs(board, i - 1, j, trie, res);
      }
      if (i + 1 < size(board)) {
        dfs(board, i + 1, j, trie, res);
      }
      if (j > 0) {
        dfs(board, i, j - 1, trie, res);
      }
      if (j + 1 < size(board[0])) {
        dfs(board, i, j + 1, trie, res);
      }
      board[i][j] = t;
    }
  }
};
