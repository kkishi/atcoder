#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  strings(s);
  int p = 1;
  rep(10) p *= 3;
  vector dp(p, mint(0));
  dp[0] = 1;

  vector<pair<int, vector<int>>> nx;
  V<int> state(10);
  Fix([&](auto rec, int depth) {
    if (depth == 10) {
      int enc = 0;
      rep(i, 10) {
        enc *= 3;
        enc += state[i];
      }
      nx.eb(enc, state);
      return;
    }
    rep(i, 3) {
      state[depth] = i;
      rec(depth + 1);
    }
  })(0);

  rep(I, n) {
    vector ndp = dp;
    V<int> state(10);
    int i = s[I] - 'A';
    each(enc, state, nx) {
      if (state[i] == 2) continue;
      V<int> nstate = state;
      nstate[i] = 1;
      rep(j, 10) if (j != i && nstate[j] == 1) nstate[j] = 2;
      int nenc = 0;
      rep(i, 10) {
        nenc *= 3;
        nenc += nstate[i];
      }
      ndp[nenc] += dp[enc];
    }
    swap(ndp, dp);
  }
  wt(accumulate(all(dp), mint(0)) - 1);
}
