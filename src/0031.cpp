class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (size(nums) <= 1) {
      return;
    }
    for (int i = size(nums) - 1; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        sort(begin(nums) + i, end(nums));
        for (int j = i; j < size(nums); ++j) {
          if (nums[j] > nums[i - 1]) {
            swap(nums[i - 1], nums[j]);
            return;
          }
        }
      }
    }
    reverse(begin(nums), end(nums));
  }
};
