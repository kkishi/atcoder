// O(N^3) solution by enumerating pairs of points that correspond.
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
  const double eps = 1e-6;
  // Canonicalize the set of points by doing a transformation such that:
  // * v[i] moves to (0, 0)
  // * v[j] moves to (1, 0)
  auto canon = [&](const V<P>& v, int i, int j) -> V<P> {
    V<P> w;
    rep(k, n) if (k != i && k != j) w.eb((v[k] - v[i]) / (v[j] - v[i]));
    sort(w, [&](const P& a, const P& b) {
      auto arg_canon = [&](const P& p) {
        const double pi = acos(-1);
        double a = arg(p);
        // Round args around the boundary to -pi.
        return pi - a < eps ? -pi : a;
      };
      double A = arg_canon(a), B = arg_canon(b);
      if (abs(A - B) > eps) return A < B;
      return abs(a) < abs(b);
    });
    return w;
  };
  V<P> S = canon(s, 0, 1);
  rep(i, n) rep(j, n) if (abs(s[1] - s[0]) == abs(t[j] - t[i])) {
    // Check if points match, assuming s[0] and s[1] corresponds to t[i] and
    //  t[j], respectively.
    V<P> T = canon(t, i, j);
    bool ok = true;
    rep(i, sz(S)) if (abs(S[i] - T[i]) > eps) {
      ok = false;
      break;
    }
    if (ok) return true;
  }
  return false;
}

void Main() { wt(Solve()); }
