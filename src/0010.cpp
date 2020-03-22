class Solution {
 public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> dp(size(s) + 1, vector<bool>(size(p) + 1));
    dp[0][0] = true;
    for (int i = 2; i < size(dp[0]); i += 2) {
      if (p[i - 1] != '*') {
        break;
      }
      dp[0][i] = true;
    }
    for (int i = 0; i < size(s); ++i) {
      for (int j = 0; j < size(p); ++j) {
        if (s[i] == p[j] || p[j] == '.') {
          dp[i + 1][j + 1] = dp[i][j];
        } else if (p[j] == '*') {
          dp[i + 1][j + 1] = dp[i + 1][j - 1];
          if (s[i] == p[j - 1] || p[j - 1] == '.') {
            dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i + 1][j] || dp[i][j + 1];
          }
        }
      }
    }
    return dp[size(s)][size(p)];
  }
};
