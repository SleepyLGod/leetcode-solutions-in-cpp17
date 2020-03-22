class Solution {
 public:
  void reverseString(vector<char>& s) {
    int l = 0;
    int r = size(s) - 1;
    while (l < r) {
      swap(s[l++], s[r--]);
    }
  }
};
