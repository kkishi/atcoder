#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, k);
  V<int> p(n);
  iota(all(p), 0);
  mint ans = 0;
  do {
    V<int> idx(n);
    iota(all(idx), 0);
    int cnt = 0;
    while (true) {
      ++cnt;
      V<int> nidx(n);
      rep(i, n) nidx[p[i]] = idx[i];
      swap(idx, nidx);
      bool ok = true;
      rep(i, n) if (idx[i] != i) ok = false;
      if (ok) break;
    }
    ans += mint(cnt).Pow(k);
  } while (next_permutation(all(p)));
  wt(ans);
}
