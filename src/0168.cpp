class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string res;
    while (columnNumber) {
      int t = columnNumber % 26;
      if (!t) {
        res.insert(begin(res), 'Z');
        columnNumber = columnNumber / 26 - 1;
      } else {
        res.insert(begin(res), 'A' + t - 1);
        columnNumber /= 26;
      }
    }
    return res;
  }
};
