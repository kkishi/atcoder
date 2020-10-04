#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  V<int> a(n), b(n);
  const int N = n * 2;
  const int DEF = -1;
  const int IN = 0;
  const int OUT = 1;
  V<int> floor(N, DEF);
  V<int> idx(N, DEF);
  rep(i, n) {
    cin >> a[i] >> b[i];
    if (a[i] != -1) {
      --a[i];
      if (floor[a[i]] != DEF) return false;
      floor[a[i]] = IN;
      idx[a[i]] = i;
    }
    if (b[i] != -1) {
      --b[i];
      if (floor[b[i]] != DEF) return false;
      floor[b[i]] = OUT;
      idx[b[i]] = i;
    }
  }
  vector dp(n + 1, false);
  dp[0] = true;
  rep(i, n) if (dp[i]) {
    for (int j = 1; j <= n - i; ++j) {
      bool ok = true;
      rep(k, j) {
        int ii = i * 2 + k;
        int oi = i * 2 + j + k;
        int index = -1;
        {
          int f = floor[ii];
          if (f == OUT) ok = false;
          if (f == IN) {
            int x = idx[ii];
            assert(x != DEF);
            int O = b[x];
            if (O != -1 && O != oi) ok = false;
            index = x;
          }
        }
        {
          int f = floor[oi];
          if (f == IN) ok = false;
          if (f == OUT) {
            int x = idx[oi];
            assert(x != DEF);
            int I = a[x];
            if (I != -1 && I != ii) ok = false;
            if (index != -1 && x != index) ok = false;
          }
        }
      }
      if (ok) dp[i + j] = true;
    }
  }
  return dp[n];
}

void Main() { wt(Solve()); }
