#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<int> r(n);  // Representative node
  rep(i, n) r[i] = i;
  V<int> p(n);  // Potential
  V<set<int>> st(n);
  rep(i, n) st[i].insert(i);
  V<int> ans;
  rep(i, q) {
    ints(a, b, d);
    --a, --b;
    if (r[a] == r[b]) {
      if (p[a] - p[b] != d) continue;
    } else {
      if (sz(st[r[a]]) > sz(st[r[b]])) {
        swap(a, b);
        d = -d;
      }
      // b becomes the root.
      int o = d + p[b] - p[a];
      each(e, st[r[a]]) {
        r[e] = r[b];
        p[e] += o;
        st[r[b]].insert(e);
      }
    }
    ans.eb(i+1);
  }
  wt(ans);
}
