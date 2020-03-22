class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (empty(nums)) {
      return 0;
    }
    vector<int> dp(size(nums));
    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1; i < size(dp); ++i) {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      res = max(res, dp[i]);
    }
    return res;
  }
};
