class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
    vector<bool> dp(size(s) + 1);
    dp[0] = true;
    for (int i = 1; i < size(dp); ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && wordSet.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp.back();
  }
};
