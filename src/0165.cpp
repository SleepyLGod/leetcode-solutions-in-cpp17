class Solution {
 public:
  int compareVersion(string version1, string version2) {
    vector<int> v1{split(version1, '.')};
    vector<int> v2{split(version2, '.')};
    int sz = max(size(v1), size(v2));
    for (int i = 0; i < sz; ++i) {
      int a = i < size(v1) ? v1[i] : 0;
      int b = i < size(v2) ? v2[i] : 0;
      if (a > b) {
        return 1;
      }
      if (a < b) {
        return -1;
      }
    }
    return 0;
  }

  vector<int> split(const string& s, char delemiter) {
    vector<int> res;
    istringstream ss{s};
    string t;
    while (getline(ss, t, delemiter)) {
      res.emplace_back(stoi(t));
    }
    return res;
  }
};
