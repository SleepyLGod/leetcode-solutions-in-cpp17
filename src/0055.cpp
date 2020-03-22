class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (empty(nums)) {
      return false;
    }
    if (size(nums) == 1 && nums[0] >= 0) {
      return true;
    }
    vector<int> dp(size(nums));
    dp[0] = nums[0];
    if (dp[0] == 0) {
      return false;
    }
    for (int i = 1; i < size(dp); ++i) {
      dp[i] = max(dp[i - 1] - 1, nums[i - 1]);
      if (dp[i] == 0) {
        return false;
      }
    }
    return true;
  }
};
