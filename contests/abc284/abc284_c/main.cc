#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  DisjointSet ds(n);
  rep(m) {
    ints(u, v);
    ds.Union(u - 1, v - 1);
  }
  set<int> st;
  rep(i, n) st.insert(ds.Find(i));
  wt(sz(st));
}
