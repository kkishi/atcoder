#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  using T = tuple<int, int, int>;
  V<T> v;
  rep(n) {
    ints(x, y, c);
    v.eb(x, y, c);
  }
  using P = pair<int, int>;              // Slope
  map<P, V<pair<T, T>>> m;               // Group line segments by slope
  auto normalize = [](int& p, int& q) {  // Normalize a rational number p/q
    int s = p * q / abs(p * q);
    p = abs(p);
    q = abs(q);
    if (p == 0) {
      q = 1;
    } else if (q == 0) {
      p = 1;
    } else {
      int g = gcd(p, q);
      p /= g;
      q /= g;
    }
    p *= s;
  };
  rep(i, n - 1) rep(j, i + 1, n) {
    auto [x, y, c] = v[i];
    auto [X, Y, C] = v[j];
    int dx = X - x;
    int dy = Y - y;
    normalize(dx, dy);
    m[{dx, dy}].eb(v[i], v[j]);
  }
  int ans = -1;
  each(k, v, m) {
    using C = pair<P, P>;           // Center
    map<C, vector<pair<T, T>>> M1;  // Group line segments by center
    each(e, v) {
      auto [i, j] = e;
      auto [x0, y0, c0] = i;
      auto [x1, y1, c1] = j;
      int cxp = x0 + x1;
      int cxq = 2;
      normalize(cxp, cxq);
      int cyp = y0 + y1;
      int cyq = 2;
      normalize(cyp, cyq);
      M1[{P{cxp, cxq}, P{cyp, cyq}}].eb(e);
    }
    using K = pair<P, P>;  // Parameters (a, b) for the vertical bisector
    map<K, int> M2;        // The maximum weight, grouped by vertical bisector.
    each(c, v, M1) {
      map<K, int> M3;
      each(e, v) {
        auto [i, j] = e;
        auto [x0, y0, c0] = i;
        auto [x1, y1, c1] = j;
        K key;
        if (y0 == y1) {
          key = K{{0, 0}, {x1 + x0, 1}};
        } else {
          int ap = -(x1 - x0);
          int aq = y1 - y0;
          normalize(ap, aq);
          auto sq = [](int x) { return x * x; };
          int bp = sq(y1) - sq(y0) + sq(x1) - sq(x0);
          int bq = y1 - y0;
          normalize(bp, bq);
          key = K{{ap, aq}, {bp, bq}};
        }
        int c = c0 + c1;
        if (M2.count(key)) {
          chmax(ans, M2[key] + c);
        }
        chmax(M3[key], c);
      }
      each(k, v, M3) chmax(M2[k], v);  // Reflect M3 to M2.
    }
  }
  wt(ans);
}
