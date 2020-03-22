class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for (auto it = rbegin(digits); it != rend(digits); ++it) {
      if (!carry) {
        break;
      }
      *it += carry;
      carry = *it / 10;
      *it %= 10;
    }
    if (carry) {
      digits.emplace(begin(digits), carry);
    }
    return digits;
  }
};
