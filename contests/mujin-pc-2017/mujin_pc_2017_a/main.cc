#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n);
  int cnt = 0;
  mint ans = 1;
  rep(n) {
    ints(x);
    ++cnt;
    if (cnt > (x + 1) / 2) {
      ans *= cnt;
      --cnt;
    }
  }
  wt(ans * mint::Fact(cnt));
}
