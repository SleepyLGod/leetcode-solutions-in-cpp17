class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (empty(nums)) {
      return 0;
    }
    vector<int> v{nums[0]};
    for (int i = 1; i < size(nums); ++i) {
      if (nums[i] > v.back()) {
        v.emplace_back(nums[i]);
      } else {
        *lower_bound(begin(v), end(v), nums[i]) = nums[i];
      }
    }
    return size(v);
  }
};
