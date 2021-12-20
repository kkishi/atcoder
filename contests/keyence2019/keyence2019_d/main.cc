#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  wt([]() -> mint {
    ints(n, m);
    map<int, int> r, c;
    rep(i, n) {
      ints(a);
      if (r.count(a)) return 0;
      r[a] = i;
    }
    rep(i, m) {
      ints(b);
      if (c.count(b)) return 0;
      c[b] = i;
    }
    int rs = 0, cs = 0;
    mint ans = 1;
    rrep(x, 1, n * m + 1) {
      bool R = false;
      if (r.count(x)) {
        R = true;
        ++rs;
      }
      bool C = false;
      if (c.count(x)) {
        C = true;
        ++cs;
      }
      if (!R && !C) {
        ans *= rs * cs - (n * m - x);
        continue;
      }
      if (R && C) continue;
      if (R) {
        ans *= cs;
      } else {
        ans *= rs;
      }
    }
    return ans;
  }());
}
