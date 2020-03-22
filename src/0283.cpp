class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int l = 0;
    int cur = 0;
    while (cur < size(nums)) {
      if (nums[cur] == 0) {
        ++cur;
      } else {
        nums[l++] = nums[cur++];
      }
    }
    for (int i = l; i < size(nums); ++i) {
      nums[i] = 0;
    }
  }
};
