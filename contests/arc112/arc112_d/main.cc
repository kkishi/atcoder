#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  s[0][0] = s[0][w - 1] = s[h - 1][0] = s[h - 1][w - 1] = '#';
  DisjointSet ds(h + w);
  rep(r, h) rep(c, w) if (s[r][c] == '#') ds.Union(r, h + c);
  set<int> rs;
  rep(r, h) rs.insert(ds.Find(r));
  set<int> cs;
  rep(c, w) cs.insert(ds.Find(h + c));
  wt(min(sz(rs), sz(cs)) - 1);
}
