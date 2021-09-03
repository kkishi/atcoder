#include <bits/stdc++.h>

#include "atcoder.h"
#include "z_algorithm.h"

void Main() {
  ints(n);
  strings(s, t);
  string rgb = "RGB";
  int ans = 0;
  each(e, rgb) {
    string u = t;
    each(f, u) if (f != e) f = 'R' + 'G' + 'B' - e - f;
    {
      string us = u + '$' + s;
      auto z = ZAlgorithm(us);
      rep(i, n) if (z[n * 2 - i] >= i + 1)++ ans;
    }
    {
      string su = s + '$' + u;
      auto z = ZAlgorithm(su);
      rep(i, n - 1) if (z[n * 2 - i] >= i + 1)++ ans;
    }
  }
  wt(ans);
}
