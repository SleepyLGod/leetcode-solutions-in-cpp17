class Solution {
 public:
  string simplifyPath(string path) {
    string res;
    vector<string> t{split(path, '/')};
    for (auto& x : t) {
      res += '/';
      res += x;
    }
    return empty(res) ? "/" : res;
  }

  vector<string> split(const string& s, char delemiter) {
    vector<string> res;
    istringstream ss{s};
    string t;
    while (getline(ss, t, delemiter)) {
      if (empty(t) || t == "." || (t == ".." && empty(res))) {
        continue;
      } else if (t == ".." && !empty(res)) {
        res.pop_back();
      } else {
        res.emplace_back(t);
      }
    }
    return res;
  }
};
