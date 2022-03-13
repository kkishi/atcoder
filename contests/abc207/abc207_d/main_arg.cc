// O(n^2) solution by using argsort to match points efficiently.
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
  auto canonicalize = [&](const V<P>& v) -> V<P> {
    P c;
    each(e, v) c += e;
    c /= sz(v);
    V<P> w;
    // Having centroid breaks the points comparison after the argsort, so skip.
    each(e, v) if (abs(e - c) > eps) w.eb(e - c);
    sort(w, [&](const P& a, const P& b) {
      double A = arg(a), B = arg(b);
      if (abs(A - B) > eps) return A < B;
      return abs(a) < abs(b);
    });
    return w;
  };
  s = canonicalize(s);
  t = canonicalize(t);
  n = sz(s);
  rep(offset, n) {
    P rot = t[0] / s[offset];
    if (abs(abs(rot) - 1.0) > eps) continue;
    bool ok = true;
    rep(i, n) {
      P A = s[(i + offset) % n] * rot;
      P B = t[i];
      if (abs(A - B) > eps) {
        ok = false;
        break;
      }
    }
    if (ok) return true;
  }
  return false;
}

void Main() { wt(Solve()); }
