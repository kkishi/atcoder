#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, k);
  map<pair<int, int>, mint> memo;
  wt(Fix([&](auto rec, int pos, int rem) -> mint {
    if (pos == n) return 1;
    if (rem == 0) return 0;
    pair<int, int> key = {pos, rem};
    if (memo.count(key)) return memo[key];
    mint sum = 0;
    rep(i, 1, m + 1) {
      int npos = pos + i;
      if (npos > n) npos = n - (npos - n);
      sum += rec(npos, rem - 1);
    }
    mint res = sum / m;
    memo[key] = res;
    return res;
  })(0, k));
}
