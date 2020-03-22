class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (empty(matrix) || empty(matrix[0])) {
      return;
    }

    bool first_row_has_zero =
        any_of(begin(matrix[0]), end(matrix[0]), [](int x) { return !x; });

    bool first_col_has_zero =
        any_of(begin(matrix), end(matrix),
               [&](const vector<int>& x) { return !x[0]; });

    int m = size(matrix);
    int n = size(matrix[0]);

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (!matrix[i][j]) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (!matrix[i][0] || !matrix[0][j]) {
          matrix[i][j] = 0;
        }
      }
    }
    if (first_row_has_zero) {
      for_each(begin(matrix[0]), end(matrix[0]), [](int& x) { x = 0; });
    }
    if (first_col_has_zero) {
      for_each(begin(matrix), end(matrix), [&](vector<int>& x) { x[0] = 0; });
    }
  }
};
