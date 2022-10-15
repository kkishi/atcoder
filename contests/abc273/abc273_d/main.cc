#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, r, c);
  --r, --c;
  ints(n);
  map<int, set<int>> C, R;
  rep(n) {
    ints(r, c);
    --r, --c;
    C[r].insert(c);
    R[c].insert(r);
  }
  ints(q);
  rep(q) {
    rd(char, d);
    ints(l);
    auto& cs = C[r];
    cs.insert(-1);
    cs.insert(w);
    auto& rs = R[c];
    rs.insert(-1);
    rs.insert(h);
    if (d == 'L') c = max(c - l, *prev(cs.lower_bound(c)) + 1);
    if (d == 'R') c = min(c + l, *cs.lower_bound(c) - 1);
    if (d == 'U') r = max(r - l, *prev(rs.lower_bound(r)) + 1);
    if (d == 'D') r = min(r + l, *rs.lower_bound(r) - 1);
    wt(r + 1, c + 1);
  }
}
