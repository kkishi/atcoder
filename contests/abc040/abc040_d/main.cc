#include <bits/stdc++.h>

#include "disjointset.h"
#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  V<tuple<int, bool, int, int>> e;
  rep(m) {
    ints(a, b, y);
    e.emplace_back(y, false, a, b);
  }
  ints(q);
  rep(i, q) {
    ints(v, w);
    e.emplace_back(w, true, v, i);
  }
  sort(all(e), greater());
  DisjointSet ds(n);
  V<int> ans(q);
  for (auto [y, query, a, b] : e) {
    if (query) {
      ans[b] = ds.Size(a - 1);
    } else {
      ds.Union(a - 1, b - 1);
    }
  }
  rep(i, q) wt(ans[i]);
}
