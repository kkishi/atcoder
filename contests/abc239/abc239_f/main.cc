#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  V<int> d(n);
  cin >> d;
  V<pair<int, int>> es;
  DisjointSet ds(n);
  V<int> D(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    if (ds.Same(a, b)) {
      wt(-1);
      return;
    }
    ds.Union(a, b);
    ++D[a];
    ++D[b];
  }
  rep(i, n) if (D[i] > d[i]) {
    wt(-1);
    return;
  }
  set<int> ST;
  VV<pair<int, int>> sts(n);
  rep(i, n) if (D[i] < d[i]) {
    int r = ds.Find(i);
    ST.insert(r);
    sts[r].eb(i, d[i] - D[i]);
  }
  rep(i, n) {
    int r = ds.Find(i);
    if (r != i) {
      d[r] += d[i];
      D[r] += D[i];
    }
  }
  set<pair<int, int>> st;
  each(e, ST) st.emplace(d[e] - D[e], e);
  rep(n - m - 1) {
    if (sz(st) < 2) {
      wt(-1);
      return;
    }
    auto it = st.begin();
    int a = it->second;
    st.erase(it);
    it = prev(st.end());
    int b = it->second;
    st.erase(it);

    int x = d[a] + d[b];
    int X = D[a] + D[b];
    ds.Union(a, b);
    int c = ds.Find(a);
    d[c] = x;
    D[c] = X + 2;
    {
      assert(!sts[a].empty());
      auto [A, AC] = sts[a].back();
      sts[a].pop_back();

      assert(!sts[b].empty());
      auto [B, BC] = sts[b].back();
      sts[b].pop_back();

      es.eb(A, B);
      --AC, --BC;
      if (AC > 0) sts[a].eb(A, AC);
      if (BC > 0) sts[b].eb(B, BC);
      if (sz(sts[a]) < sz(sts[b])) swap(sts[a], sts[b]);
      each(e, sts[b]) sts[a].eb(e);
      swap(sts[a], sts[c]);
    }
    if (D[c] < d[c]) {
      st.emplace(d[c] - D[c], c);
    }
  }
  if (!st.empty()) {
    wt(-1);
    return;
  }
  each(a, b, es) wt(a + 1, b + 1);
}
