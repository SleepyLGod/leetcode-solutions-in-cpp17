class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(begin(people), end(people), [](vector<int>& x, vector<int>& y) {
      return tie(y[0], x[1]) < tie(x[0], y[1]);
    });
    vector<vector<int>> res;
    for (auto& x : people) {
      res.emplace(begin(res) + x[1], x);
    }
    return res;
  }
};
