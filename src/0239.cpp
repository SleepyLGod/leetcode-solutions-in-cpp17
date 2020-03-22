class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> d;
    for (int i = 0; i < size(nums); ++i) {
      if (!empty(d) && i - d.front() >= k) {
        d.pop_front();
      }
      while (!empty(d) && nums[i] >= nums[d.back()]) {
        d.pop_back();
      }
      d.emplace_back(i);
      if (i >= k - 1) {
        res.emplace_back(nums[d.front()]);
      }
    }
    return res;
  }
};
