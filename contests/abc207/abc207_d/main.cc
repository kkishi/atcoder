// O(N^3) solution by naively matching points (simpler implementation).
#include <bits/stdc++.h>

#include "atcoder.h"

using P = complex<double>;

bool Solve() {
  ints(n);
  if (n == 1) return true;
  V<P> s, t;
  rep(n) {
    rd(double, a, b);
    s.eb(a, b);
  }
  rep(n) {
    rd(double, c, d);
    t.eb(c, d);
  }
  auto center = [&](V<P> v) -> V<P> {
    P c;
    each(e, v) c += e;
    c /= sz(v);
    each(e, v) e -= c;
    return v;
  };
  // Move points such that the centroid is on (0, 0).
  s = center(s);
  t = center(t);
  const double eps = 1e-6;
  // Choose 2 (not centroid) points and try to match by rotating appropriately.
  rep(i, n) {
    P S = s[i];
    if (abs(S) < eps) continue;
    rep(j, n) {
      P T = t[j];
      if (abs(abs(S) - abs(T)) > eps) continue;
      P rot = T / S;
      bool ok = true;
      rep(k, n) {
        P A = s[k] * rot;
        bool found = false;
        // Naively look up if there's a matching point. This could be optimized
        // using argsort but the implementation has to be careful:
        // 1) Points might lie on the edge of [-pi, pi]. In such cases the args
        // need to be rounded, for example to -pi.
        // 2) The sort needs to consider not only args but also norms, because
        // there can be multiple points with the same arg.
        rep(l, n) {
          P B = t[l];
          if (abs(A - B) < eps) found = true;
        }
        if (!found) ok = false;
      }
      if (ok) return true;
    }
    // It's sufficient to try at most one point from s.
    break;
  }
  return false;
}

void Main() { wt(Solve()); }
