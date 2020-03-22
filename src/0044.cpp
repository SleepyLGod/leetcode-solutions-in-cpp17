class Solution {
 public:
  bool isMatch(string s, string p) {
    int i = 0;
    int j = 0;
    int markS = -1;
    int markP = -1;
    while (i < size(s)) {
      if (j < size(p) && (s[i] == p[j] || p[j] == '?')) {
        ++i;
        ++j;
      } else if (j < size(p) && p[j] == '*') {
        markS = i;
        markP = j;
        ++j;
      } else if (markP != -1) {
        i = ++markS;
        j = markP + 1;
      } else {
        return false;
      }
    }
    while (j < size(p) && p[j] == '*') {
      ++j;
    }
    return j == size(p);
  }
};
