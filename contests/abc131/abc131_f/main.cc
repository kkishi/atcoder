#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjointset.h"

struct Point {
  int x, y;
};

void Main() {
  ints(n);
  vector<Point> ps(n);
  rep(i, n) cin >> ps[i].x >> ps[i].y;
  const int kMax = 100001;
  vector<set<int>> xs(kMax);
  for (const Point& p : ps) {
    xs[p.y].insert(p.x);
  }

  int ans = 0;
  {
    DisjointSet dsx(kMax);
    for (const set<int>& s : xs)
      for (int x : s) dsx.Union(x, *s.begin());
    vector<int> y_count(kMax);
    vector<set<int>> y_unique(kMax);
    set<int> roots;
    for (const Point& p : ps) {
      int root = dsx.Find(p.x);
      ++y_count[root];
      y_unique[root].insert(p.y);
      roots.insert(root);
    }
    for (int r : roots) {
      ans += int(dsx.Size(r)) * int(y_unique[r].size()) - y_count[r];
    }
  }
  wt(ans);
}
