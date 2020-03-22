class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (empty(envelopes)) {
      return 0;
    }
    sort(begin(envelopes), end(envelopes),
         [](auto& x, auto& y) { return tie(x[0], y[1]) < tie(y[0], x[1]); });
    vector<int> v{envelopes[0][1]};
    for (int i = 1; i < size(envelopes); ++i) {
      if (envelopes[i][1] > v.back()) {
        v.emplace_back(envelopes[i][1]);
      } else {
        *lower_bound(begin(v), end(v), envelopes[i][1]) = envelopes[i][1];
      }
    }
    return size(v);
  }
};
