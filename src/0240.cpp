class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (empty(matrix) || empty(matrix[0])) {
      return false;
    }
    int m = size(matrix);
    int n = size(matrix[0]);
    int i = m - 1;
    int j = 0;
    while (i >= 0 && j <= n - 1) {
      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] < target) {
        ++j;
      } else {
        --i;
      }
    }
    return false;
  }
};
