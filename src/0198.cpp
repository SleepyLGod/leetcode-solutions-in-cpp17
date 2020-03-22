class Solution {
 public:
  int rob(vector<int>& nums) {
    if (empty(nums)) {
      return 0;
    }
    vector<int> dp(size(nums) + 1);
    dp[1] = nums[0];
    for (int i = 2; i < size(dp); ++i) {
      dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    return dp[size(nums)];
  }
};
