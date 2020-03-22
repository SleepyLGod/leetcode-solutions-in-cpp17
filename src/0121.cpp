class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (size(prices) <= 1) {
      return 0;
    }
    vector<int> dp(size(prices));
    int res = 0;
    for (int i = 1; i < size(dp); ++i) {
      dp[i] = max(dp[i - 1] + prices[i] - prices[i - 1], 0);
      res = max(res, dp[i]);
    }
    return res;
  }
};
