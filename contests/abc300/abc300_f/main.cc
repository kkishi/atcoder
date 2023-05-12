#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, k);
  strings(s);

  int x = count(all(s), 'x');

  auto f = [&](const string& s) {
    V<int> v(x);
    int cnt = 0;
    rep(i, n) if (s[i] == 'x') {
      v[cnt] = i;
      ++cnt;
    }
    return v;
  };

  V<int> l = f(s);
  V<int> r = f(string(s.rbegin(), s.rend()));

  auto g = [&](int rem_m, int rem_k) {
    int mid = rem_k / x;
    if (mid >= rem_m) {
      return rem_m * n;
    }
    return r[rem_k % x] + mid * n;
  };

  int ans = g(m, k);
  rep(i, min(x, k + 1)) chmax(ans, l[i] + g(m - 1, k - i));

  if (k < x) {
    s = 'x' + s + 'x';
    V<int> idx;
    rep(i, sz(s)) if (s[i] == 'x') idx.eb(i);
    rep(i, sz(idx)) {
      int j = i + k + 1;
      if (j < sz(idx)) {
        chmax(ans, idx[j] - idx[i] - 1);
      }
    }
  }
  wt(ans);
}
