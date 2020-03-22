class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (size(prices) <= 1) {
      return 0;
    }
    vector<int> dp(size(prices));
    for (int i = 1; i < size(dp); ++i) {
      dp[i] = max(dp[i - 1], dp[i - 1] + prices[i] - prices[i - 1]);
    }
    return dp.back();
  }
};
