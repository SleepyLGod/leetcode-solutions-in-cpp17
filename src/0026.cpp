class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (empty(nums)) {
      return 0;
    }
    int l = 0;
    for (int r = 1; r < size(nums); ++r) {
      if (nums[l] != nums[r]) {
        ++l;
        if (l < r) {
          nums[l] = nums[r];
        }
      }
    }
    return l + 1;
  }
};
