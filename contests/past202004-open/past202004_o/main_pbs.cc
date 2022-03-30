#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);

  V<int> A, B, C;
  V<tuple<int, int, int, int>> es;
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    es.eb(c, a, b, i);
    A.eb(a);
    B.eb(b);
    C.eb(c);
  }
  sort(es);

  DisjointSet ds(n);
  int sum = 0;
  V<tuple<int, int, int>> ES;
  for (auto [c, a, b, i] : es) {
    if (ds.Same(a, b)) continue;
    ds.Union(a, b);
    sum += c;
    ES.eb(a, b, c);
  }

  // Parallel binary search
  V<int> ok(m, n - 1), ng(m, -1);
  while (true) {
    V<pair<int, int>> mid;
    rep(i, m) {
      if (abs(ok[i] - ng[i]) > 1) {
        mid.eb((ok[i] + ng[i]) / 2, i);
      }
    }
    if (mid.empty()) break;
    sort(mid);
    auto it = mid.begin();
    DisjointSet ds(n);
    rep(i, sz(ES)) {
      auto [a, b, _] = ES[i];
      ds.Union(a, b);
      for (; it != mid.end() && it->first == i; ++it) {
        int j = it->second;
        (ds.Same(A[j], B[j]) ? ok : ng)[j] = i;
      }
    }
  }
  rep(i, m) wt(sum - get<2>(ES[ok[i]]) + C[i]);
}
