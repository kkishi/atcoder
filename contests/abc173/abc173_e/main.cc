#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, k);
  V<int> p, z, m;
  rep(i, n) {
    ints(a);
    if (a == 0) {
      z.pb(0);
    } else if (a > 0) {
      p.pb(a);
    } else {
      m.pb(-a);
    }
  }
  bool can_make_positive = false;
  for (int mc = 0; mc <= min<int>(m.size(), k); ++mc) {
    if (p.size() >= (k - mc) && even(mc)) {
      can_make_positive = true;
    }
  }
  // answer has to be minus or zero
  if (!can_make_positive) {
    // if (k > p.size() && (k - p.size()) % 2 == 1) {
    // can be zero?
    if (!z.empty()) {
      dbg("can be zero");
      wt(0);
    } else {
      dbg("has to be minus");
      mint ans = 1;
      rep(i, p.size()) ans *= p[i];
      sort(m);
      rep(i, k - p.size()) ans *= m[i];
      wt(-ans);
    }
  } else {
    // answer has to be zero?
    if (!z.empty() && k > (p.size() + m.size())) {
      dbg("has to be zero");
      wt(0);
    } else {
      mint ans = 1;
      int pi = 0;
      int mi = 0;
      sort(p, greater{});
      sort(m, greater{});
      while (pi + mi < k) {
        int rk = k - (pi + mi);
        if (rk == 1) {
          assert(pi < p.size());
          ans *= p[pi];
          wt(ans);
          return;
        }
        if (pi + 1 >= p.size()) {
          assert(mi + 1 < m.size());
          ans *= m[mi] * m[mi + 1];
          mi += 2;
        } else if (mi + 1 >= m.size()) {
          assert(pi + 1 < p.size());
          ans *= p[pi] * p[pi + 1];
          pi += 2;
        } else {
          int px = p[pi] * p[pi + 1];
          int mx = m[mi] * m[mi + 1];
          if (px > mx) {  // ?
            ans *= p[pi] * p[pi + 1];
            pi += 2;
          } else {
            ans *= m[mi] * m[mi + 1];
            mi += 2;
          }
        }
      }
      wt(ans);
    }
  }
}
