class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (empty(strs)) {
      return "";
    }
    string s{strs[0]};
    for (int i = 1; i < size(strs); ++i) {
      const string& x = strs[i];
      int cur = 0;
      while (s[cur] == x[cur]) {
        ++cur;
        if (cur == size(s) || cur == size(x)) {
          break;
        }
      }
      s = s.substr(0, cur);
    }
    return s;
  }
};
