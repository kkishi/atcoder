#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);

  V<tuple<int, int, int, int>> es;
  V<set<int>> st(n);
  rep(i, m) {
    ints(a, b, c);
    --a, --b;
    es.eb(c, i, a, b);
    st[a].insert(i);
    st[b].insert(i);
  }
  sort(es);

  V<int> ri(m);
  rep(i, m) ri[get<1>(es[i])] = i;

  V<int> ans(m);
  DisjointSet ds(n);
  int sum = 0;
  for (auto [c, i, a, b] : es) {
    a = ds.Find(a);
    b = ds.Find(b);
    if (a == b) continue;
    ds.Union(a, b);
    sum += c;

    if (sz(st[a]) < sz(st[b])) swap(a, b);
    V<int> rm;
    each(e, st[b]) {
      st[a].insert(e);
      auto [C, _, A, B] = es[ri[e]];
      if (ds.Same(A, B)) {
        rm.eb(e);
        ans[e] = C - c;
      }
    }
    each(e, rm) st[a].erase(e);
    swap(st[ds.Find(a)], st[a]);
  }
  each(e, ans) wt(sum + e);
}
