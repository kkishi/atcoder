#include <bits/stdc++.h>

#include "atcoder.h"

struct S {
  int a, b;
};

void Main() {
  ints(n, h);
  V<S> v;
  rep(n) {
    ints(a, b);
    v.pb({a, b});
  }
  sort(all(v), [](auto& x, auto& y) {
    int l = x.b * y.a, r = y.b * x.a;
    if (l != r) return l < r;
    return x.b > y.b;
  });
  int ans = 0;
  each(s, v) {
    dbg(s.a, s.b);
    ans += h * s.a;
    h -= s.b;
    if (h <= 0) break;
  }
  wt(ans);
}
