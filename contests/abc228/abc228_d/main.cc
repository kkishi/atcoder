#include <bits/stdc++.h>

#include "atcoder.h"
#include "intervals.h"

void Main() {
  Intervals is;
  ints(q);
  const int n = 1 << 20;
  V<int> v(n, -1);
  rep(q) {
    ints(t, x);
    int h = x;
    h %= n;
    if (t == 1) {
      auto f = Fix([&](auto f, int p) {
        auto i = is.Find(p);
        if (!i) return p;
        p = i->right;
        if (p == n) p = f(0);
        return p;
      });
      h = f(h);
      is.Insert(h, h + 1);
      v[h] = x;
      dbg(h, x);
    } else {
      wt(v[h]);
    }
  }
}
