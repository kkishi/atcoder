#include <bits/stdc++.h>

#include "atcoder.h"

class DisjointSet {
 public:
  DisjointSet(int size) : parent_(size), size_(size, 1) {
    for (int i = 0; i < size; ++i) {
      parent_[i] = i;
    }
  }
  int Find(int x) const {
    int p = parent_[x];
    if (p != x) p = Find(p);
    return p;
  }
  void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return;
    if (size_[x] > size_[y]) std::swap(x, y);
    history_.emplace_back(x, parent_[x], y, size_[y]);
    parent_[x] = parent_[y];
    size_[y] += size_[x];
  }
  int Size(int x) const { return size_[Find(x)]; }
  bool Same(int x, int y) const { return Find(x) == Find(y); }
  void Rollback() {
    while (!history_.empty()) {
      auto [x, px, y, sy] = history_.back();
      history_.pop_back();
      parent_[x] = px;
      size_[y] = sy;
    }
  }
  void ClearHistory() { history_.clear(); }

 private:
  std::vector<int> parent_, size_;
  std::vector<tuple<int, int, int, int>> history_;
};

void Main() {
  ints(n, m, k);
  VV<int> g(n);
  rep(m) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  V<int> s(n);
  cin >> s;
  each(e, s)-- e;

  map<pair<int, int>, V<pair<int, int>>> gs;
  rep(i, n) each(j, g[i]) { gs[{s[i], s[j]}].eb(i, j); }

  DisjointSet ds(n);
  rep(i, n) each(j, g[i]) {
    if (s[i] == s[j]) {
      ds.Union(i, j);
    }
  }
  ds.ClearHistory();

  ints(q);
  map<pair<int, int>, V<tuple<int, int, int>>> qs;
  rep(i, q) {
    ints(a, b);
    --a, --b;
    int sa = s[a];
    int sb = s[b];
    if (sa > sb) {
      swap(a, b);
      swap(sa, sb);
    }
    qs[{sa, sb}].eb(a, b, i);
  }
  V<int> ans(q);
  each(k, v, qs) {
    auto [sa, sb] = k;
    auto& vec = gs[{sa, sb}];
    each(a, b, vec) ds.Union(a, b);
    for (auto [a, b, i] : v) {
      ans[i] = ds.Same(a, b);
    }
    ds.Rollback();
  }
  each(e, ans) wt(e);
}
