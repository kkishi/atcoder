#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(k);
  strings(s);

  mint ans = 0;
  for (int last = 0; last <= k; ++last) {
    ans += mint::Comb(k - last + s.size() - 1, s.size() - 1) *
           mint(25).Pow(k - last) * mint(26).Pow(last);
  }
  wt(ans);
}
