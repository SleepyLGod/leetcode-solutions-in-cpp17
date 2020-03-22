class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = size(nums);
    n = n * (n + 1) / 2;
    return accumulate(begin(nums), end(nums), n, minus<int>{});
  }
};
