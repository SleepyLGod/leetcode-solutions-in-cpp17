class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    dfs(res, nums, 0);
    return res;
  }

  void dfs(vector<vector<int>>& res, vector<int>& nums, int n) {
    if (n == size(nums)) {
      res.emplace_back(nums);
      return;
    }
    for (int i = n; i < size(nums); ++i) {
      swap(nums[i], nums[n]);
      dfs(res, nums, n + 1);
      swap(nums[i], nums[n]);
    }
  }
};
