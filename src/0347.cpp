class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto& x : nums) {
      ++m[x];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    for (auto& x : m) {
      q.emplace(x.second, x.first);
      if (size(q) > k) {
        q.pop();
      }
    }
    vector<int> res;
    while (!empty(q)) {
      res.emplace_back(q.top().second);
      q.pop();
    }
    return res;
  }
};
