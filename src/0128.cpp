class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(begin(nums), end(nums));
    int res = 0;
    for (auto& x : nums) {
      if (!s.count(x - 1)) {
        int cnt = 1;
        while (s.count(x + cnt)) {
          ++cnt;
        }
        res = max(res, cnt);
      }
    }
    return res;
  }
};
