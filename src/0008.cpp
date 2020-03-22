class Solution {
 public:
  int myAtoi(string s) {
    if (empty(s)) {
      return 0;
    }
    long res = 0;
    int cur = 0;
    bool postive = true;
    while (cur < size(s) && s[cur] == ' ') {
      ++cur;
    }
    if (cur >= size(s)) {
      return 0;
    }
    if (s[cur] == '+') {
      ++cur;
    } else if (s[cur] == '-') {
      postive = false;
      ++cur;
    }
    while (cur < size(s) && isdigit(s[cur])) {
      if (res > INT_MAX) {
        break;
      }
      res = res * 10 + (s[cur] - '0');
      ++cur;
    }
    if (!postive) {
      res = -res;
    }
    if (res >= INT_MAX) {
      return INT_MAX;
    }
    if (res <= INT_MIN) {
      return INT_MIN;
    }
    return res;
  }
};
