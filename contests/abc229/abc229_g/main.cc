#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  strings(s);
  ints(k);
  V<int> v;
  rep(i, sz(s)) if (s[i] == 'Y') v.pb(i);
  int n = sz(v);
  V<int> w;
  rep(i, n) w.pb(n - 1 - v[n - 1 - i]);
  wt(BinarySearch<int>(0, n + 1, [&](int x) {
    auto f = [&](const V<int>& v, int L) {
      V<int> l(n, big);
      int s = 0;
      rep(i, n) {
        if (i > 0) s += (v[i] - 1 - v[i - 1]) * min(L, i);
        if (i >= L) l[i] = s;
        int j = i - L;
        if (j >= 0) s -= (v[i] - L) - v[j];
      }
      return l;
    };
    V<int> l = f(v, x / 2);
    V<int> r = f(w, (x - 1) / 2);
    int y = big;
    rep(i, n) chmin(y, l[i] + r[n - 1 - i]);
    return y <= k;
  }));
}
