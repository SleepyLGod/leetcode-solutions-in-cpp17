class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> helper{nums};
    sort(begin(helper), end(helper));
    helper.erase(unique(begin(helper), end(helper)), end(helper));
    int sz = size(nums);
    init(sz + 1);
    vector<int> res;
    for (int i = sz - 1; i >= 0; --i) {
      int x = lower_bound(begin(helper), end(helper), nums[i]) - begin(helper);
      res.emplace_back(prefix_sum(x));
      add(x + 1, 1);
    }
    reverse(begin(res), end(res));
    return res;
  }

  void init(int n) {
    t.clear();
    t.resize(n);
    t.shrink_to_fit();
  }

  void add(int pos, int value) {
    while (pos < size(t)) {
      t[pos] += value;
      pos += lowbit(pos);
    }
  }

  int prefix_sum(int pos) const {
    int res = 0;
    while (pos) {
      res += t[pos];
      pos -= lowbit(pos);
    }
    return res;
  }

 private:
  int lowbit(int x) const { return x & (-x); }

 private:
  vector<int> t;
};
