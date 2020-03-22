class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> m;
    vector<int> indegree(numCourses);
    for (auto& x : prerequisites) {
      m[x[1]].emplace_back(x[0]);
      ++indegree[x[0]];
    }
    queue<int> q;
    for (int i = 0; i < size(indegree); ++i) {
      if (!indegree[i]) {
        q.emplace(i);
      }
    }
    int cnt = 0;
    while (!empty(q)) {
      int n = q.front();
      q.pop();
      ++cnt;
      for (auto& x : m[n]) {
        --indegree[x];
        if (!indegree[x]) {
          q.emplace(x);
        }
      }
    }
    return cnt == numCourses;
  }
};
