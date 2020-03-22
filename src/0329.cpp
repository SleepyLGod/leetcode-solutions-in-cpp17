class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (empty(matrix) || empty(matrix[0])) {
      return 0;
    }
    int m = size(matrix);
    int n = size(matrix[0]);
    vector<vector<int>> v(m, vector<int>(n));
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(matrix, i, j, v);
        res = max(res, v[i][j]);
      }
    }
    return res;
  }

  int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& v) {
    if (v[i][j]) {
      return v[i][j];
    }
    int t = 0;
    if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
      t = dfs(matrix, i - 1, j, v) + 1;
      v[i][j] = max(v[i][j], t);
    }
    if (i + 1 < size(matrix) && matrix[i][j] < matrix[i + 1][j]) {
      t = dfs(matrix, i + 1, j, v) + 1;
      v[i][j] = max(v[i][j], t);
    }
    if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
      t = dfs(matrix, i, j - 1, v) + 1;
      v[i][j] = max(v[i][j], t);
    }
    if (j + 1 < size(matrix[0]) && matrix[i][j] < matrix[i][j + 1]) {
      t = dfs(matrix, i, j + 1, v) + 1;
      v[i][j] = max(v[i][j], t);
    }
    v[i][j] = max(v[i][j], 1);
    return v[i][j];
  }
};