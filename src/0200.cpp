class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (empty(grid) || empty(grid[0])) {
      return 0;
    }
    int m = size(grid);
    int n = size(grid[0]);
    vector<int> p{MakeSet(m * n)};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int t = i * n + j;
        if (i + 1 < m && grid[i][j] == grid[i + 1][j]) {
          Union(p, t, t + n);
        }
        if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
          Union(p, t, t + 1);
        }
      }
    }
    int res = 0;
    for (int i = 0; i < size(p); ++i) {
      if (p[i] == i && grid[i / n][i % n] == '1') {
        ++res;
      }
    }
    return res;
  }

 private:
  vector<int> MakeSet(int n) {
    vector<int> res(n);
    iota(begin(res), end(res), 0);
    return res;
  }

  int FindSet(vector<int>& p, int i) {
    while (p[i] != i) {
      i = p[i];
    }
    return i;
  }

  void Union(vector<int>& p, int parent, int child) {
    p[FindSet(p, child)] = p[FindSet(p, parent)];
  }
};
