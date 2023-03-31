#include <bits/stdc++.h>

#include <atcoder/math>
#include <atcoder/modint>

#include "atcoder.h"
#include "discrete_log.h"

void Main() {
  ints(t);
  rep(t) {
    wt([]() -> int {
      ints(p, a, b, s, g);
      if (s == g) return 0;
      if (a == 0) return b == g ? 1 : -1;
      using mint = atcoder::modint;
      mint::set_mod(p);
      if (a == 1) {
        // b*i = g - s mod p
        if (b == 0) return -1;
        return (mint(g - s) / b).val();
      }
      // a^i * Q = P mod p
      mint P = g * (a - 1) + b;
      mint Q = s * (a - 1) + b;
      if (Q.val() == 0) return (P.val() == 0) ? 0 : -1;
      return DiscreteLog(a, (P / Q).val(), p);
    }());
  }
}
