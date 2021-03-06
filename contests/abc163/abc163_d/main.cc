#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(N, K);

  mint minimum = 0;
  mint maximum = 0;
  rep(i, K) {
    minimum += i;
    maximum += N - i;
  }

  mint ans = 0;
  for (int i = K; i <= N + 1; ++i) {
    ans += maximum - minimum + 1;
    minimum += i;
    maximum += N - i;
  }
  wt(ans);
}
