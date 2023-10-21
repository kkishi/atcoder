#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set_2d.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  DisjointSet2D ds(h, w);
  rep(i, h) rep(j, w) {
    if (s[i][j] != '#') continue;
    rep(di, -1, 2) rep(dj, -1, 2) {
      int ni = i + di;
      int nj = j + dj;
      if (inside(ni, nj, h, w)) {
        if (s[ni][nj] != '#') continue;
        ds.Union(i, j, ni, nj);
      }
    }
  }
  set<int> st;
  rep(i, h) rep(j, w) if (s[i][j] == '#') st.insert(ds.Find(i, j));
  wt(sz(st));
}
