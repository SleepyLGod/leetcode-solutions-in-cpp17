class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int sz = size(matrix);
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
      reverse(begin(matrix[i]), end(matrix[i]));
    }
  }
};
