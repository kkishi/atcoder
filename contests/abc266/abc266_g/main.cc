#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(r, g, b, k);
  r -= k;
  g -= k;
  mint ans = 1;                     // {R}
  ans *= mint::Comb(r + b, b);      // {R, B}
  ans *= mint::Comb(r + b + k, k);  // {R, B, RB}
  ans *= mint::Comb(b + k + g, g);  // {R, B, RB, G}
  wt(ans);
}
