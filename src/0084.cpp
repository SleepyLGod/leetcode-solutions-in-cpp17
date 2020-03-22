class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    heights.emplace_back(0);
    stack<int> s;
    int res = 0;
    for (int i = 0; i < size(heights); ++i) {
      while (!empty(s) && heights[i] < heights[s.top()]) {
        int t = s.top();
        s.pop();
        res = max(res, heights[t] * (empty(s) ? i : (i - s.top() - 1)));
      }
      s.emplace(i);
    }
    return res;
  }
};
