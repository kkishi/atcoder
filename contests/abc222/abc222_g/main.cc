// NOTE: This solution doesn't AC yet.
#include <bits/stdc++.h>

#include "atcoder.h"
#include "divisors.h"
#include "pow.h"

int Solve(int k) {
  if (k == 1) return 1;
  if (even(k)) k /= 2;
  if (k % 2 == 0 || k % 5 == 0) return -1;
  if (k % 3 == 0) return -1;  // ?
  int K = k - 1;
  int ans = k - 1;
  each(d, Divisors(K)) {
    if (Pow(10, d, k) == 1) {
      chmin(ans, d);
      dbg(k, d);
    }
  }
  return ans;
}

void Main() {
  ints(t);
  rep(t) {
    ints(k);
    wt(Solve(k));
  }
}
