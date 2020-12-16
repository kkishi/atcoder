#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, g, b);
  int ans = numeric_limits<int>::max() / 10;
  // Try all placements where marbles of each color are placed consecutively.
  rep(L, -300, 300) rep(R, -300, 300) if (R - L >= g) {
    // Red: [L-r, L)
    // Blue: [R, R + b)
    // Green: find the best interval [gl, gr) within [L, R)
    int gl = -(g / 2);
    int gr = gl + g;
    if (gl < L) {
      gr += L - gl;
      gl = L;
    } else if (gr > R) {
      gl -= gr - R;
      gr = R;
    }
    auto f = [](int l, int r, int c) {
      l -= c;
      r -= c;
      auto g = [](int a, int b) {
        // // a + (a+1) + ... + (b-1)
        int n = b - a;
        return a * n + n * (n - 1) / 2;
      };
      if (r <= 0) return g(-r + 1, -l + 1);
      if (l >= 0) return g(l, r);
      return g(0, -l + 1) + g(0, r);
    };
    chmin(ans, f(L - r, L, -100) + f(gl, gr, 0) + f(R, R + b, 100));
  }
  wt(ans);
}
