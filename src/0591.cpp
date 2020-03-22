class Solution {
 public:
  bool isValid(string code) {
    if (empty(code)) {
      return false;
    }
    if (code[0] != '<') {
      return false;
    }
    int l = 0;
    int r = 0;
    while (r < size(code) && code[r] != '>') {
      ++r;
    }
    string outter_tag_first = code.substr(l, r - l + 1);
    if (!valid(outter_tag_first)) {
      return false;
    }
    string outter_tag_second{outter_tag_first};
    outter_tag_second.insert(begin(outter_tag_second) + 1, '/');
    int search_end = size(code) - size(outter_tag_second);
    if (search_end < 0) {
      return false;
    }
    if (code.substr(search_end, size(outter_tag_second)) != outter_tag_second) {
      return false;
    }
    string cdata_prefix{"<![CDATA["};
    string cdata_suffix{"]]>"};
    stack<string> s;
    l = size(outter_tag_first);
    while (l < search_end) {
      while (code[l] != '<') {
        ++l;
      }
      if (code.substr(l, size(cdata_prefix)) == cdata_prefix) {
        int pos = code.find(cdata_suffix, l + size(cdata_prefix));
        if (pos == string::npos) {
          return false;
        }
        l = pos + size(cdata_suffix);
        continue;
      }
      if (l >= search_end) {
        break;
      }
      r = l;
      while (r < search_end && code[r] != '>') {
        ++r;
      }
      string tag = code.substr(l, r - l + 1);
      if (tag[1] == '/') {
        if (empty(s) || !compare(s.top(), tag)) {
          return false;
        }
        s.pop();
      } else {
        if (!valid(tag)) {
          return false;
        }
        s.emplace(tag);
      }
      l = r + 1;
    }
    return empty(s);
  }

 private:
  bool compare(const string& a, const string& b) {
    if (a[0] != '<' || b[0] != '<' || b[1] != '/') {
      return false;
    }
    for (int i = 1; i < size(a); ++i) {
      if (a[i] != b[i + 1]) {
        return false;
      }
    }
    return true;
  }

  bool valid(const string& tag) {
    int sz = size(tag);
    if (sz <= 2 || sz > 11) {
      return false;
    }
    if (tag[0] != '<' || tag[sz - 1] != '>') {
      return false;
    }
    for (int i = 1; i < sz - 1; ++i) {
      if (tag[i] < 'A' || tag[i] > 'Z') {
        return false;
      }
    }
    return true;
  }
};
